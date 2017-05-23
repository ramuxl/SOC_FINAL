/*
* Simple app to read/write into custom IP in PL via /dev/uoi0 interface
* To compile for arm: make ARCH=arm CROSS_COMPILE=arm-xilinx-linux-gnueabi-
* Author: Tsotnep, Kjans
* Modified: Chibueze Cyril Akaluka; Anthony Damian Ramos Leon;OluSiji Medaiyese
* Modifications according to lab tasks for SOC project
*/
  
//C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdint.h>
#include "ZedboardOLED.h"
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <string.h>
#include <termios.h>
#include <math.h>

#define TOP_FREQUENCY 18000
#define BOTTOM_FREQUENCY 20
#define VOL_LEVELS 14
#define TO_BOTTOM 0
#define TO_TOP 1
#define LP_INIT_VALUE 50
#define HP_INIT_VALUE 12000
#define FILTERNETID 0
#define FILTERLINEID 1
#define CHANGE_FACTOR 50

#define BINARY_STRING_MAX 1024
#define PI 3.1415926539
#define SAMPLE_FREQENCY  48000

//control keys
#define UP_KEY 1
#define DOWN_KEY 2
#define RIGHT_KEY 3
#define LEFT_KEY 4
#define KEY_1 5
#define KEY_2 6
#define KEY_3 7
#define ZERO_KEY 8
#define QUIT 9
 
 //LED FILES
 #define LED0 "/sys/class/gpio/gpio192/value"
 #define LED1 "/sys/class/gpio/gpio193/value"
 #define LED2 "/sys/class/gpio/gpio194/value"
 #define LED3 "/sys/class/gpio/gpio195/value"
 #define LED4 "/sys/class/gpio/gpio196/value"
 #define LED5 "/sys/class/gpio/gpio197/value"


#define REG_FIL_NET_0   *((unsigned *)(ptr3 + 0))
#define REG_FIL_NET_1   *((unsigned *)(ptr3 + 4))
#define REG_FIL_NET_2   *((unsigned *)(ptr3 + 8))
#define REG_FIL_NET_3   *((unsigned *)(ptr3 + 12)) 
#define REG_FIL_NET_4   *((unsigned *)(ptr3 + 16))
#define REG_FIL_NET_5   *((unsigned *)(ptr3 + 20))
#define REG_FIL_NET_6   *((unsigned *)(ptr3 + 24)) 
#define REG_FIL_NET_7   *((unsigned *)(ptr3 + 28))
#define REG_FIL_NET_8   *((unsigned *)(ptr3 + 32))
#define REG_FIL_NET_9   *((unsigned *)(ptr3 + 36)) 
#define REG_FIL_NET_10  *((unsigned *)(ptr3 + 40))
#define REG_FIL_NET_11  *((unsigned *)(ptr3 + 44))
#define REG_FIL_NET_12  *((unsigned *)(ptr3 + 48)) 
#define REG_FIL_NET_13  *((unsigned *)(ptr3 + 52))
#define REG_FIL_NET_14  *((unsigned *)(ptr3 + 56))
#define REG_FIL_NET_15  *((unsigned *)(ptr3 + 60)) 
#define REG_FIL_NET_16  *((unsigned *)(ptr3 + 64))


#define REG_FIL_NET_17  ((unsigned *)(ptr3 + 68))
#define REG_FIL_NET_18  ((unsigned *)(ptr3+ 72)) 
#define REG_FIL_NET_19  ((unsigned *)(ptr3 + 76))


#define REG_VOL_NET_0  ((unsigned *)(ptr4 + 0))
#define REG_VOL_NET_1  ((unsigned *)(ptr4 + 4)) 


#define REG_FIL_LINE_0   *((unsigned *)(ptr1 + 0))
#define REG_FIL_LINE_1   *((unsigned *)(ptr1 + 4))
#define REG_FIL_LINE_2   *((unsigned *)(ptr1 + 8))
#define REG_FIL_LINE_3   *((unsigned *)(ptr1 + 12)) 
#define REG_FIL_LINE_4   *((unsigned *)(ptr1 + 16))
#define REG_FIL_LINE_5   *((unsigned *)(ptr1 + 20))
#define REG_FIL_LINE_6   *((unsigned *)(ptr1 + 24)) 
#define REG_FIL_LINE_7   *((unsigned *)(ptr1 + 28))
#define REG_FIL_LINE_8   *((unsigned *)(ptr1 + 32))
#define REG_FIL_LINE_9   *((unsigned *)(ptr1 + 36)) 
#define REG_FIL_LINE_10  *((unsigned *)(ptr1 + 40))
#define REG_FIL_LINE_11  *((unsigned *)(ptr1 + 44))
#define REG_FIL_LINE_12  *((unsigned *)(ptr1 + 48)) 
#define REG_FIL_LINE_13  *((unsigned *)(ptr1 + 52))
#define REG_FIL_LINE_14  *((unsigned *)(ptr1 + 56))
#define REG_FIL_LINE_15  *((unsigned *)(ptr1 + 60)) 
#define REG_FIL_LINE_16  *((unsigned *)(ptr1 + 64))

