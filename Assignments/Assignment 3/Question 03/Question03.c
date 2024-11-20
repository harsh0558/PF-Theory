#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validateEmail(char *mail,int length){
    int i,symbol=-1,dot=-1,empty=-1,index;
    if(length !=0){
        empty = 1;
        for(i=0;i<length;i++){
            if(mail[i]=='@'){
                symbol = 1;
                index=i;
                break;
            }
        }
        for(i=0;i<length;i++){
            if(mail[i]=='.' && i>index){
                dot = 1;
                break;
            }
        }
    }
    if(symbol==1 && dot==1 && empty == 1){
        return 1;
    }else{
        return 0;
    }
}


int main() {
    char temp[100];
    
    printf("Enter email address: ");
    scanf("%s",temp);
    int length = strlen(temp);
    char *email = (char*)malloc(length*sizeof(char));
    strcpy(email, temp);
    if(validateEmail(email,length)){
        printf("Valid Email");
    }else{
        printf("Invalid Email");
    }
    free(email);
    return 0;
}
