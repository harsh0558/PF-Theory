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
    

    n = num;
    int i;
    int ans=0;
    char hex[1000000] = {'\0'};
    int index = 1000000-2;
    while(n>0){
        data = n%10000;
        n = n/10000;
        ans =0;
        for(i=0;i<4;i++){
            if(data%10==1){
                ans = ans+pow(2,i);
            }  
            data = data /10;
        }
        if(ans==10){
            hex[index] = 'A';
        }else if (ans==11){
            hex[index] = 'B';
        }else if(ans==12){
            hex[index] = 'C';
        }else if(ans==13){
            hex[index] = 'D';
        }else if(ans==14){
            hex[index] = 'E';
        }else if (ans==15){
            hex[index] = 'F';
        }else{
            hex[index] = (char)(ans+'0');
        }
        index--;
    }
    for(i=index+1;i<1000000-1;i++){
        if(hex[i] != '\0'){
            printf("%c",hex[i]);
        }        
    }
}

void DecimalToHexadecimal(long num){
    return BinaryToHexadecimal((DecimalToBinary(num)));
}
    
    


int main() {
    long input;
    printf("\tCHOOSE THE CONVERSION YOU WANT TO DO\n");
    printf("1) BINARY TO DECIMAL\n");
    printf("2) DECIMAL TO BINARY\n");
    printf("3) BINARY TO HEXADECIMAL\n");
    printf("4) DECIMAL TO HEXADECIMAL\n");
    printf("5) HEXADECIMAL TO BINARY\n");
    printf("6) HEXADECIMAL TO DECIMAL\n");
    printf("Enter your choice: ");
    scanf("%ld", &input);

    if (input == 1) {
        long ans;
        printf("Enter the Binary value: ");
        scanf("%ld", &ans);
        printf("The Decimal equivalent of %ld is: %ld\n", ans, BinaryToDecimal(ans));
    } else if (input == 2) {
        long ans;
        printf("Enter the Decimal value: ");
        scanf("%ld", &ans);
        printf("The Binary equivalent of %ld is: %ld\n", ans, DecimalToBinary(ans));
    } else if (input == 3) {
        long ans;
        printf("Enter the Binary value: ");
        scanf("%ld", &ans);
        printf("The Hexadecimal equivalent of %ld is: ", ans);
        BinaryToHexadecimal(ans);
        printf("\n");
    } else if (input == 4) {
        long ans;
        printf("Enter the Decimal value: ");
        scanf("%ld", &ans);
        printf("The Hexadecimal equivalent of %ld is: ", ans);
        DecimalToHexadecimal(ans);
        printf("\n");
    } else if (input == 5) {
        char ans[100]; 
        printf("Enter the Hexadecimal value: ");
        scanf("%s", ans);
        printf("The Binary equivalent of %s is: %ld\n", ans, HexadecimalToBinary(ans));
    } else if (input == 6) { 
        char ans[100];
        printf("Enter the Hexadecimal value: ");
        scanf("%s", ans);
        printf("The Decimal equivalent of %s is: %ld\n", ans, HexadecimalToDecimal(ans));
    } else {
        printf("Invalid choice! Please enter a number between 1 and 6.\n");
    }

    return 0;
}
