#include <stdio.h>
#include <math.h>
#include <string.h>

void BinaryToDecimal(int num) {
    int decimal = 0;  
    int i = 0; 
    int data;

    while (num > 0) {
        data = num % 10;
        num = num / 10; 
        if (data == 1) {
            decimal = decimal + pow(2, i);
        }
        i++;
    }
    printf("The decimal equivalent is: %d\n", decimal);
}

void DecimalToBinary(int num) {
    char binary[1000000] = {'\0'}; 
    int power = num;  
    int index = 0; 
    int count = 0;
    while (power >= 0) {
        if (pow(2, power) <= num) {
            num = num - pow(2, power);  
            binary[index++] = '1';  
            count++;
        } else {
            binary[index++] = '0'; 
            if(count!=0){
                count++;
            }
        }
        power--; 
    }
    printf("The binary equivalent is: ");
    while(count>=0){
        printf("%c",binary[index-count]);
        count--;
    }
}

void HexadecimalToDecimal(char arr[]){
    int size = strlen(arr);
    char decimal[1000000];
    int num,i;
    for(i=0;i<size;i++){
        if(arr[i]=='A' || arr[i]=='a'){
            num = 10;
        }
    }
    
    
} 

int main() {

    return 0;
}
