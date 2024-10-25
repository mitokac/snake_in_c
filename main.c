#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void screen(front_x, front_y, fruit_x, fruit_y) {
    int i, j;
    printf("snek: %d %d\n", front_x, front_y);
    printf("fruit: %d %d\n", fruit_x, fruit_y);
    //top
    printf("+--------------------+\n");

    //printing the actual lines
    for (j = 1; j <= 10; ++j) {
        printf("|");
        for (i = 1; i <= 20; ++i) {
            if(front_x==i && front_y==j){
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
    int score, game=1;
    int direction, prev_directon;
    int snek_x = 10, snek_y = 5;
    int fruit_x , fruit_y;

    srand(time(NULL));

    fruit_x = (rand() % 20)+1;
    fruit_y = (rand() % 10)+1;

    while(game == 1) {

        screen(snek_x, snek_y, fruit_x, fruit_y);
        prev_directon=direction;
        direction=move(prev_directon);
        switch (direction) {
            case 1:
                snek_x--;
                break;
            case 2:
                snek_x++;
                break;
            case 3:
                snek_y--;
                break;
            case 4:
                snek_y++;
                break;
            case 5:
                game=0;
                break;

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