#define REG_FIL_LINE_17  ((unsigned *)(ptr1 + 68))
#define REG_FIL_LINE_18  ((unsigned *)(ptr1+ 72)) 
#define REG_FIL_LINE_19  ((unsigned *)(ptr1 + 76))

#define REG_VOL_LINE_0  ((unsigned *)(ptr2 + 0))
#define REG_VOL_LINE_1  ((unsigned *)(ptr2 + 4)) 

#define REG_ECHO  *((unsigned *)(ptr6 + 0))


#define REG_OLED_0 *((unsigned *)(ptr1 + 0))

struct num_parts {//structure for separating floating point numbers
    int integer_part;
    double decimal_part;
};

typedef struct filters{//Filter coefficients structure
	int *lp_fc;
	unsigned *lp_b0;
	unsigned *lp_b1;
	unsigned *lp_b2;
	unsigned *lp_a1;
	unsigned *lp_a2;
	
	int *hp_fc;
	unsigned *hp_b0;
	unsigned *hp_b1;
	unsigned *hp_b2;
	unsigned *hp_a1;
	unsigned *hp_a2;
}filter_args;



typedef struct p_params{	//Passed to user thread and for use by other functions
	unsigned * VolumenRNet;
	unsigned * VolumenLNet;
	unsigned * Filter0Net;
	unsigned * Filter1Net;
	unsigned * Filter2Net;
	unsigned * VolumenRline;
	unsigned * VolumenLline;
	unsigned * Filter0line;
	unsigned * Filter1line;
	unsigned * Filter2line;
	unsigned * OLED;
	
	unsigned *echo_en_ptr;
	
	filter_args coeffs_filter1;
	filter_args coeffs_filter2;
} p_user_thread_arg;

//function prototyeps
void *CLIThread_Func(void *);
void *RdSwitchesFunc(void *);
void Set_Filter(p_user_thread_arg *, int);
void Set_Volume (unsigned *, unsigned *);
int getch(void);
int Get_Ctrl_Key(void);
unsigned BinaryToHex (char *binary_str);
void fader(p_user_thread_arg *, int , char, int);
struct num_parts *SplitParts(double);
void Fp2Str(char*, double);
char* FloatToBinary(double);
char *strdup(const char *);
void assign_coeffs(filter_args *, int, char);
unsigned BinaryToHex(char *);

//global varible to exit program


