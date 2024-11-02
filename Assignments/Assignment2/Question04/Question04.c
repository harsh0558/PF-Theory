#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    int num,i,j;
    printf("Enter the number of words you want to enter: ");
    scanf("%d", &num);
    
    getchar();

    char words[num][100];
    char words1[num][100];
    bool words2[num];
    
    for(i=0;i<num;i++){
        words2[i] = false;
    }
    
     for (i = 0; i < num; i++) {
        printf("Enter a word: ");
        fgets(words[i], sizeof(words[i]), stdin);
        words[i][strcspn(words[i], "\n")] = '\0'; 
        strcpy(words1[i], words[i]); 
    }
    
    
    for(i=0;i<num;i++){
        bool swap = true;
        int boundary = strlen(words[i]);
        while (swap==true){
            swap = false;
            for(j=0;j<boundary-1;j++){
                if(words[i][j]>words[i][j+1]){
                    char temp = words[i][j];
                    words[i][j] = words[i][j+1];
                    words[i][j+1] = temp;
                    swap = true;
                }
            }
            boundary--;
        }
    }
    
    for(i = 0; i < num; i++) {
        if(words2[i]!=true) {
            printf("for %s:\n", words1[i]); 
            words2[i] = true;
            printf("%s\n", words1[i]); 
            for(j = i + 1; j < num; j++) {
                if(strcmp(words[i], words[j]) == 0) {
                    printf("%s\n", words1[j]);
                    words2[j] = true;
                }
            }
        }
    }
    
    
    return 0;
}
