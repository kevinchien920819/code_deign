#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define CANVAS_SIZE 50
#define CANVAS_HEIGHT 10
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

// struct itemData {
//     char shape;
//     int frequency;
// };

struct playerData {
    char skin;
    int jumpState;
};

// int readData(struct itemData **itemList) {
//     FILE *fp;
//     int noOfItem = 0;
//     free(*itemList);

//     if ((fp = fopen("gameData.txt", "r+")) == NULL) {  // open file
//         printf("Game data file cannot be opened.");
//     }

//     for (int i = 0; !feof(fp); i++) {
//         if (fgetc(fp) == '\n') {
//             noOfItem++;
//         };
//     }
//     // printf("%d\n", noOfItem);

//     *itemList = malloc(noOfItem * sizeof(struct itemData));
//     if (*itemList == NULL) {
//         return 0;
//     }
//     rewind(fp);
//     for (int i = 0; !feof(fp); i++) {  // read data from file and put into struct
//         fscanf(fp, "%c", &(*itemList)[i].shape);
//         fscanf(fp, "%d", &(*itemList)[i].frequency);
//         fgetc(fp);
//     }

//     return noOfItem;
//     fclose(fp);  // close
// }

// void writeData(struct itemData **itemList, int noOfItems) {
//     for (int i = 0; i < noOfItems; i++) {
//         printf("%c ", (*itemList)[i].shape);
//         printf("%d", (*itemList)[i].frequency);
//         printf("\n");
//     }
// }

void intro(char (*canvas)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*object)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*bkg)[CANVAS_HEIGHT][CANVAS_SIZE + 10]) {
    int start, ani = 0;
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("                                                 |\n");
    // printf("_____O____________________________________________\n");
        gotoxy(0, 0);
        printf("\e[?25l");
        system("cls");
        for(int i = 0; i < CANVAS_SIZE+10; i++) {
            if((*bkg)[CANVAS_HEIGHT-1][i] == '0') {
                (*bkg)[CANVAS_HEIGHT-1][i-3] = '/';
                (*bkg)[CANVAS_HEIGHT-1][i+3] = '\\';
                (*bkg)[CANVAS_HEIGHT-2][i-2] = '/';
                (*bkg)[CANVAS_HEIGHT-2][i+2] = '\\';
                (*bkg)[CANVAS_HEIGHT-3][i-1] = '/';
                (*bkg)[CANVAS_HEIGHT-3][i+1] = '\\';
                (*bkg)[CANVAS_HEIGHT-4][i] = '_';
                (*bkg)[CANVAS_HEIGHT-1][i] = ' ';
            }
            if((*bkg)[CANVAS_HEIGHT-1][i] == '1') {
                (*bkg)[CANVAS_HEIGHT-1][i-2] = '/';
                (*bkg)[CANVAS_HEIGHT-1][i+2] = '\\';
                (*bkg)[CANVAS_HEIGHT-2][i-1] = '/';
                (*bkg)[CANVAS_HEIGHT-2][i+1] = '\\';
                (*bkg)[CANVAS_HEIGHT-3][i] = '_';
                (*bkg)[CANVAS_HEIGHT-1][i] = ' ';
            }
        }

        // Draw ground
        for (int i = 0; i < CANVAS_SIZE; i++) {
            (*canvas)[CANVAS_HEIGHT-1][i] = '_';
        }
        // Draw background
        for (int i = 0; i < CANVAS_HEIGHT-1; i++) {
            for (int j = 0; j < CANVAS_SIZE; j++) {
                (*canvas)[i][j] = (*bkg)[i][j];
            }
        }
        for (int j = 0; j < CANVAS_SIZE; j++) {
            if ((*bkg)[CANVAS_HEIGHT - 1][j] != ' ')
                (*canvas)[CANVAS_HEIGHT-1][j] = (*bkg)[CANVAS_HEIGHT-1][j];
            }
        // Draw items
        for (int i = 0; i < CANVAS_HEIGHT; i++) {
            for (int j = 0; j < CANVAS_SIZE; j++) {
                if ((*object)[i][j] != ' ')
                    (*canvas)[i][j] = (*object)[i][j];
            }
        }
        (*canvas)[CANVAS_HEIGHT-1][5] = 'O';
        // Printf canvas
        for (int i = 0; i < CANVAS_HEIGHT; i++) {
            for (int j = 0; j < CANVAS_SIZE; j++) {
                printf("%c", (*canvas)[i][j]);
            }
            printf("\n");
        }
    printf("Type Anything then press Enter to start!");
    if(scanf("%d", &start) == 0) {
        return 0;
    };
}

