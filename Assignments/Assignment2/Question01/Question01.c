#include <stdio.h>

int main() {
    int i,min=10000,min2=10000;
    int numarr[5];
    
    for(i=0;i<=4;i++){
        printf("enter element number %d: ",i+1);
        scanf("%d",&numarr[i]);
    }
    
    for(i=0;i<=4;i++){
        if(numarr[i]<min){
            min = numarr[i];
        }else if(numarr[i]>min && numarr[i]<min2){
            min2 = numarr[i];
        }
    }
    printf("the second smallest element in the array is: %d",min2);

    return 0;
}
