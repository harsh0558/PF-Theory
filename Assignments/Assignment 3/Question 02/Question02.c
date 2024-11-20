#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[100];
    int totalScore;
};

bool validateScore(int num) {
    if (num > 6 || num < 0) {
        return false;
    } else {
        return true;
    }
}

struct Player playGame(struct Player player) { 
    int i, score, total = 0;

    for (i = 0; i < 12; i++) {
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &score);
        if (validateScore(score)) {
            player.ballScores[i] = score;
            total += score;
        } else {
            player.ballScores[i] = 0;
        }
    }
    player.totalScore = total; 
    return player;  
}

int findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        return 1;
    } else {
        return 2;
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    float average1 = player1.totalScore / 12.0;
    float average2 = player2.totalScore / 12.0;

    printf("\n--- Match Scoreboard ---\n");

    printf("\nPlayer 1: %s\n", player1.playerName);
    printf("Scores: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score: %d", player1.totalScore);
    printf("\nAverage Score: %.2f\n", average1);

    printf("\nPlayer 2: %s\n", player2.playerName);
    printf("Scores: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score: %d", player2.totalScore);
    printf("\nAverage Score: %.2f\n", average2);
}

int main() {
    struct Player player1, player2;

    printf("Enter the name of Player 1: ");
    fgets(player1.playerName, 100, stdin);
    player1.playerName[strcspn(player1.playerName, "\n")] = '\0'; 
    player1 = playGame(player1);
    getchar();
    printf("Enter the name of Player 2: ");
    fgets(player2.playerName, 100, stdin);
    player2.playerName[strcspn(player2.playerName, "\n")] = '\0'; 
    player2 = playGame(player2); 

    displayMatchScoreboard(player1, player2);

    if (findWinner(player1, player2) == 1) {
        printf("\nTHE WINNER IS: %s\n", player1.playerName);
    } else {
        printf("\nTHE WINNER IS: %s\n", player2.playerName);
    }

    return 0;
}
