#include <stdio.h>
#include <stdlib.h>

unsigned BinaryToHex(char *);


int main (void){

    char *lowpass[40][5];
    char *highpass[26][5];
    int LP_Frequencies[40];
    int HP_Frequencies[26];
    char* filtername = malloc(sizeof(char));
    int i, j;
    for (i = 0; i < 40; i++){
        for(j = 0; j < 5; j++){
            lowpass[i][j] = malloc(33* sizeof(char));
        }
    }
    FILE * fptr;
    fptr = fopen("coefficientstable.txt", "r");
    if(fptr == NULL){
        printf("Error opening file\n");
        exit(-1);
    }
    fscanf(fptr, "%s",filtername);
    printf("%s\n", filtername);
    for (i = 0; i < 40; i++){
        fscanf(fptr, "%d\t", &LP_Frequencies[i]);
        for (j = 0; j < 5; j++){
            fscanf(fptr, "%s\t", lowpass[i][j]);
        }
    }
    unsigned hex_num = BinaryToHex(lowpass[38][0]);
    printf("%d\n", LP_Frequencies[38]);
    printf("%s\n", lowpass[38][0]);
    printf("%0x\n", hex_num);
    close(fptr);
    return 0;
}
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
