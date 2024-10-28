#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void screen(int *front_x,int *front_y,int fruit_x,int fruit_y, int score) {
    int i, j,k;
    printf("snek: %d %d\n", front_x[0], front_y[0]);
    printf("fruit: %d %d\n", fruit_x, fruit_y);
    //top
    printf("+--------------------+\n");

    //printing the actual lines
    for (j = 1; j <= 10; ++j) {
        printf("|");
        for (i = 1; i <= 20; ++i) {
            for (k = 0; k < score; k++) {
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
}

int move(direction) {
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
//        printf("%d", key);


    return key;
}

int snek(){
    int score = 0, game=1;
    int direction, prev_directon;
    int snek_x[20], snek_y[20];
    int fruit_x , fruit_y;
    int i,j;

    snek_x[0] = 10;
    snek_y[0] = 5;


    srand(time(NULL));

    fruit_x = (rand() % 20)+1;
    fruit_y = (rand() % 10)+1;

    while(game == 1) {

        screen(snek_x, snek_y, fruit_x, fruit_y, score);
        prev_directon=direction;
        direction=move(prev_directon);
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

        }

        if (snek_x[0]==fruit_x && snek_y[0]==fruit_y){
            int g_roll=0;
            score+=1;
            while(g_roll==0) {
                for (i = 0; i < score; i++) {
                    fruit_x = (rand() % 20) + 1;
                    fruit_y = (rand() % 10) + 1;
                    if (fruit_x == snek_x[i] && fruit_y == snek_y[i]) {
                        g_roll = 0;
                        break;
                    }
                }
                g_roll=1;
            }


        }
        system("cls");



    }
    return 0;
}



int main(void) {
snek();

    //system("cls");
    return 0;

}