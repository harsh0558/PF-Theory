#include <stdio.h>
#include <string.h>

void compressWord(char arr[], char newarr[], int *count) {
    int i = 0, j = 0;
    *count = 0;

    while (arr[i] != '\0' && arr[i] != '\n') { 
        if (arr[i] != arr[i + 1]) {
            newarr[j++] = arr[i];
        } else {
            (*count)++;
        }
        i++;
    }
    newarr[j] = '\0';
}

int main() {
    char arr[100];
    char newarr[100];
    int count = 0;

    printf("Enter a word: ");
    fgets(arr, 100, stdin);

    compressWord(arr, newarr, &count);
    
    printf("Compressed word: %s\n", newarr);
    printf("Characters removed: %d\n", count);

    return 0;
}