void outro(char (*canvas)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*object)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*bkg)[CANVAS_HEIGHT][CANVAS_SIZE + 10], int *tick) {
    for(int timer = 0; timer < 2; timer++) {
        gotoxy(0, 0);
        printf("\e[?25l");
        system("cls");
        for(int i = 15; i <= 35; i++) {
            (*bkg)[CANVAS_HEIGHT-7][i] = '-';
            (*bkg)[CANVAS_HEIGHT-6][i] = ' ';
            (*bkg)[CANVAS_HEIGHT-5][i] = ' ';
            (*bkg)[CANVAS_HEIGHT-4][i] = '-';   
        }
        (*bkg)[CANVAS_HEIGHT-6][15] = '|';
        (*bkg)[CANVAS_HEIGHT-5][15] = '|';
        (*bkg)[CANVAS_HEIGHT-6][35] = '|';
        (*bkg)[CANVAS_HEIGHT-5][35] = '|';

        (*bkg)[CANVAS_HEIGHT-6][20] = 'Y';
        (*bkg)[CANVAS_HEIGHT-6][21] = 'o';
        (*bkg)[CANVAS_HEIGHT-6][22] = 'u';
        (*bkg)[CANVAS_HEIGHT-6][24] = ' ';
        (*bkg)[CANVAS_HEIGHT-6][25] = 'D';
        (*bkg)[CANVAS_HEIGHT-6][26] = 'i';
        (*bkg)[CANVAS_HEIGHT-6][27] = 'e';
        (*bkg)[CANVAS_HEIGHT-6][28] = 'd';
        (*bkg)[CANVAS_HEIGHT-6][29] = '!';

        if(timer == 1) {
            (*bkg)[CANVAS_HEIGHT-5][20] = 'S';
            (*bkg)[CANVAS_HEIGHT-5][21] = 'c';
            (*bkg)[CANVAS_HEIGHT-5][22] = 'o';
            (*bkg)[CANVAS_HEIGHT-5][23] = 'r';
            (*bkg)[CANVAS_HEIGHT-5][24] = 'e';
            (*bkg)[CANVAS_HEIGHT-5][25] = ':';
            (*bkg)[CANVAS_HEIGHT-5][26] = (*tick) % 10000 / 1000 + '0';
            (*bkg)[CANVAS_HEIGHT-5][27] = (*tick) % 1000 / 100 + '0';
            (*bkg)[CANVAS_HEIGHT-5][28] = (*tick) % 100 / 10 + '0';
            (*bkg)[CANVAS_HEIGHT-5][29] = (*tick) % 10 + '0';
        }

        // Draw background
        for (int i = 0; i < CANVAS_HEIGHT-1; i++) {
            for (int j = 0; j < CANVAS_SIZE; j++) {
                (*canvas)[i][j] = (*bkg)[i][j];
            }
        }
        for (int i = 0; i < CANVAS_HEIGHT; i++) {
            for (int j = 0; j < CANVAS_SIZE; j++) {
                printf("%c", (*canvas)[i][j]);
            }
            printf("\n");
        }
        Sleep(1000);
    }
    (*object)[CANVAS_HEIGHT-1][5] = ' ';
    *tick = 0;
}

