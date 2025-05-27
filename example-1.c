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

pixel led[LED_ROW][LED_COL];
int led_canvas_clear(){
    for(int i = 0; i < LED_ROW; i++){
        for(int j = 0; j < LED_COL; j++){
            strcpy(led[i][j].color, BLACK);
        }
    }
}
int led_canvas_set_pixel(int row, int col, const char *color){
    if(row < 0 || row >= LED_ROW || col < 0 || col >= LED_COL){
        return -1; // Invalid index
    }
    strcpy(led[row][col].color, color);
    return 0; // Success
}
int led_canvas_display(){
    for(int i = 0; i < LED_ROW; i++){
        printf("|");
        for(int j = 0; j < LED_COL; j++){
            printf("%s", led[i][j].color);
        }
        printf("|\n");
    }
    return 0; // Success
}

int main(int argc, char const *argv[])
{
    //↓ここを変えてね
    led_canvas_clear();
    led_canvas_set_pixel(1, 20, BLUE);
    led_canvas_set_pixel(2, 30, YELLOW);
    led_canvas_display();

    return 0;
}
