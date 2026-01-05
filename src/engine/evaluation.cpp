#include "../config.hpp"

#include "../board/board.hpp"

bool CheckWin(Board& board, 
    int column, int row, 
    int d_column, int d_row
)
{
    int count = 1;
    int required = cfg::wincondition;

    //check forward

    for (int i=1; i < count; i++)
    {
        if (
        column + i*d_column < 0 or column + i*d_column > cfg::grid_size.x 
        or
        row + i*d_row < 0 or row + i*d_row > cfg::grid_size.y
        )
            break;
        
        else if (
            ! board.turnMatchesContent(column + i*d_column, row + i*d_column)
        )
            break;

        count += 1;
    }

        for (int i=1; i < count; i++)
    {
        i = -i; //reverse direction

        if (
        column * i*d_column < 0 or column + i*d_column > cfg::grid_size.x 
        or
        row + i*d_row < 0 or row + i*d_row > cfg::grid_size.y
        )
            break;
        
        else if (
            ! board.turnMatchesContent(column + i*d_column, row + i*d_column)
        )
            break;

        count += 1;
    }

    return count > required - 1;
}

float eval(Board& board)
{
    float result;

    return result;
}
