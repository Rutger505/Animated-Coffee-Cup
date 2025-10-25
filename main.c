#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GRID_X_SIZE 15
#define GRID_Y_SIZE 9

const char objectCharacters[GRID_Y_SIZE][GRID_X_SIZE] = {
    {},
    {},
    {},
    {},
    {'|', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '|'},
    {'|', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '|'},
    {0, '\\', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '/', 0},
    {0, 0, '\\', 0, 0, 0, 0, 0, 0, 0, 0, 0, '/', 0, 0},
    {0, 0, 0, '-', '-', '-', '-', '-', '-', '-', '-', '-', 0, 0, 0},
};

const char particleCharacters[] = {'#', '~', '*'};
const short particleLevels[GRID_Y_SIZE][GRID_X_SIZE] = {
    {0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0},
    {0, 0, 4, 4, 4, 3, 3, 3, 3, 3, 4, 4, 4, 0, 0},
    {0, 0, 4, 3, 2, 2, 2, 2, 2, 2, 2, 3, 4, 0, 0},
    {0, 0, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0},
};


const int totalSeconds = 5;
const int frameRate = 5;

int main(void) {
    srandom(time(NULL));

    for (int frame = 0; frame < frameRate * totalSeconds; frame++) {
        // Clear terminal output
        printf("\033[2J\n");
        // Move cursor to top left corner
        printf("\033[H");

        printf("Frame %d\n", frame);

        for (int i = 0; i < GRID_Y_SIZE; i++) {
            for (int j = 0; j < GRID_X_SIZE; j++) {
                char objectCharacter = objectCharacters[i][j];
                short particleLevel = particleLevels[i][j];
                if (objectCharacter != 0) {
                    printf("%c", objectCharacter);
                } else if (particleLevel != 0) {
                    int particleLevelIndex = particleLevel - 1;

                    // TODO make constants
                    int randomParticleOffset = random() % 3 - 1;

                    int randomizedParticleIndex = particleLevelIndex + randomParticleOffset;
                    if (randomizedParticleIndex < 0) {
                        randomizedParticleIndex = 0;
                    }

                    printf("%c", particleCharacters[randomizedParticleIndex]);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        usleep((int) (1 / (double) frameRate * 1000 * 1000));
    }

    return 0;
}
