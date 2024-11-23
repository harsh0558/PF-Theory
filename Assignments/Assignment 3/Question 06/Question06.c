#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    struct Weather {
        float temperature;
        float rainfall;
        float windPatterns;
    };

    struct Crop {
        char cropType[20];
        int growthStage;
        float expectedYield;
        struct Weather *weather; 
    };

    struct Equipment {
        char equipmentName[20];
        int operationalStatus;
        float fuelLevel;
        char activitySchedule[50];
    };

    struct Sensor {
        char nutrientData[50];
        float pHLevel;
        char pestActivity[50];
    };

    struct Field {
        float gpsLatitude;
        float gpsLongitude;
        float soilHealth;
        float moistureLevel;
        struct Crop *crops;     
        int numCrops;
        struct Equipment *equipments; 
        int numEquipments;
        struct Sensor *sensors; 
        int numSensors;
    };

    struct RegionalHub {
        struct Field *fields;
        int numFields;
        float yieldPrediction;
        char resourceDistribution[100];
        char emergencyResponsePlan[100];
    };

    
    int numHubs, i, j, k;
    printf("Enter the number of regional hubs: ");
    scanf("%d", &numHubs);

    struct RegionalHub *regionalHubs = (struct RegionalHub *)malloc(numHubs * sizeof(struct RegionalHub));

    for (i = 0; i < numHubs; i++) {
        printf("\nEnter data for Regional Hub %d:\n", i + 1);

        printf("Enter number of fields in this hub: ");
        scanf("%d", &regionalHubs[i].numFields);

        
        regionalHubs[i].fields = (struct Field *)malloc(regionalHubs[i].numFields * sizeof(struct Field));

        for (j = 0; j < regionalHubs[i].numFields; j++) {
            printf("\nEnter data for Field %d in Regional Hub %d:\n", j + 1, i + 1);

            printf("Enter GPS latitude: ");
            scanf("%f", &regionalHubs[i].fields[j].gpsLatitude);

            printf("Enter GPS longitude: ");
            scanf("%f", &regionalHubs[i].fields[j].gpsLongitude);

            printf("Enter soil health: ");
            scanf("%f", &regionalHubs[i].fields[j].soilHealth);

            printf("Enter moisture level: ");
            scanf("%f", &regionalHubs[i].fields[j].moistureLevel);

            printf("Enter number of crops: ");
            scanf("%d", &regionalHubs[i].fields[j].numCrops);

            
            regionalHubs[i].fields[j].crops = (struct Crop *)malloc(regionalHubs[i].fields[j].numCrops * sizeof(struct Crop));
            for (k = 0; k < regionalHubs[i].fields[j].numCrops; k++) {
                printf("Enter data for Crop %d in Field %d:\n", k + 1, j + 1);
                printf("Enter crop type: ");
                scanf("%s", regionalHubs[i].fields[j].crops[k].cropType);
                printf("Enter growth stage: ");
                scanf("%d", &regionalHubs[i].fields[j].crops[k].growthStage);
                printf("Enter expected yield: ");
                scanf("%f", &regionalHubs[i].fields[j].crops[k].expectedYield);

                
                regionalHubs[i].fields[j].crops[k].weather = (struct Weather *)malloc(sizeof(struct Weather));
                printf("Enter temperature: ");
                scanf("%f", &regionalHubs[i].fields[j].crops[k].weather->temperature);
                printf("Enter rainfall: ");
                scanf("%f", &regionalHubs[i].fields[j].crops[k].weather->rainfall);
                printf("Enter wind patterns: ");
                scanf("%f", &regionalHubs[i].fields[j].crops[k].weather->windPatterns);
            }

            printf("Enter number of equipment: ");
            scanf("%d", &regionalHubs[i].fields[j].numEquipments);

            
            regionalHubs[i].fields[j].equipments = (struct Equipment *)malloc(regionalHubs[i].fields[j].numEquipments * sizeof(struct Equipment));
            for (k = 0; k < regionalHubs[i].fields[j].numEquipments; k++) {
                printf("Enter data for Equipment %d in Field %d:\n", k + 1, j + 1);
                printf("Enter equipment name: ");
                scanf("%s", regionalHubs[i].fields[j].equipments[k].equipmentName);
                printf("Enter operational status (1 for active, 0 for inactive): ");
                scanf("%d", &regionalHubs[i].fields[j].equipments[k].operationalStatus);
                printf("Enter fuel level: ");
                scanf("%f", &regionalHubs[i].fields[j].equipments[k].fuelLevel);
                printf("Enter activity schedule: ");
                scanf("%s", regionalHubs[i].fields[j].equipments[k].activitySchedule);
            }

            printf("Enter number of sensors: ");
            scanf("%d", &regionalHubs[i].fields[j].numSensors);

            
            regionalHubs[i].fields[j].sensors = (struct Sensor *)malloc(regionalHubs[i].fields[j].numSensors * sizeof(struct Sensor));
            for (k = 0; k < regionalHubs[i].fields[j].numSensors; k++) {
                printf("Enter data for Sensor %d in Field %d:\n", k + 1, j + 1);
                printf("Enter nutrient data: ");
                scanf("%s", regionalHubs[i].fields[j].sensors[k].nutrientData);
                printf("Enter pH level: ");
                scanf("%f", &regionalHubs[i].fields[j].sensors[k].pHLevel);
                printf("Enter pest activity: ");
                scanf("%s", regionalHubs[i].fields[j].sensors[k].pestActivity);
            }
        }

        printf("Enter yield prediction for Regional Hub %d: ", i + 1);
        scanf("%f", &regionalHubs[i].yieldPrediction);

        printf("Enter resource distribution plan for Regional Hub %d: ", i + 1);
        scanf("%s", regionalHubs[i].resourceDistribution);

        printf("Enter emergency response plan for Regional Hub %d: ", i + 1);
        scanf("%s", regionalHubs[i].emergencyResponsePlan);
    }

    
    for (i = 0; i < numHubs; i++) {
        for (j = 0; j < regionalHubs[i].numFields; j++) {
            for (k = 0; k < regionalHubs[i].fields[j].numCrops; k++) {
                free(regionalHubs[i].fields[j].crops[k].weather);
            }
            free(regionalHubs[i].fields[j].crops);
            free(regionalHubs[i].fields[j].equipments);
            free(regionalHubs[i].fields[j].sensors);
        }
        free(regionalHubs[i].fields);
    }
    free(regionalHubs);

    return 0;
}