void background(char (*bkg)[CANVAS_HEIGHT][CANVAS_SIZE + 10], int tick) {
    // Spawn background elements
    // Mountains
    int size = rand() % 2;
    if(rand() % 20 == 0) {
        (*bkg)[CANVAS_HEIGHT-1][CANVAS_SIZE+4] = size + '0';
    }
    for(int i = 0; i < CANVAS_SIZE+10; i++) {
        if((*bkg)[CANVAS_HEIGHT-1][i] == '0') {
            (*bkg)[CANVAS_HEIGHT-1][i-3] = '/';
            (*bkg)[CANVAS_HEIGHT-1][i+3] = '\\';
            (*bkg)[CANVAS_HEIGHT-2][i-2] = '/';
            (*bkg)[CANVAS_HEIGHT-2][i+2] = '\\';
            (*bkg)[CANVAS_HEIGHT-3][i-1] = '/';
            (*bkg)[CANVAS_HEIGHT-3][i+1] = '\\';
            (*bkg)[CANVAS_HEIGHT-4][i] = '_';
            (*bkg)[CANVAS_HEIGHT-1][i] = ' ';
        }
        if((*bkg)[CANVAS_HEIGHT-1][i] == '1') {
            (*bkg)[CANVAS_HEIGHT-1][i-2] = '/';
            (*bkg)[CANVAS_HEIGHT-1][i+2] = '\\';
            (*bkg)[CANVAS_HEIGHT-2][i-1] = '/';
            (*bkg)[CANVAS_HEIGHT-2][i+1] = '\\';
            (*bkg)[CANVAS_HEIGHT-3][i] = '_';
            (*bkg)[CANVAS_HEIGHT-1][i] = ' ';
        }
    }

    // Clouds
    if(rand() % 50 == 0) {
        int height = CANVAS_HEIGHT - 5 - rand() % 5;
        (*bkg)[height][CANVAS_SIZE] = '~';
    }

    // Move elements to the left
    if(tick % 2 == 0) {
        for (int i = 0; i < CANVAS_HEIGHT; i++) {
            if ((*bkg)[i][0] != ' ') {
                (*bkg)[i][0] = ' ';
            }
            for (int j = 1; j < CANVAS_SIZE+10; j++) {
                if ((*bkg)[i][j] != ' ' && (*bkg)[i][j] != '~') {
                    char temp = (*bkg)[i][j];
                    (*bkg)[i][j] = (*bkg)[i][j - 1];
                    (*bkg)[i][j - 1] = temp;
                }
            }
        }
    }
    if(tick % 5 == 0) {
        for (int i = 0; i < CANVAS_HEIGHT; i++) {
            if ((*bkg)[i][0] != ' ') {
                (*bkg)[i][0] = ' ';
            }
            for (int j = 1; j < CANVAS_SIZE+10; j++) {
                if ((*bkg)[i][j] == '~') {
                    char temp = (*bkg)[i][j];
                    (*bkg)[i][j] = (*bkg)[i][j - 1];
                    (*bkg)[i][j - 1] = temp;
                }
            }
        }
    }
}

