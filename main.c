#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void screen(front_x, front_y, fruit_x, fruit_y) {
    int i, j;
    printf("snek: %d %d\n", front_x, front_y);
    printf("fruit: %d %d\n", fruit_x, fruit_y);
    //top
    printf("+--------------------+\n");

    for (j = 1; j <= 10; ++j) {
        //fruit and snek in same line
        if (front_y == fruit_y && front_y == j){
            printf("|");
            //snek lefter than fruit
            if(front_x<fruit_x){
                for (i = 1; i < front_x; ++i) {
                    printf(" ");
                }
                printf("0");
                for (i = 1; i < fruit_x-(front_x); ++i) {
                    printf(" ");
                }
                printf("F");
                for (i = 1; i <= 20-(fruit_x); ++i) {
                    printf(" ");
                }

            }
            //snek righter than fruit
            if(front_x>fruit_x){
                for (i = 1; i < fruit_x; ++i) {
                    printf(" ");
                }
                printf("0");
                for (i = 1; i < front_x-(fruit_x); ++i) {
                    printf(" ");
                }
                printf("F");
                for (i = 1; i <= 20-(front_x); ++i) {
                    printf(" ");
                }

            }

            printf("|\n");
            continue;
        }


        //snek line
        if (front_y==j){
            printf("|");
            for (i = 1; i < front_x; ++i) {
                printf(" ");
            }
            printf("0");
            for (i = 1; i <= 20-(front_x); ++i) {
                printf(" ");
            }
            printf("|\n");

            continue;
        }

        //fruit line
        if (fruit_y==j){
            printf("|");
            for (i = 1; i < fruit_x; ++i) {
                printf(" ");
            }
            printf("F");
            for (i = 1; i <= 20-(fruit_x); ++i) {
                printf(" ");
            }
            printf("|\n");

            continue;
        }

        //empty line
            printf("|                    |\n");
    }

    //bottom line
    printf("+--------------------+\n");
}

int snek(){
    int snake_lenght, game=1;
    int direction, score = 0;
    int snek_x = 10, snek_y = 5;
    int fruit_x , fruit_y;

    srand(time(NULL));

    fruit_x = (rand() % 20)+1;
    fruit_y = (rand() % 10)+1;

    while(game == 1) {

        screen(snek_x, snek_y, fruit_x, fruit_y);
        game = 0;

    }
    return score;
}



int main(void) {
snek();

    //system("cls");
    return 0;

}