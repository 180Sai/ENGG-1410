#pragma once
#include <stdio.h>

int updateScore(char winner)
{
    static int x = 0;
    static int y = 0;

    if (winner == 'X')
    {
        x++;
        return x;
    }

    y++;
    return y;
}
