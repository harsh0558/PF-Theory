#include <stdio.h>
#include <stdlib.h>

void inputEmployees(int **ratings, int numEmployees, int numPeriods) {
    int i, j, num;

    for (i = 0; i < numEmployees; i++) {
        for (j = 0; j < numPeriods; j++) {
            num = -1; 
            while (num < 1 || num > 10) { 
                printf("Enter the rating for employee %d for period %d (1-10): ", i + 1, j + 1);
                scanf("%d", &num);
                if (num < 1 || num > 10) {
                    printf("Invalid input. Please enter a number between 1 and 10.\n");
                }
            }
            ratings[i][j] = num; 
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods) {
    int i, j;
    printf("-----Employee Performance-----\n");
    for (i = 0; i < numEmployees; i++) {
        printf("for Employee %d\n", i + 1);
        for (j = 0; j < numPeriods; j++) {
            printf("period %d rating: %d\n", j + 1, ratings[i][j]);
        }
    }
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int i, j;
    float max = -1.0, avg;
    int highestRatedPeriod = -1, total;

    for (i = 0; i < numPeriods; i++) {
        total = 0;
        for (j = 0; j < numEmployees; j++) {
            total += ratings[j][i]; 
        }
        avg = (float) total / numEmployees;
        if (avg > max) {
            max = avg;
            highestRatedPeriod = i; 
        }
    }

    return highestRatedPeriod;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    float min = 100.0, avg;
    int total, i, j, worstEmployee = -1;

    for (i = 0; i < numEmployees; i++) {
        total = 0;
        for (j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        avg = (float)total / numPeriods;
        if (avg < min) {
            min = avg;
            worstEmployee = i; 
        }
    }

    return worstEmployee;
}

int main() {
    int i, employees, periods;

    printf("Enter the number of employees: ");
    scanf("%d", &employees);

    printf("Enter the number of repeating periods: ");
    scanf("%d", &periods);

    struct Employee {
        int **ratings;
        int totalScore;
    };

    struct Employee *employeeArray = (struct Employee*)malloc(employees * sizeof(struct Employee));

    for (i = 0; i < employees; i++) {
        employeeArray[i].ratings = (int**)malloc(periods * sizeof(int*));
        employeeArray[i].totalScore = 0;

        for (int j = 0; j < periods; j++) {
            employeeArray[i].ratings[j] = (int*)malloc(sizeof(int));
        }
    }

    inputEmployees(employeeArray[0].ratings, employees, periods);  
    displayPerformance(employeeArray[0].ratings, employees, periods);  

    int highestRatedPeriod = findHighestRatedPeriod(employeeArray[0].ratings, employees, periods);  
    printf("The Highest Rated Period is: Period %d\n", highestRatedPeriod + 1);  
    

    int worstEmployee = findWorstPerformingEmployee(employeeArray[0].ratings, employees, periods); 
    printf("The Worst Performing Employee is: Employee %d\n", worstEmployee + 1);

    for (i = 0; i < employees; i++) {
        for (int j = 0; j < periods; j++) {
            free(employeeArray[i].ratings[j]); 
        }
        free(employeeArray[i].ratings);
    }

    free(employeeArray);
    
    return 0;
}
