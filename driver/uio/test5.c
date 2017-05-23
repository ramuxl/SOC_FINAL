#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BINARY_STRING_MAX 1024
#define PI 3.1415926539
#define fs  48000
typedef struct filter_parameters{
    unsigned b0;
    unsigned b1;
    unsigned b2;
    unsigned a1;
    unsigned a2;

    char filter_type;
}filter_args;

struct num_parts {
        int integer_part;
        double decimal_part;
};
struct num_parts *SplitParts(double);
void Fp2Str(char*, double);
char* FloatToBinary(double);
char *strdup(const char *);
void assign_coeffs(filter_args *, int, char);
unsigned BinaryToHex(char *);
int main (void){

    filter_args * filter;
    filter = malloc(sizeof(filter_args));
    assign_coeffs(filter, 12000, 'h');
    printf("Coeffs are:- \na0: %0x\na1:%0x\na2:%0x\nb1:%0x\nb2:%0x\n", filter->a0, filter->a1, filter->a2, filter->b1, filter->b2);

    return 0;
}
char* FloatToBinary (double number){
    double new_value, decimal_part_temp;
    char * decimal_binary, *binary_equiv, *int_bin, *temp_str;
    struct num_parts *n;
    int i, t;
    decimal_part_temp = 0.0;
    decimal_binary = malloc(BINARY_STRING_MAX * sizeof(char));
    binary_equiv = malloc(BINARY_STRING_MAX * sizeof(char));
    int_bin = malloc((BINARY_STRING_MAX*sizeof(char)));
    //coeff[0] = malloc(3 * sizeof(char));
   // coeff[1] = malloc(31* sizeof(char));
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

        if((n -> integer_part) == 1){
            strcat(binary_equiv, "11");
            strcat(binary_equiv, decimal_binary);
        }
        else{
            strcat(binary_equiv, "10");
            strcat(binary_equiv, decimal_binary);
        }
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
struct num_parts * SplitParts(double number){
    struct num_parts* n = malloc(sizeof(struct num_parts));
    n -> integer_part = (int)(trunc(number));
    n -> decimal_part = fabs(number - (n-> integer_part));
    return n;
}
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
char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL) strcpy (d,s);         // Copy string if okay
    return d;                            // Return new memory
}
void assign_coeffs(filter_args * prmt, int fc, char filter_type){
    double K, Q, norm;

    Q = 1/sqrt(2);
    K = tan(PI * fc/fs);
    norm = 1/(1 + (K/Q) + pow(K, 2));
    switch(filter_type){
        case 'l':
            prmt->b0 = BinaryToHex(FloatToBinary(pow(K,2) * norm));
            prmt->b1 = BinaryToHex(FloatToBinary(2 * pow(K,2) * norm));
            prmt->b2 = prmt ->b0;
            prmt->a1 = BinaryToHex(FloatToBinary(2 * (pow(K,2) - 1) * norm));
            prmt->a2 = BinaryToHex(FloatToBinary((1-(K/Q) + pow(K,2)) * norm));
            break;
        case 'h':
            prmt->b0 = BinaryToHex(FloatToBinary(1 * norm));
            prmt->b1 = BinaryToHex(FloatToBinary(-2 * norm));
            prmt->b2 = prmt->b0;
            prmt->a1 = BinaryToHex(FloatToBinary( 2 * (pow(K,2) -1) * norm));
            prmt->a2 = BinaryToHex(FloatToBinary(((1 - (K/Q) + pow(K,2)) * norm)));
            break;
        default:
            printf("Wrong filter specified\n");
            break;
    }

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
