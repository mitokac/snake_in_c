#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void screen(int *front_x,int *front_y,int fruit_x,int fruit_y, int score) {
    int i, j,k;

    printf("Score: %d\n", score-1);
    printf("snek: %d %d\n", front_x[0], front_y[0]);
    printf("fruit: %d %d\n", fruit_x, fruit_y);

    //top
    printf("+--------------------+\n");

    //printing the actual lines
    for (j = 1; j <= 10; ++j) {
        printf("|");
        for (i = 1; i <= 20; ++i) {
            for (k = 1; k < score; k++) {
                if(front_x[k]==i && front_y[k]==j){
                    printf("o");
                    k=999;
                    break;
                }
            }
            if (k==999)continue;

            if(front_x[0]==i && front_y[0]==j){
                printf("0");
                continue;
            }

            if (fruit_x==i && fruit_y==j){
                printf("F");
                continue;
            }
            printf(" ");
        }
        printf("|\n");
    }

    //bottom line
    printf("+--------------------+\n");
    printf("WASD to move\nX to exit");
}

//input recognition
int move(int direction) {
    int key = direction;
        Sleep(400);
        if (kbhit()) {
            switch (tolower(getch())) {
                case 'a':
                    if(key!=2)
                        key = 1;
                    break;
                case 'd':
                    if(key!=1)
                        key = 2;
                    break;
                case 'w':
                    if(key!=4)
                        key = 3;
                    break;
                case 's':
                    if(key!=3)
                        key = 4;
                    break;
                case 'x':
                    key = 5;
                    break;
                default:
                    break;
            }
        }
    return key;
}

int snek(){
    int score = 1, game=1;
    int direction, prev_direction;
    int snek_x[200], snek_y[200];
    int fruit_x , fruit_y;
    int i;

    snek_x[0] = 10;
    snek_y[0] = 5;

    srand(time(NULL));

    fruit_x = (rand() % 20)+1;
    fruit_y = (rand() % 10)+1;

    while(game == 1) {

        screen(snek_x, snek_y, fruit_x, fruit_y, score);
        prev_direction=direction;
        direction=move(prev_direction);

        //movement
        switch (direction) {
            case 1:
                for (i = score; i >= 1; i--) {
                    snek_x[i] = snek_x[i-1];
                    snek_y[i] = snek_y[i-1];
                }
                snek_x[0]--;
                break;
            case 2:
                for (i = score; i >= 1; i--) {
                    snek_x[i] = snek_x[i-1];
                    snek_y[i] = snek_y[i-1];
                }
                snek_x[0]++;
                break;
            case 3:
                for (i = score; i >= 1; i--) {
                    snek_x[i] = snek_x[i-1];
                    snek_y[i] = snek_y[i-1];
                }
                snek_y[0]--;
                break;
            case 4:
                for (i = score; i >= 1; i--) {
                    snek_x[i] = snek_x[i-1];
                    snek_y[i] = snek_y[i-1];
                }
                snek_y[0]++;
                break;
            case 5:
                game=0;
                break;
            default:
                break;
        }

        //check if snek eats fruit
        if (snek_x[0]==fruit_x && snek_y[0]==fruit_y){
            int g_roll=0;
            score+=1;
            //new fruit creation
            while(g_roll==0) {
                fruit_x = (rand() % 20) + 1;
                fruit_y = (rand() % 10) + 1;
                for (i = 0; i < score; i++) {
                    if (fruit_x == snek_x[i] && fruit_y == snek_y[i]) {
                        g_roll = 0;
                        break;
                    }
                    g_roll=1;

                }
            }
        }

        //check if snek ran into itself
        for (i = 1; i < score; i++) {
            if(snek_x[0]==snek_x[i] && snek_y[0]==snek_y[i]) game=0;
        }
        // check if snek ran into a wall
        if(snek_x[0]>19 || snek_x[0]<1 || snek_y[0]>10 || snek_y[0]<1) game =0;

        system("cls");
    }
    return score;
}

int main(void) {
    int score;
    score = snek()-1;
    printf("Your final score is %d", score);
    return 0;
}