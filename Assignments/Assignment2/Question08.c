#include <stdio.h>
#include <math.h>
#include <string.h>

int BinaryToDecimal(int num) {
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

    return decimal;
}

int DecimalToBinary(int num) {
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
    
    long number=0;
    long multiplier=1;
    int i;
    int count1 = count;
    int counter=1;
    for(i=index-1;i>=index-count1;i--){
        if(binary[i] == '1'){
            number = number + 1*multiplier;
        }
        multiplier = multiplier*10;
        
    }
    return number;

}

void HexadecimalToBinary(char arr[]){
    int size = strlen(arr);
    char decimal[1000000];
    int num,i;
    char str[100];
    for(i=0;i<size;i++){
        if(arr[i]=='A' || arr[i]=='a'){
            num = 10;
            sprintf(str,"%d",DecimalToBinary(num));
            strcat(decimal,str);
        }else if(arr[i]=='B' || arr[i]=='b'){
            num = 11;
            sprintf(str,"%d",DecimalToBinary(num));
            strcat(decimal,str);
        }else if(arr[i]=='C' || arr[i]=='c'){
            num = 12;
            sprintf(str,"%d",DecimalToBinary(num));
            strcat(decimal,str);
        }else if(arr[i]=='D' || arr[i]=='d'){
            num = 13;
            sprintf(str,"%d",DecimalToBinary(num));
            strcat(decimal,str);
        }else if(arr[i]=='E' || arr[i]=='e'){
            num = 14;
            sprintf(str,"%d",DecimalToBinary(num));
            strcat(decimal,str);
        }else if(arr[i]=='F' || arr[i]=='f'){
            num = 15;
            sprintf(str,"%d",DecimalToBinary(num));
            strcat(decimal,str);
        }else{
            num = (int)arr[i]-(int)'0';
            sprintf(str,"%d",DecimalToBinary(num));
            strcat(decimal,str);
        }
    }
    printf("%s",decimal);
} 

int main() {
    char arr[]= {"156"};
    HexadecimalToBinary(arr);
    return 0;
}