int main(int argc, char *argv[])
{	
	p_user_thread_arg prmtr;
	
	//open FILTER LINE IN  -> uio1
	int fd1 = open ("/dev/uio1", O_RDWR);
	if (fd1 < 1) { perror(argv[0]); return -1; }
	
	//open VOLUME LINE IN  -> uio2
	int fd2 = open ("/dev/uio2", O_RDWR);
	if (fd2 < 1) { perror(argv[0]); return -1; }
	
	//open dev/uio3 FILTER NETWORK
	int fd3 = open ("/dev/uio3", O_RDWR);
	if (fd3 < 1) { perror(argv[0]); return -1; }
	//open dev/uio4 VOLUME NETWORK
	int fd4 = open ("/dev/uio4", O_RDWR);
	if (fd4 < 1) { perror(argv[0]); return -1;}
 
	//OPEN /dev/ui05 OLED	
	int fd5 = open ("/dev/uio5", O_RDWR);
       if (fd5 < 1) { perror(argv[0]); return -1;}
       
       //OPEN /dev/ui05 OLED	
	int fd6 = open ("/dev/uio6", O_RDWR);
       if (fd6 < 1) { perror(argv[0]); return -1;}
	
	
		
	//Redirect stdout/printf into /dev/kmsg file (so it will be printed using printk)
	//freopen ("/dev/kmsg","w",stdout);
  
	//get architecture specific page size
	unsigned pageSize = sysconf(_SC_PAGESIZE);
  
	//Map virtual memory to physical memory     
               
	void *ptr1;
	ptr1 = mmap(NULL, pageSize, (PROT_READ |PROT_WRITE), MAP_SHARED, fd1, pageSize*0);
        
             
	void *ptr2;
	ptr2 = mmap(NULL, pageSize, (PROT_READ |PROT_WRITE), MAP_SHARED, fd2, pageSize*0);
        
         
	void *ptr3;
	ptr3 = mmap(NULL, pageSize, (PROT_READ |PROT_WRITE), MAP_SHARED, fd3, pageSize*0);
                
	void *ptr4;
	ptr4 = mmap(NULL, pageSize, (PROT_READ |PROT_WRITE), MAP_SHARED, fd4, pageSize*0);
        
	void *ptr5;
	ptr5 = mmap(NULL, pageSize, (PROT_READ |PROT_WRITE), MAP_SHARED, fd5, pageSize*0);
        
	void *ptr6;
	ptr6 = mmap(NULL, pageSize, (PROT_READ |PROT_WRITE), MAP_SHARED, fd6, pageSize*0);

	/*write something in OLED*/
	oled_clear(ptr5);
	char str[] = "Welcome SOC TTU";
	if (!oled_print_message(str, 0, ptr5)){
		perror("Error: Failed to write in the OLED\n");
		exit(-1);
	}
	char str2[] = "**AUDIO MIXER**";
	if (!oled_print_message(str2, 1, ptr5)){
		perror("Error: Failed to write in the OLED\n");
		exit(-1);
	}

        
     /* write initialization coeffients in both filters */
    REG_FIL_NET_0 = 0x00002CB6;
    REG_FIL_NET_1 = 0x0000596C;
    REG_FIL_NET_2 = 0x00002CB6;
    REG_FIL_NET_3 = 0x8097A63A;
    REG_FIL_NET_4 = 0x3F690C9D;
    REG_FIL_NET_5 = 0x074D9236;
    REG_FIL_NET_6 = 0x00000000;
    REG_FIL_NET_7 = 0xF8B26DCA;
    REG_FIL_NET_8 = 0x9464B81B;
    REG_FIL_NET_9 = 0x3164DB93;
    REG_FIL_NET_10 = 0x12BEC333;
    REG_FIL_NET_11 = 0xDA82799A;
    REG_FIL_NET_12 = 0x12BEC333;
    REG_FIL_NET_13 = 0x00000000;
    REG_FIL_NET_14 = 0x0AFB0CCC;
    
    REG_FIL_LINE_0 = 0x00002CB6;
    REG_FIL_LINE_1 = 0x0000596C;
    REG_FIL_LINE_2 = 0x00002CB6;
    REG_FIL_LINE_3 = 0x8097A63A;
    REG_FIL_LINE_4 = 0x3F690C9D;
    REG_FIL_LINE_5 = 0x074D9236;
    REG_FIL_LINE_6 = 0x00000000;
    REG_FIL_LINE_7 = 0xF8B26DCA;
    REG_FIL_LINE_8 = 0x9464B81B;
    REG_FIL_LINE_9 = 0x3164DB93;
    REG_FIL_LINE_10 = 0x12BEC333;
    REG_FIL_LINE_11 = 0xDA82799A;
    REG_FIL_LINE_12 = 0x12BEC333;
    REG_FIL_LINE_13 = 0x00000000;
    REG_FIL_LINE_14 = 0x0AFB0CCC;
        
    //set reset for NET filter device to zero
    REG_FIL_NET_15 = 0;
    //set REG16 for LINE to constant 1
    REG_FIL_NET_16 = 1;
 
    //set reset for LINE filter device to zero
    REG_FIL_LINE_15 = 0;
    //set REG16 for LINE to constant 1
    REG_FIL_LINE_16 = 1;
    
    //Initialize volume and filters for NET and LINE
    *REG_VOL_NET_0 = 256;
    *REG_VOL_NET_1 = 256;
 
	
    *REG_VOL_LINE_0 = 256;
    *REG_VOL_LINE_1 = 256;
    
    *REG_FIL_LINE_17 = 0;
    *REG_FIL_LINE_18 = 0;
    *REG_FIL_LINE_19 = 0;
        
	//Initialize echo as disabled
    REG_ECHO = 0;
    
	//Initilize CLI thread structure values
    
    prmtr.VolumenRNet = REG_VOL_NET_0;
	prmtr.VolumenLNet = REG_VOL_NET_1;
       
    prmtr.Filter0Net  = REG_FIL_NET_17;
    prmtr.Filter1Net  = REG_FIL_NET_18;
    prmtr.Filter2Net  = REG_FIL_NET_19;
    
    prmtr.VolumenRline = REG_VOL_LINE_0;
    prmtr.VolumenLline = REG_VOL_LINE_1;
    
    prmtr.Filter0line = REG_FIL_LINE_17;
    prmtr.Filter1line = REG_FIL_LINE_18;
    prmtr.Filter2line = REG_FIL_LINE_19;
    
    prmtr.coeffs_filter1.lp_fc = (int*)malloc(sizeof(int));
    prmtr.coeffs_filter1.hp_fc = (int*)malloc(sizeof(int));
    prmtr.coeffs_filter2.lp_fc = (int*)malloc(sizeof(int));
    prmtr.coeffs_filter2.hp_fc = (int*)malloc(sizeof(int));
       
    *(prmtr.coeffs_filter1.lp_fc) = LP_INIT_VALUE;
    *(prmtr.coeffs_filter1.hp_fc) = HP_INIT_VALUE;
    *(prmtr.coeffs_filter2.lp_fc) = LP_INIT_VALUE;
    *(prmtr.coeffs_filter2.hp_fc) = HP_INIT_VALUE;
   
    prmtr.coeffs_filter1.lp_b0 = &REG_FIL_NET_0;
    prmtr.coeffs_filter1.lp_b1 = &REG_FIL_NET_1;
    prmtr.coeffs_filter1.lp_b2 = &REG_FIL_NET_2;
    prmtr.coeffs_filter1.lp_a1 = &REG_FIL_NET_3;
    prmtr.coeffs_filter1.lp_a2 = &REG_FIL_NET_4;
    prmtr.coeffs_filter1.hp_b0 = &REG_FIL_NET_10;
    prmtr.coeffs_filter1.hp_b1 = &REG_FIL_NET_11;
    prmtr.coeffs_filter1.hp_b2 = &REG_FIL_NET_12;
    prmtr.coeffs_filter1.hp_a1 = &REG_FIL_NET_13;
    prmtr.coeffs_filter1.hp_a2 = &REG_FIL_NET_14;
   
    prmtr.coeffs_filter2.lp_b0 = &REG_FIL_LINE_0;
    prmtr.coeffs_filter2.lp_b1 = &REG_FIL_LINE_1;
    prmtr.coeffs_filter2.lp_b2 = &REG_FIL_LINE_2;
    prmtr.coeffs_filter2.lp_a1 = &REG_FIL_LINE_3;
    prmtr.coeffs_filter2.lp_a2 = &REG_FIL_LINE_4;
    prmtr.coeffs_filter2.hp_b0 = &REG_FIL_LINE_10;
    prmtr.coeffs_filter2.hp_b1 = &REG_FIL_LINE_11;
    prmtr.coeffs_filter2.hp_b2 = &REG_FIL_LINE_12;
    prmtr.coeffs_filter2.hp_a1 = &REG_FIL_LINE_13;
    prmtr.coeffs_filter2.hp_a2 = &REG_FIL_LINE_14;
        
    prmtr.echo_en_ptr = &REG_ECHO;
        
    //create threads
	pthread_t CLIThread;
	int rc;
       rc = pthread_create(&CLIThread, NULL, CLIThread_Func,(void *)&prmtr);
	if (rc){
	 perror("Error: Failed to create the CLIThread with retrun code\n");
	 exit(-1);
	}   
	
	//wait for CLIThread exit
	pthread_join(CLIThread,NULL);
	   
	//unmap
    munmap(ptr1, pageSize);
    munmap(ptr2, pageSize);
    munmap(ptr3, pageSize);
    munmap(ptr4, pageSize);
	munmap(ptr5, pageSize);
    munmap(ptr6, pageSize);
  
    //close
    fclose(stdout);
    pthread_exit(NULL);
    return 0;
}



