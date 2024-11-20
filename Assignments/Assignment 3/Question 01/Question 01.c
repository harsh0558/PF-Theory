#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee{
    char employeeCode[100];
    char employeeName[100];
    char dateOfJoining[100];
};

void initialise(char ec[], char en[], char doj[], struct Employee array[], int index){
    strcpy(array[index].employeeCode, ec);
    strcpy(array[index].employeeName, en);
    strcpy(array[index].dateOfJoining, doj);
}

void tenure(struct Employee array[]){
    char currentdate[20];
    int count = 0;

    printf("Enter current date (FORMAT DD-MM-YYYY): ");
    scanf("%s", currentdate);

    char curDayStr[3] = {currentdate[0], currentdate[1], '\0'};
    char curMonthStr[3] = {currentdate[3], currentdate[4], '\0'};
    char curYearStr[5] = {currentdate[6], currentdate[7], currentdate[8], currentdate[9], '\0'};

    int currentday = atoi(curDayStr);
    int currentmonth = atoi(curMonthStr);
    int currentyear = atoi(curYearStr);

    int i;

    printf("\tEmployee Details\n");

    for (i = 0; i < 4; i++) {
        char joinDayStr[3] = {array[i].dateOfJoining[0], array[i].dateOfJoining[1], '\0'};
        char joinMonthStr[3] = {array[i].dateOfJoining[3], array[i].dateOfJoining[4], '\0'};
        char joinYearStr[5] = {array[i].dateOfJoining[6], array[i].dateOfJoining[7], array[i].dateOfJoining[8], array[i].dateOfJoining[9], '\0'};

        int joiningday = atoi(joinDayStr);
        int joiningmonth = atoi(joinMonthStr);
        int joiningyear = atoi(joinYearStr);

        int tenureYear = currentyear - joiningyear;
        int tenureMonth = currentmonth - joiningmonth;
        int tenureDay = currentday - joiningday;

        if (tenureDay < 0) {
            tenureMonth--;
            tenureDay += 30;
        }
        if (tenureMonth < 0) {
            tenureYear--;
            tenureMonth += 12;
        }

        if ((tenureYear > 3) || (tenureYear == 3 && tenureMonth > 0) || (tenureYear == 3 && tenureDay > 0)) {
            count++;
            printf("Employee name: %s\n", array[i].employeeName);
            printf("Employee code: %s\n", array[i].employeeCode);
            printf("Date Of Joining: %s\n", array[i].dateOfJoining);
        }
    }
}

int main() {
    struct Employee arr[4];
    int i;
    char name[20], code[20], date[20];

    for (i = 0; i < 4; i++) {
        printf("Enter the name of the employee: ");
        fgets(name, 20, stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter the employee code:  ");
        fgets(code, 20, stdin);
        code[strcspn(code, "\n")] = '\0';

        printf("Enter the date of joining (FORMAT DD-MM-YYYY):  ");
        fgets(date, 20, stdin);
        date[strcspn(date, "\n")] = '\0';

        initialise(code, name, date, arr, i);
    }
    tenure(arr);

    return 0;
}
