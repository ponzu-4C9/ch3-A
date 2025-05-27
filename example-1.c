#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LED_ROW 20  //16
#define LED_COL 70  //16

#define RED "\x1b[41m \x1b[0m"
#define GREEN "\x1b[42m \x1b[0m"
#define BLUE "\x1b[44m \x1b[0m"
#define YELLOW "\x1b[43m \x1b[0m"
#define MAGENTA "\x1b[45m \x1b[0m"
#define CYAN "\x1b[46m \x1b[0m"
#define WHITE "\x1b[47m \x1b[0m"
#define BLACK "\x1b[40m \x1b[0m"

typedef struct pixel{
    char color[11];
} pixel;



int main(int argc, char const *argv[])
{
    pixel led[LED_ROW][LED_COL];
    
    for(int i = 0; i < LED_ROW; i++){
        for(int j = 0; j < LED_COL; j++){
            strcpy(led[i][j].color, BLACK);
        }
    }
    //--------------------------------------------
    strcpy(led[0][10].color, GREEN);
    strcpy(led[5][0].color, RED);


    //--------------------------------------------
    printf("\n");
    for(int i = 0; i < LED_ROW; i++){
        printf("|");
        for(int j = 0; j < LED_COL; j++){
            printf("%s", led[i][j].color);
        }
        printf("|\n");
    }

    return 0;
}