void *CLIThread_Func(void * p_register){
	p_user_thread_arg * prmt;
	prmt = (p_user_thread_arg *) p_register;
	int Control, ch;
    while (true){
		printf("*****************************************\n");
		printf("*\t\tMAIN MENU\t\t*\n");
		printf("*****************************************\n");
		printf("/*Enter*/\n");
		printf("0. Exit program\n");
		printf("1. Control volume for network\n");
		printf("2. Control volume for Line in\n");
		printf("3. Control filter for network\n");
		printf("4. Control filter for Line in\n");
		printf("5. Enable or disable echo\n");
		printf("\nUser_Input/>");
		fflush(stdin);
		scanf(" %d",&Control);
		switch (Control){
			case 0:
				getchar();
				while (true){
					printf("Are you sure you want to exit? y or n: ");
					ch = getchar();
					if(getchar() != '\n'){
						printf("Invalid input!!\n");
						while(getchar() != '\n');
						continue;
					}
					else if( ch == 'n' || ch == 'N' || ch == 'y' || ch == 'Y')
						break;
					printf("Invalid input!!\n");
				}
				if(ch == 'n' || ch == 'N')
					break;
				pthread_exit(NULL);
				return;
			case 1:
				Set_Volume(prmt->VolumenRNet, prmt->VolumenLNet);
				break;
			case 2:
				Set_Volume(prmt->VolumenRline, prmt->VolumenLline);
				break;
			case 3:
				Set_Filter(prmt, FILTERNETID);
				break;
			case 4:
				Set_Filter(prmt, FILTERLINEID);
				break;
			case 5:
				*(prmt -> echo_en_ptr) = !(*(prmt -> echo_en_ptr));
				break;
			default: //Notify unsupported control
				printf("Unsupported control specified\n");
				break;
		}
    }
     pthread_exit(NULL);
}
void Set_Volume(unsigned *Vol_R, unsigned *Vol_L){
	
	int ch, i, r_vol, l_vol;
	unsigned vol_levels[VOL_LEVELS]  = {0, 16, 32, 64, 128, 256, 512, 1024, 1536, 2048, 2560, 3072, 3584, 4096};
	//Determine current volume level for right and left
	for (i = 0; i < VOL_LEVELS; i++){
		if (*Vol_R == vol_levels[i])
			r_vol = i;
		if(*Vol_L == vol_levels[i])
			l_vol = i;
	}
	//print usage
	printf("/*Use the arrow keys as follow*/ \n");
	printf("*UP KEY - R Volume increase\n");
	printf("*DOWN KEY - R Volume decrease\n");
	printf("*RIGHT KEY - L Volume increase\n");
	printf("*LEFT KEY - L Voulme decrease\n");
	printf("*0 mute both L & R\n");
	printf("Q to go back to main menu\n");
	getchar();
	while((ch = Get_Ctrl_Key()) != QUIT){
		switch (ch){
			case UP_KEY:
				if(r_vol != VOL_LEVELS -1)//if maximum volume is not reached.
					*Vol_R = vol_levels[++r_vol];	        
				break;
			case DOWN_KEY:
				if(r_vol != 0)//if minimum volume is not reached
					*Vol_R = vol_levels[--r_vol];
				break;
			case RIGHT_KEY:
				if(l_vol != VOL_LEVELS -1)//if maximum volume is not reached.
					*Vol_L = vol_levels [++l_vol];
				break;
			case LEFT_KEY:
				if (l_vol != 0)//if minimum volume is not reached
					*Vol_L = vol_levels[--l_vol];
				break;
			case ZERO_KEY:
				l_vol = 0;
				r_vol = 0;
				*Vol_L = vol_levels[l_vol];
				*Vol_R = vol_levels[r_vol];
				break;
			default:
				printf("Wrong key pressed!. Use Q to return to main menu.\n");
		}
	}
	return;
}

