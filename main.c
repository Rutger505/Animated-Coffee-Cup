#include <stdio.h>
#include <time.h>

#define GRID_X_SIZE 18
#define GRID_Y_SIZE 7

int main(void) {
    printf("Hello, World!\n");


    char objectCharacters[GRID_Y_SIZE][GRID_X_SIZE] = {
        {},
        {},
        {},
        {'|', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '|'},
        {'|', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '|'},
        {'|', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '|'},
        {'|', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '|'},
    };

    char particleCharacters[] = {'#', '/', '*'};
    short particleLevels[GRID_Y_SIZE][GRID_X_SIZE] = {
        {0, 3, 3, 2, 2, 3, 3, 3},
        {0, 2, 1, 1, 1, 2, 2, 2},
        {2, 2, 2, 1, 1, 1, 1, 2}
    };


    for (int i = 0; i < GRID_Y_SIZE; i++) {
        for (int j = 0; j < GRID_X_SIZE; j++) {
            char objectCharacter = objectCharacters[i][j];
            short particleLevel = particleLevels[i][j];
            if (objectCharacter != 0) {
                printf("%c", objectCharacter);
            } else if (particleLevel != 0) {
                printf("%c", particleCharacters[particleLevel - 1]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }


    printf("1\n");
    nanosleep(1 * 1000 * 1000);
    printf("2");
    nanosleep(1 * 1000 * 1000);
    printf("\r3");

    return 0;
}
