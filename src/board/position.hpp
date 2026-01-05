#pragma once

#include "../config.hpp"
#include "square.hpp"
#include "turn.hpp"

class Position
{
public:
    Turn turn;
    Square squares[cfg::grid_size.x][cfg::grid_size.y];

    Position()
    {
        for (int column = 0; column < cfg::grid_size.x; column++)
        {
            for (int row = 0; row < cfg::grid_size.y; row ++)
            {
                squares[column][row] = Square();
            }
        }
    }
    
    bool isEmpty(int column, int row)
    {
        return squares[column][row].isEmpty();
    }
    void setEmpty(int column, int row)
    {
        squares[column][row].setEmpty();
    }

    bool isCircle(int column, int row)
    {
        return squares[column][row].isCircle();
    }
    void setCircle(int column, int row)
    {
        squares[column][row].setCircle();
    }

    bool isCross(int column, int row)
    {
        return squares[column][row].isCross();
    }
    void setCross(int column, int row)
    {
        squares[column][row].setCross();
    }
    
    bool isSecured(int column, int row)
    {
            return squares[column][row].isSecured();
    }
    void setSecured(int column, int row)
    {
        squares[column][row].setSecured();
    }
    void setUnsecured(int column, int row)
    {
        squares[column][row].setUnsecured();
    }

    void unsecureOpponent()
    {
        for (int column = 0; column < cfg::grid_size.x; column++)
        {
            for (int row = 0; row < cfg::grid_size.y; row ++)
            {   
                if (not turnMatchesContent(column, row))
                    setUnsecured(column, row);
            }
        } 
    }

    bool turnMatchesContent(int column, int row)
    {
        if (squares[column][row].isCircle() and turn.forCircle())
            return true;

        else if (squares[column][row].isCross() and turn.forCross())
            return true;

        else 
            return false;
    }
    void setSymbol(int column, int row)
    {
        if (turn.forCircle())
            setCircle(column, row);

        if (turn.forCross())
            setCross(column, row);

        turn.count_move();
    }

    void playTurn(int column, int row)
    {
        if (squares[column][row].isEmpty())
        {       
            unsecureOpponent();
               
            setSymbol(column, row);

            if (turn.move_counter == 2)
                turn.end();
        }

        else if ( 
            (turnMatchesContent(column, row))
        )
        {
            setSecured(column, row);
            
            turn.move_counter += 1;

            if (turn.move_counter ==2)
                turn.end();
        }

        else if ( 
            ( not squares[column][row].isEmpty()) and 
            turn.move_counter < 1 and
            ( not turnMatchesContent(column, row)) and
            (not squares[column][row].isSecured())
        )
        {
            setSymbol(column, row);
            setSecured(column, row);
            turn.end();
        }
    }

    void drawContent(sf::RenderWindow& window)
    {
        for (int column = 0; column < cfg::grid_size.x; column++)
        {
            for (int row = 0; row < cfg::grid_size.y; row ++)
            {
                squares[column][row].drawContent(window);
            }
        } 
    }
};