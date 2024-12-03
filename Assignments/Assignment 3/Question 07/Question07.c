#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata{
    char title[100];
    double rating;
    int runtime;
    char encoding[100];
};

struct EngagementMatrix{
    double** matrix;
    int users;
    int categories;
};

struct DeviceMatrix{
    int** matrix;
    int users;
    int devices;
};

struct ContentMetadataMatrix{
    struct metadata** matrix;
    int categories;
    int content;
};

int main(){
    struct EngagementMatrix engagementMatrix;
    struct DeviceMatrix deviceMatrix;
    struct ContentMetadataMatrix contentMetadataMatrix;
    int i, j;

    printf("Enter number of Users: ");
    scanf("%d", &engagementMatrix.users);
    printf("Enter number of categories: ");
    scanf("%d", &engagementMatrix.categories);
    printf("Enter number of devices: ");
    scanf("%d", &deviceMatrix.devices);
    printf("Enter number of content: ");
    scanf("%d", &contentMetadataMatrix.content);
    contentMetadataMatrix.categories = engagementMatrix.categories;

    engagementMatrix.matrix = (double**)malloc(engagementMatrix.users * sizeof(double*));
    for (i = 0; i < engagementMatrix.users; i++){
        engagementMatrix.matrix[i] = (double*)malloc(engagementMatrix.categories * sizeof(double));
        for (j = 0; j < engagementMatrix.categories; j++){
            printf("Enter engagement score for user %d and category %d: ", i + 1, j + 1);
            scanf("%lf", &engagementMatrix.matrix[i][j]);
        }
    }

    deviceMatrix.matrix = (int**)malloc(engagementMatrix.users * sizeof(int*));
    for (i = 0; i < engagementMatrix.users; i++){
        deviceMatrix.matrix[i] = (int*)malloc(deviceMatrix.devices * sizeof(int));
        for (j = 0; j < deviceMatrix.devices; j++){
            printf("Enter resolution preference (e.g., 1080) for user %d, device %d: ", i + 1, j + 1);
            scanf("%d", &deviceMatrix.matrix[i][j]);
        }
    }

    contentMetadataMatrix.matrix = (struct metadata**)malloc(contentMetadataMatrix.categories * sizeof(struct metadata*));
    getchar();
    for (i = 0; i < contentMetadataMatrix.categories; i++){
        contentMetadataMatrix.matrix[i] = (struct metadata*)malloc(contentMetadataMatrix.content * sizeof(struct metadata));
        for (j = 0; j < contentMetadataMatrix.content; j++){
            printf("\nEnter details for Category %d, Content %d:\n", i + 1, j + 1);
            printf("Title: ");
            fgets(contentMetadataMatrix.matrix[i][j].title, 100, stdin);
            contentMetadataMatrix.matrix[i][j].title[strcspn(contentMetadataMatrix.matrix[i][j].title, "\n")] = 0;
            printf("Rating: ");
            scanf("%lf", &contentMetadataMatrix.matrix[i][j].rating);
            printf("Runtime (in minutes): ");
            scanf("%d", &contentMetadataMatrix.matrix[i][j].runtime);
            printf("Encoding format: ");
            getchar();
            fgets(contentMetadataMatrix.matrix[i][j].encoding, 100, stdin);
            contentMetadataMatrix.matrix[i][j].encoding[strcspn(contentMetadataMatrix.matrix[i][j].encoding, "\n")] = 0;
        }
    }

    printf("\nEngagement Matrix:\n");
    for (i = 0; i < engagementMatrix.users; i++){
        for (j = 0; j < engagementMatrix.categories; j++){
            printf("User %d, Category %d: %.2f\n", i + 1, j + 1, engagementMatrix.matrix[i][j]);
        }
    }

    printf("\nDevice Preferences:\n");
    for (i = 0; i < engagementMatrix.users; i++){
        for (j = 0; j < deviceMatrix.devices; j++){
            printf("User %d, Device %d: %dp\n", i + 1, j + 1, deviceMatrix.matrix[i][j]);
        }
    }

    printf("\nContent Metadata:\n");
    for (i = 0; i < contentMetadataMatrix.categories; i++){
        for (j = 0; j < contentMetadataMatrix.content; j++){
            printf("Category %d, Content %d: %s, Rating: %.2f, Runtime: %d mins, Format: %s\n",
                   i + 1, j + 1, contentMetadataMatrix.matrix[i][j].title, contentMetadataMatrix.matrix[i][j].rating,
                   contentMetadataMatrix.matrix[i][j].runtime, contentMetadataMatrix.matrix[i][j].encoding);
        }
    }

    for (i = 0; i < engagementMatrix.users; i++){
        free(engagementMatrix.matrix[i]);
    }
    free(engagementMatrix.matrix);

    for (i = 0; i < engagementMatrix.users; i++){
        free(deviceMatrix.matrix[i]);
    }
    free(deviceMatrix.matrix);

    for (i = 0; i < contentMetadataMatrix.categories; i++){
        free(contentMetadataMatrix.matrix[i]);
    }
    free(contentMetadataMatrix.matrix);

    return 0;
}