#include <stdio.h>
#include <string.h>

int main() {
    char arr[100];
    char newarr[100];
    int i=0,count=0;
    
    printf("enter a word: ");
    fgets(arr,100,stdin);
    
    while(arr[i]!='\0'){
        if(arr[i]!=arr[i+1]){
            printf("%c",arr[i]);
        }else{
            count++;
        }
        i++;
    }
    printf("\n");
    printf("%d",count);
    
    return 0;
}
