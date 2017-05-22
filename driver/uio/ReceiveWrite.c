#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include "udpclient.h"

#define BYTES_TO_RECEIVE 256
#define BYTES_TO_READ 4
#define TEMP_FIFO "/temp.fifo"
#define BROADCAST_ADDRESS "10.255.255.255"
#define BROADCAST_PORT 7891
#define BUFFER_SIZE 256

#define REG_AXI_0   ((unsigned *)(ptr0 + 0))



//function prototyeps
void *ReceiveAudio(void *);


int main(int argc, char *argv[])
{
        //open dev/uio0 AXI BUS
        int fd0 = open ("/dev/uio0", O_RDWR);
        if (fd0 < 1) { perror(argv[0]); return -1; }
        
        //get architecture specific page size
        unsigned pageSize = sysconf(_SC_PAGESIZE);
        
        //Map virtual memory to physical memory         
        void *ptr0;
        ptr0 = mmap(NULL, pageSize, (PROT_READ |PROT_WRITE), MAP_SHARED, fd0, pageSize*0);
        
        //setup socket
        if (udp_client_setup (BROADCAST_ADDRESS, BROADCAST_PORT) == 1){
			perror("Error with UDP setup");
			exit(-1);
		}
          
        //Create FIFO
        const char * my_fifo;
		my_fifo = strcat (getenv("HOME"), TEMP_FIFO);
		if (access(my_fifo, F_OK) != -1){
			remove(my_fifo);
		}
        if(mkfifo(my_fifo, S_IRUSR| S_IWUSR) != 0){
			 perror("mkfifo() error\n");
			 exit (-1);
		}
		
		
		//create threads
		 pthread_t ReceiveThread;
		 int rc;
		 rc = pthread_create(&ReceiveThread, NULL, ReceiveAudio,(void *)my_fifo);
		 if (rc){
			 perror("Error: Failed to create the ReceiveThread with retrun code\n");
			 exit(-1);
		 }
		 int rfd;
		 rfd = open(my_fifo, O_RDONLY);
		 while(true){
			if((read(rfd, REG_AXI_0, BYTES_TO_READ)) == -1){//Write 4  bytes to REG_AXI_0
				perror("read() error");
				close(rfd);
			}
		 }
		 
		 
		 pthread_join(ReceiveThread, NULL);
		 //unmap
        munmap(ptr0, pageSize);
        fclose(stdout);
        unlink(my_fifo);
        pthread_exit(NULL);
        return 0;
}
void *ReceiveAudio (void *tempfifo)
{
	const char *fifo;
	fifo = (char *) tempfifo;
	int wfd;
	unsigned buffer[BUFFER_SIZE];
	wfd = open (fifo, O_WRONLY);
	if (wfd < 0){
			perror("open() error for write end");
			return;
	}
	while (true){
		
		if (udp_client_recv (buffer, BYTES_TO_RECEIVE) == 1){;//receive 256 bytes from UDP to buffer
			perror("Error receiving from UDP");
			close(wfd);
			return;
		}
		if ((write (wfd, buffer, BYTES_TO_RECEIVE) )== -1){ //Write 256 bytes from buffer to FIFO
			perror("write () error");
			close(wfd);
			return;
		}
		
	}
	close(wfd);
	pthread_exit(NULL);
	return;
}
