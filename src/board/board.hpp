#pragma once

#include "../config.hpp"
#include "square.hpp"

class Board
{
private:
    Square squares[cfg::grid_size.x][cfg::grid_size.y];

public:
    Board()
    {
        for (int column = 0; column < cfg::grid_size.x; column++)
        {
            for (int row = 0; row < cfg::grid_size.y; row ++)
            {
                squares[column][row] = Square(column, row);
            }
        }
    }
    
    bool isEmpty(int column, int row)
    {
        squares[column][row].isEmpty();
    }
    void setEmpty(int column, int row)
    {
        squares[column][row].setEmpty();
    }

    bool isCircle(int column, int row)
    {
        squares[column][row].isCircle();
    }
    void setCircle(int column, int row)
    {
        squares[column][row].setCircle();
    }

    bool isCross(int column, int row)
    {
        squares[column][row].isCross();
    }
    void setCross(int column, int row)
    {
        squares[column][row].setCross();
    }

    
};