//Function to control the filters depending on specified filter_id
void Set_Filter (p_user_thread_arg * prmt, int filter_id){
	
	int ch;
	/*LED's*/
	FILE * fled0, * fled1, *fled2, *fled3, *fled4, *fled5;
	//print usage
	printf("/*Use the function keys as follow*/ \n");
	printf("1 to enable or disable high pass\n");
	printf("2 to enable or disable band pass\n");
	printf("3 to enable or disable low pass\n");
	printf("0 to display filter status\n");
	printf("*UP KEY - highpass fader increment\n");
	printf("*DOWN KEY - highpass fader decrement\n");
	printf("*RIGHT KEY - lowpass fader increment\n");
	printf("*LEFT KEY - lowpass fader decrement\n");
	printf("Q to go back to main menu\n");
	getchar();
	while ((ch = Get_Ctrl_Key()) != QUIT){
		switch(ch){
			case KEY_1:
				if (filter_id == FILTERNETID){
					if((fled0 = fopen(LED0, "w")) == NULL){perror(LED0);}
					*(prmt->Filter0Net) = !(*(prmt->Filter0Net));
					printf("Low pass %s\n", (*(prmt->Filter0Net) == 0)? "enabled" : "disabled");
					fprintf(fled0,"%d",*(prmt->Filter0Net));
					fclose(fled0);
				}
				else{
					if((fled3 = fopen(LED3, "w")) == NULL){perror(LED3);}
					*(prmt->Filter0line) = !(*(prmt->Filter0line));
					printf("Low pass %s\n", (*(prmt->Filter0line) == 0)? "enabled" : "disabled");
					fprintf(fled3,"%d",*(prmt->Filter0line));
					fclose(fled3);
				}
				break;
			case KEY_2:
				if (filter_id == FILTERNETID){
					if((fled1 = fopen(LED1, "w")) == NULL){perror(LED1);}
					*(prmt->Filter1Net) = !(*(prmt->Filter1Net));
					printf("Band pass %s\n", (*(prmt->Filter1Net) == 0)? "enabled" : "disabled");
					fprintf(fled1,"%d",*(prmt->Filter1Net));
					fclose(fled1);
				}
				else{
					if((fled4 = fopen(LED4, "w")) == NULL){perror(LED4);}
					*(prmt->Filter1line) = !(*(prmt->Filter1line));
					printf("Band pass %s\n", (*(prmt->Filter1line) == 0)? "enabled" : "disabled");
					fprintf(fled4,"%d",*(prmt->Filter1line));
					fclose(fled4);
				}
				break;
			case KEY_3:
				if (filter_id == FILTERNETID){
					if((fled2 = fopen(LED2, "w")) == NULL){perror(LED2);}
					*(prmt->Filter2Net) = !(*(prmt->Filter2Net));
					printf("High pass %s\n", (*(prmt->Filter2Net) == 0)? "enabled" : "disabled");
					fprintf(fled2,"%d",*(prmt->Filter2Net));
					fclose(fled2);
				}
				else{
					if((fled5 = fopen(LED5, "w")) == NULL){perror(LED5);}
					*(prmt->Filter2line) = !(*(prmt->Filter2line));
					printf("High pass %s\n", (*(prmt->Filter2line) == 0)? "enabled" : "disabled");
					fprintf(fled5,"%d",*(prmt->Filter2line));
					fclose(fled5);
				}
				break;
			case UP_KEY:
				if(*(prmt->Filter2Net) == 1 || *(prmt->Filter2line) == 1){
					printf("High pass fiter is disabled. Kindly enable to use this function!\n");
					break;
				}
				fader(prmt, filter_id, 'h', TO_TOP);
				break;
			case DOWN_KEY:
				if(*(prmt->Filter2Net) == 1 || *(prmt->Filter2line) == 1){
					printf("High pass fiter is disabled. Kindly enable to use this function!\n");
					break;
				}
				fader(prmt, filter_id, 'h', TO_BOTTOM);
				break;
			case RIGHT_KEY:
				if(*(prmt->Filter0Net) == 1 || *(prmt->Filter0line) == 1){
					printf("Low pass fiter is disabled. Kindly enable to use this function!\n");
					break;
				}
				fader(prmt, filter_id, 'l', TO_TOP);
				break;
			case LEFT_KEY:
				if(*(prmt->Filter0Net) == 1 || *(prmt->Filter0line) == 1){
					printf("Low pass fiter is disabled. Kindly enable to use this function!\n");
					break;
				}
				fader(prmt, filter_id, 'l', TO_BOTTOM);
				break;
			case ZERO_KEY:
				//printf("\n************Status*****************\n");
				if (filter_id == FILTERLINEID){
					printf("High pass filter is %s\n", (*(prmt->Filter2Net) == 0)? "enabled" : "disabled");
					printf("Band pass filter is %s\n", (*(prmt->Filter1Net) == 0)? "enabled" : "disabled");
					printf("Low pass filter is %s\n",  (*(prmt->Filter0Net) == 0)?  "enabled" : "disabled");
				}
				else{
					printf("High pass filter is %s\n", (*(prmt->Filter2line) == 0)? "enabled" : "disabled");
					printf("Band pass filter is %s\n", (*(prmt->Filter1line) == 0)? "enabled" : "disabled");
					printf("Low pass filter is %s\n",  (*(prmt->Filter0line) == 0)?  "enabled" : "disabled");
				}
				break;
			default:
				printf("Wrong key pressed. Use Q to return to main menu!\n");				
		}
	}
}
//Function to implement change filter parameters
void fader(p_user_thread_arg *prmt, int filter_id, char filter_type, int direction)
{
	int fc;//cutoff frequency
	filter_args *filter1_args = &(prmt->coeffs_filter1);
	filter_args *filter2_args = &(prmt->coeffs_filter2);
	
	switch(filter_id){
		case FILTERNETID:
			if(filter_type == 'h'){
				if(direction == TO_TOP)
					fc = *(filter1_args->hp_fc) + CHANGE_FACTOR;
				else
					fc = *(filter1_args->hp_fc) - CHANGE_FACTOR;
					
				if ((direction == TO_TOP && fc <= TOP_FREQUENCY) || (direction == TO_BOTTOM && fc >= BOTTOM_FREQUENCY)){
					assign_coeffs(filter1_args, fc, 'h');
					*(filter1_args->hp_fc) = fc;
				}	
			}
			else{
				if(direction == TO_TOP)
					fc = *(filter1_args->lp_fc) + CHANGE_FACTOR;
				else
					fc = *(filter1_args->lp_fc) - CHANGE_FACTOR;
					
				if ((direction == TO_TOP && fc <= TOP_FREQUENCY) || (direction == TO_BOTTOM && fc >= BOTTOM_FREQUENCY)){
					assign_coeffs(filter1_args, fc, 'l');
					*(filter1_args->lp_fc) = fc;
				}
			}
			break;
		case FILTERLINEID:
			if(filter_type == 'h'){
				if(direction == TO_TOP)
					fc = *(filter2_args->hp_fc) + CHANGE_FACTOR;
				else
					fc = *(filter2_args->hp_fc) - CHANGE_FACTOR;
					
				if ((direction == TO_TOP && fc <= TOP_FREQUENCY) || (direction == TO_BOTTOM && fc >= BOTTOM_FREQUENCY)){
					assign_coeffs(filter2_args, fc, 'h');
					*(filter2_args->hp_fc) = fc;
				}		
			}
			else{
				if(direction == TO_TOP)
					fc = *(filter2_args->lp_fc) + CHANGE_FACTOR;
				else
					fc = *(filter2_args->lp_fc) - CHANGE_FACTOR;
					
				if ((direction == TO_TOP && fc <= TOP_FREQUENCY) || (direction == TO_BOTTOM && fc >= BOTTOM_FREQUENCY)){
					assign_coeffs(filter2_args, fc, 'l');
					*(filter2_args->lp_fc) = fc;
				}
			}
			break;
	}
}
//Custom getch function
int getch(void)
{
	 int ch;
	 struct termios oldt;
	 struct termios newt;
	 tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
	 newt = oldt; /* copy old settings to new settings */
	 newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
	 tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
	 ch = getchar(); /* standard getchar call */
	 tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
	 return ch; /*return received char */
}
//Function to get required control keys
int Get_Ctrl_Key(void){

	int x, y, z;
	x = getch();
	
	if (x == 'q'|| x == 'Q')
		return QUIT;
	if (x == '0')
		return ZERO_KEY;
	if (x == '1')
		return KEY_1;
	if (x == '2')
		return KEY_2;
	if (x == '3')
		return KEY_3;
	
	if (x == 27){
		y = getch();
		z = getch();
	}
	
	if (x == 27 && (y == 91 || y == 79))
	{
		switch(z){
			case 65:
				return UP_KEY;
			case 66:
				return DOWN_KEY;
			case 67:
				return RIGHT_KEY;
			case 68:
				return LEFT_KEY;
		}
	}
	return -1;
}
//Function to convert Binary string to unsigned
unsigned BinaryToHex (char *binary_str){

    unsigned hex_num = 0;
    int b;
    char *p = binary_str;
    do {
        b = *p=='1'?1:0;
        hex_num = (hex_num<<1)|b;
        p++;
    } while (*p);
    return hex_num;
}
//Function to convert float or double numbers to binary string
char* FloatToBinary (double number){
    double new_value, decimal_part_temp;
    char * decimal_binary, *binary_equiv, *int_bin, *temp_str;
    struct num_parts *n;
    int i, t;
    decimal_part_temp = 0.0;
    decimal_binary = malloc(BINARY_STRING_MAX * sizeof(char));
    binary_equiv = malloc(BINARY_STRING_MAX * sizeof(char));
    int_bin = malloc((BINARY_STRING_MAX*sizeof(char)));
    
    if (number < 0){
        new_value = 2 + number;
        n = SplitParts(new_value);
        decimal_part_temp = pow(2, 30) * ((n -> decimal_part));
        decimal_part_temp = round(decimal_part_temp);
        Fp2Str(decimal_binary, decimal_part_temp);
        t = 30 - strlen(decimal_binary);
        temp_str = strdup(decimal_binary);
        decimal_binary[0] = '\0';
        if(strlen(decimal_binary) < 30){
            for(i = 0; i < t; i++)
                strcat(decimal_binary, "0");
        }
        strcat(decimal_binary, temp_str);

        if((n -> integer_part) == 1)
            strcat(binary_equiv, "11");
        else
            strcat(binary_equiv, "10");
		
		strcat(binary_equiv, decimal_binary);
    }
    else{
        n = SplitParts(number);
        decimal_part_temp = pow(2, 30) * (n -> decimal_part);
        decimal_part_temp = round(decimal_part_temp);
        Fp2Str(decimal_binary, decimal_part_temp);
        t = 30 - strlen(decimal_binary);
        temp_str = strdup(decimal_binary);
        decimal_binary[0] = '\0';
        if(strlen(decimal_binary) < 30){
            for(i = 0; i < t; i++)
                strcat(decimal_binary, "0");
        }
        strcat(decimal_binary, temp_str);
        Fp2Str(int_bin, n -> integer_part);
        strcat(binary_equiv, int_bin);
        strcat(binary_equiv, "0");
        strcat(binary_equiv, decimal_binary);
    }
    free(temp_str);
    free(decimal_binary);
    free(int_bin);
    free(n);
    return binary_equiv;
}
//Splits a double number into respective integer and decimal parts
struct num_parts * SplitParts(double number){
    struct num_parts* n = malloc(sizeof(struct num_parts));
    n -> integer_part = (int)(trunc(number));
    n -> decimal_part = fabs(number - (n-> integer_part));
    return n;
}
//Function to convert floating point number to a binary string
void Fp2Str(char *binary_str, double float_num){
    char binary_str_temp[BINARY_STRING_MAX];
    int bit_count, i;
    bit_count = 0;
    do{
        binary_str_temp[bit_count++] = '0' + (int)fmod(float_num, 2);
        float_num = floor(float_num/2);
    }while(float_num > 0);
    bit_count--;
    /*Reverse the bits of binary_str_temp*/
    for(i = 0; bit_count >= 0; i++){
        binary_str[i] = binary_str_temp[bit_count--];
    }
    binary_str[i] = '\0';
}
//Function to allocate memory and store value of a string variable
char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL) strcpy (d,s);         // Copy string if okay
    return d;                            // Return new memory
}
//Function to calculate and assign filter coefficient
void assign_coeffs(filter_args * prmt, int fc, char filter_type){
    double K, Q, norm;
	double cutoff_freq = (double)(fc);
    Q = 1/sqrt(2);
    K = tan((double)PI * (cutoff_freq/SAMPLE_FREQENCY));
    norm = 1/(1 + (K/Q) + pow(K, 2));
    
    switch(filter_type){
        case 'l':
			*(prmt->lp_a1) = BinaryToHex(FloatToBinary(2 * (pow(K,2) - 1) * norm));
            *(prmt->lp_a2) = BinaryToHex(FloatToBinary((1-(K/Q) + pow(K,2)) * norm));
            *(prmt->lp_b0) = BinaryToHex(FloatToBinary(pow(K,2) * norm));
            *(prmt->lp_b1) = BinaryToHex(FloatToBinary(2 * pow(K,2) * norm));
            *(prmt->lp_b2) = *(prmt ->lp_b0);
            break;
        case 'h':
			*(prmt->hp_a1) = BinaryToHex(FloatToBinary(2 * (pow(K,2) -1) * norm));
            *(prmt->hp_a2) = BinaryToHex(FloatToBinary(((1 - (K/Q) + pow(K,2)) * norm)));
            *(prmt->hp_b0) = BinaryToHex(FloatToBinary(1 * norm));
            *(prmt->hp_b1) = BinaryToHex(FloatToBinary(-2 * norm));
            *(prmt->hp_b2) = *(prmt->hp_b0);
            break;
        default:
            printf("Wrong filter specified\n");
            break;
    }
}
