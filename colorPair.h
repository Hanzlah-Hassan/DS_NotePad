#ifndef COLORPAIR_H
#define COLORPAIR_H
#include <ncurses.h>
class ColorPair
{
public:
    ColorPair();
    ColorPair(ColorPair &other);
    int getColorPair(int pairNumber);
};

#endif