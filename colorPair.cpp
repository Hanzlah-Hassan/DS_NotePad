#include "colorPair.h"
ColorPair::ColorPair(){
    // red box bg
    start_color();
init_pair(9,COLOR_BLACK,COLOR_RED);
    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_BLUE,COLOR_BLACK);
    init_pair(3,COLOR_RED,COLOR_BLACK);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_YELLOW,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(7,COLOR_CYAN,COLOR_BLACK);

}
int ColorPair::getColorPair(int pairNumber) {
    return COLOR_PAIR(pairNumber);  
}
ColorPair::ColorPair(ColorPair & obj){
      start_color();
    init_pair(8,COLOR_BLACK,COLOR_RED);
     init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(0,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_BLUE,COLOR_BLACK);
    init_pair(3,COLOR_RED,COLOR_BLACK);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    init_pair(5,COLOR_YELLOW,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(7,COLOR_CYAN,COLOR_BLACK);

}