int update(char (*object)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*canvas)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*bkg)[CANVAS_HEIGHT][CANVAS_SIZE + 10], struct playerData *player, int *tick) {
    // Check keyboard input
    // Jumping
    if (GetAsyncKeyState(VK_UP) & 0x8000 && player->jumpState == 0) {
        player->jumpState = 5;
    } else if (player->jumpState > 0) {
        player->jumpState--;
    }

    // Check collision
    // Player vs cactus
    if ((*object)[CANVAS_HEIGHT - 1][5] == 'X' && player->jumpState == 0) {
        return 0;
    }

    // Move item to the left
    // Gound level
    for (int i = CANVAS_HEIGHT - 1; i < CANVAS_HEIGHT; i++) {
        if ((*object)[i][0] != ' ') {
            (*object)[i][0] = ' ';
        }
        for (int j = 1; j < CANVAS_SIZE; j++) {
            if ((*object)[i][j] != ' ') {
                char temp = (*object)[i][j];
                (*object)[i][j] = (*object)[i][j - 1];
                (*object)[i][j - 1] = temp;
            }
        }
    }

    // Spawn item
    // Ground level
    if (rand() % 10 == 0 &&
        (*object)[CANVAS_HEIGHT - 1][CANVAS_SIZE - 1] != 'X' &&
        (*object)[CANVAS_HEIGHT - 1][CANVAS_SIZE - 2] != 'X' &&
        (*object)[CANVAS_HEIGHT - 1][CANVAS_SIZE - 3] != 'X' &&
        (*object)[CANVAS_HEIGHT - 1][CANVAS_SIZE - 4] != 'X' &&
        (*object)[CANVAS_HEIGHT - 1][CANVAS_SIZE - 5] != 'X') {
        (*object)[CANVAS_HEIGHT - 1][CANVAS_SIZE - 1] = 'X';
    }

    background(bkg, *tick);

    // Draw canvas to terminal
    // Draw ground
    for (int i = 0; i < CANVAS_SIZE; i++) {
        (*canvas)[CANVAS_HEIGHT - 1][i] = '_';
    }
    // Draw background
    for (int i = 0; i < CANVAS_HEIGHT-1; i++) {
        for (int j = 0; j < CANVAS_SIZE; j++) {
            (*canvas)[i][j] = (*bkg)[i][j];
        }
    }
    for (int j = 0; j < CANVAS_SIZE; j++) {
        if ((*bkg)[CANVAS_HEIGHT - 1][j] != ' ')
            (*canvas)[CANVAS_HEIGHT-1][j] = (*bkg)[CANVAS_HEIGHT-1][j];
        }
    // Draw items
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_SIZE; j++) {
            if ((*object)[i][j] != ' ')
                (*canvas)[i][j] = (*object)[i][j];
        }
    }
    // Drawer player
    if (player->jumpState == 0) {
        (*canvas)[CANVAS_HEIGHT - 1][5] = player->skin;
        if ((*canvas)[CANVAS_HEIGHT - 2][5] == player->skin) {
            (*canvas)[CANVAS_HEIGHT - 2][5] = (*object)[CANVAS_HEIGHT - 2][5];
        }
    } else {
        (*canvas)[CANVAS_HEIGHT - 2][5] = player->skin;
        if ((*canvas)[CANVAS_HEIGHT - 1][5] == player->skin) {
            (*canvas)[CANVAS_HEIGHT - 1][5] = (*object)[CANVAS_HEIGHT - 1][5];
        }
    }
    // Printf canvas
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_SIZE; j++) {
            printf("%c", (*canvas)[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d", *tick);
    (*tick)++;
    // printf("%d", *tick);
    return 1;
}

void initialise(char (*canvas)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*object)[CANVAS_HEIGHT][CANVAS_SIZE + 1], char (*bkg)[CANVAS_HEIGHT][CANVAS_SIZE + 10], struct playerData *player, int *tick) {
    // Clear all arrays
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_SIZE; j++) {
            (*canvas)[i][j] = ' ';
            (*object)[i][j] = ' ';
        }
    }
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_SIZE+10; j++) {
            (*bkg)[i][j] = ' ';
        }
    }

    // Prepare intro
    (*bkg)[CANVAS_HEIGHT-1][10] = '1';
    (*bkg)[CANVAS_HEIGHT-1][35] = '0';
    (*bkg)[CANVAS_HEIGHT-1][40] = '1';
    (*bkg)[CANVAS_HEIGHT-7][10] = '~';
    (*bkg)[CANVAS_HEIGHT-7][11] = '~';
    (*bkg)[CANVAS_HEIGHT-6][24] = '~';
    (*object)[CANVAS_HEIGHT-1][26] = 'X';
    (*canvas)[CANVAS_HEIGHT-1][5] = 'O';

    (*bkg)[CANVAS_HEIGHT-3][20] = 'D';
    (*bkg)[CANVAS_HEIGHT-3][21] = 'i';
    (*bkg)[CANVAS_HEIGHT-3][22] = 'n';
    (*bkg)[CANVAS_HEIGHT-3][23] = 'o';
    (*bkg)[CANVAS_HEIGHT-3][25] = 'G';
    (*bkg)[CANVAS_HEIGHT-3][26] = 'a';
    (*bkg)[CANVAS_HEIGHT-3][27] = 'm';
    (*bkg)[CANVAS_HEIGHT-3][28] = 'e';
    
    // Set player data
    player->skin = 'O';
    player->jumpState = 0;
    *tick = 0;
}

int main() {
    // struct itemData *itemList;
    struct playerData player;
    char object[CANVAS_HEIGHT][CANVAS_SIZE + 1];
    char canvas[CANVAS_HEIGHT][CANVAS_SIZE + 1];
    char bkg[CANVAS_HEIGHT][CANVAS_SIZE + 10];
    // int noOfItem;
    int tick = 2;
    char tryAgain;

    // itemList = NULL;
    // noOfItem = readData(&itemList);
    srand(time(NULL));
    initialise(&canvas, &object, &bkg, &player, &tick);

    gotoxy(0, 0);
    printf("\e[?25l");
    system("cls");

    while(1) {
        intro(&canvas, &object, &bkg);
        while (update(&object, &canvas, &bkg, &player, &tick)) {
            Sleep(100);
            gotoxy(0, 0);
            printf("\e[?25l");
            system("cls");
        }
        outro(&canvas, &object, &bkg, &tick);
        scanf("%c", &tryAgain);
    }
    // free(itemList);
    return 0;
}