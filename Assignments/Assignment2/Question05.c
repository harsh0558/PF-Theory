#include <stdio.h>
#include <string.h>

void histogram(int arr[], int count){
    int i,j;
    int max=-1;
    printf("\tHORIZONTAL HISTOGRAM\n");
    printf("\n");
    for(i=1;i<=count;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    
    for(i=0;i<count;i++){
        printf("%d:\t",arr[i]);
        for(j=1;j<=arr[i];j++){
            printf("*");
        }
        printf("\n");
    }
    
}

int main() {
    int arr[] = {3,5,1,4};
    histogram(arr,4);
    return 0;
}
