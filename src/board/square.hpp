#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../graphics/draw_circle.hpp"
#include "../graphics/draw_cross.hpp"
#include "../graphics/draw_secure.hpp"

struct Square
{
    enum State{empty = 0, cross = 1, circle = 2};
    bool secured = false;

private:

    State state = empty;

public:

    int column;
    int row;

    Square()
    {
        column = 0;
        row = 0;
    }
    
    Square(int column_init, int row_init)
    {
        column = column_init;
        row = row_init;
    }

    bool isEmpty() {return (state == empty);}
    void setEmpty() {state = empty;}

    bool isCross() {return (state == cross);}
    void setCross() {state = cross;}

    bool isCircle() {return (state == circle);}
    void setCircle() {state = circle;}

    bool isSecured() {return secured;}
    void setSecured() {secured = true;}
    void setUnsecured() {secured = false;}

    void drawContent(sf::RenderWindow& window)
    {
        if (state == empty) 
            return;
    
        if (state == circle)
            draw_circle(window, column, row);

        if (secured)
            draw_secure(window, column, row);
            
        if (state == cross)
            draw_cross(window, column, row);
    }

};
