#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../config.hpp"
#include "../graphics/draw_house.hpp"
#include "../graphics/draw_fence.hpp"

struct Square
{
    color house = none;
    color fence = none;
    
    Square(): 
        house(none),
        fence(none)
        {}

    Square(color house_init, color fence_init): 
        house(house_init),
        fence(fence_init)
        {}

    void drawContent(sf::RenderWindow& window, int column, int row)
    {
        if (house != none)
            draw_house(window, house, column, row);

        if (fence != none)
            draw_fence(window, fence, column, row);
    }
};
