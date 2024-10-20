#include <stdio.h>
#include <math.h>
#include <string.h>

long BinaryToDecimal(long num) {
    long decimal = 0;  
    long i = 0; 
    long data;

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

long DecimalToBinary(long num) {
    char binary[1000000] = {'\0'}; 
    long power = num;  
    long index = 0; 
    long count = 0;
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
    long i;
    long count1 = count;
    long counter=1;
    for(i=index-1;i>=index-count1;i--){
        if(binary[i] == '1'){
            number = number + 1*multiplier;
        }
        multiplier = multiplier*10;
        
    }
    return number;

}

long HexadecimalToBinary(char arr[]){
    long size = strlen(arr);
    char binary[1000000]={'\0'};
    long num,i;
    char str[5];
    for(i=0;i<size;i++){
        if(arr[i]=='A' || arr[i]=='a'){
            num = 10;
            sprintf(str,"%04ld",DecimalToBinary(num));
            strcat(binary,str);
        }else if(arr[i]=='B' || arr[i]=='b'){
            num = 11;
            sprintf(str,"%04ld",DecimalToBinary(num));
            strcat(binary,str);
        }else if(arr[i]=='C' || arr[i]=='c'){
            num = 12;
            sprintf(str,"%04ld",DecimalToBinary(num));
            strcat(binary,str);
        }else if(arr[i]=='D' || arr[i]=='d'){
            num = 13;
            sprintf(str,"%04ld",DecimalToBinary(num));
            strcat(binary,str);
        }else if(arr[i]=='E' || arr[i]=='e'){
            num = 14;
            sprintf(str,"%04ld",DecimalToBinary(num));
            strcat(binary,str);
        }else if(arr[i]=='F' || arr[i]=='f'){
            num = 15;
            sprintf(str,"%04ld",DecimalToBinary(num));
            strcat(binary,str);
        }else{
            num = (int)arr[i]-(int)'0';
            sprintf(str,"%04ld",DecimalToBinary(num));
            strcat(binary,str);
        }
    }
    long number=0;
    for(i = 0; i < strlen(binary); i++) {
        number = number * 10 + (binary[i] - '0');
    }
    
    return number;
    
}

long HexadecimalToDecimal(char arr[]){
    
    long binary = HexadecimalToBinary(arr);
    long decimal = BinaryToDecimal(binary);
    return decimal;

}

void BinaryToHexadecimal(long num){
    long size=0;
    long n = num;
    long data;
    while(n>0){
        n = n/10;
        size++;
    }
    
    long index = 1;
    long data;
    n = num;
    int i;
    int ans;
    while(){
        data = n/10000;
        for(i=1;i<=4;i++){
            if(data%10==1){
                
            }    
        }
    }
    
}

int main() {
    BinaryToHexadecimal(10101010);
    return 0;
}
