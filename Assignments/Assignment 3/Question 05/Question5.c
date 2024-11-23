#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int supplies, i, j, num;
    char name[20], supply[20];
    
    printf("Enter the number of species you want to store: "); 
    scanf("%d", &num);
    
    char ***speciesSupplies = (char***)malloc(num * sizeof(char**));
    int *suppliesCount = (int *)malloc(num * sizeof(int));
    
    for (i = 0; i < num; i++) {
        
        printf("Enter the name of species %d: ", i + 1);
        scanf("%s", name);
        
        speciesSupplies[i] = (char**)malloc(sizeof(char*));
        speciesSupplies[i][0] = (char*)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(speciesSupplies[i][0], name); 
        
        printf("Enter the number of supplies you want to enter for %s: ", name);
        scanf("%d", &supplies);
        
        speciesSupplies[i] = (char**)realloc(speciesSupplies[i], (supplies + 1) * sizeof(char*));
        suppliesCount[i] = supplies + 1; 
        
        for (j = 1; j <= supplies; j++) {
            printf("Enter supply no %d: ", j);
            scanf("%s", supply);
            speciesSupplies[i][j] = (char*)malloc((strlen(supply) + 1) * sizeof(char));
            strcpy(speciesSupplies[i][j], supply);
        }
    }
    
    int input = -1;
    while(input != 5) {
        printf("---MENU---\n");
        printf("1) Add Supplies\n");
        printf("2) Update Supplies\n");
        printf("3) Remove Species\n");
        printf("4) Display Inventory\n");
        printf("5) Exit\n");
        printf("Your answer: ");
        scanf("%d", &input);
        
        if(input == 1) {
            int number;
            printf("Select the number of the species you want to add the supply for: \n");
            for(i = 0; i < num; i++) {
                printf("%d) %s\n", i + 1, speciesSupplies[i][0]);
            }
            scanf("%d", &number);
            number--;  
            
            printf("Enter the supply you want to add: ");
            scanf("%s", supply);
            
            speciesSupplies[number] = (char**)realloc(speciesSupplies[number], (suppliesCount[number] + 1) * sizeof(char*));
            speciesSupplies[number][suppliesCount[number]] = (char*)malloc((strlen(supply) + 1) * sizeof(char));
            strcpy(speciesSupplies[number][suppliesCount[number]], supply);
            suppliesCount[number]++;
        }
        else if(input == 2) {
            int speciesNum, supplyNum;
            printf("Select the species number to update supply for: \n");
            for(i = 0; i < num; i++) {
                printf("%d) %s\n", i + 1, speciesSupplies[i][0]);
            }
            scanf("%d", &speciesNum);
            speciesNum--;  
            
            printf("Select the supply number to update for %s: \n", speciesSupplies[speciesNum][0]);
            for(j = 1; j < suppliesCount[speciesNum]; j++) {
                printf("%d) %s\n", j, speciesSupplies[speciesNum][j]);
            }
            scanf("%d", &supplyNum);
            supplyNum--;
            
            printf("Enter the new supply name: ");
            scanf("%s", supply);
            
            
            free(speciesSupplies[speciesNum][supplyNum]);
            speciesSupplies[speciesNum][supplyNum] = (char*)malloc((strlen(supply) + 1) * sizeof(char));
            strcpy(speciesSupplies[speciesNum][supplyNum], supply);
        }
        else if(input == 3) {  
            int speciesNum;
            printf("Select the species number to remove: \n");
            for(i = 0; i < num; i++) {
                printf("%d) %s\n", i + 1, speciesSupplies[i][0]);
            }
            scanf("%d", &speciesNum);
            speciesNum--; 
            
        
            for(j = 0; j < suppliesCount[speciesNum]; j++) {
                free(speciesSupplies[speciesNum][j]);
            }
            free(speciesSupplies[speciesNum]);
            
        
            for(i = speciesNum; i < num - 1; i++) {
                speciesSupplies[i] = speciesSupplies[i + 1];
                suppliesCount[i] = suppliesCount[i + 1];
            }
            num--;  
            speciesSupplies = (char***)realloc(speciesSupplies, num * sizeof(char**));
            suppliesCount = (int*)realloc(suppliesCount, num * sizeof(int));
        }
        else if(input == 4) { 
            printf("\nInventory:\n");
            for (i = 0; i < num; i++) {
                printf("Species: %s\n", speciesSupplies[i][0]);
                for (j = 1; j < suppliesCount[i]; j++) {  
                    printf("  Supply %d: %s\n", j, speciesSupplies[i][j]);
                }
            }
        }
    }
    
    
    for (i = 0; i < num; i++) {
        for (j = 0; j < suppliesCount[i]; j++) { 
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);
    free(suppliesCount);
    
    return 0;
}
