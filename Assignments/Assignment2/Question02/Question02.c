#include <stdio.h>
#include <string.h>

int main() {
    int row, i, j, k, count = 0;

    printf("Enter the number of slogans you want to enter: ");
    scanf("%d", &row);
    
    getchar();

    char arr[row][100];

    for (i = 0; i < row; i++) {
        printf("Enter slogan number %d: ", i + 1);
        fgets(arr[i], 100, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; 
    }

    for (i = 0; i < row; i++) {
        printf("For %s\n", arr[i]);
        for (j = 0; arr[i][j] != '\0'; j++) {
            if (arr[i][j] != '%' && arr[i][j] != ' ') {
                count = 1; 
                printf("%c=", arr[i][j]);
                for (k = j + 1; arr[i][k] != '\0'; k++) {
                    if (arr[i][j] == arr[i][k]) {
                        arr[i][k] = '%'; 
                        count++; 
                    }
                }
                printf("%d\n", count); 
            }
        }
    }

    return 0;
}
