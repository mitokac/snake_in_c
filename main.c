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

//int move() {
//    int key;
//    while(1) {
//        if (_kbhit())
//            key = _getch();
//            // do stuff depending on key_code
//        else
//            key = 0;
//        Sleep(100);
//        printf("%d", key);
//    }
//
//    return key;
//}

int snek(){
    int score, game=1;
    int direction;
    int snek_x = 10, snek_y = 5;
    int fruit_x , fruit_y;

    srand(time(NULL));

    fruit_x = (rand() % 20)+1;
    fruit_y = (rand() % 10)+1;

    while(game == 1) {

        screen(snek_x, snek_y, fruit_x, fruit_y);
//        move();
        game = 0;

    }
    return 0;
}



int main(void) {
snek();

    //system("cls");
    return 0;

}