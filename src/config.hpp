#pragma once
#include <SFML/Graphics.hpp>

enum color{none = 0, blue = 1, red =-1};

namespace cfg
{

sf::Vector2u constexpr window_size = {1000, 1000};
sf::Vector2i constexpr grid_size = {4, 4};
float constexpr stepsize_x = window_size.x/grid_size.x;
float constexpr stepsize_y = window_size.y/grid_size.y;

int constexpr wincondition = 4;

sf::Vector2f constexpr house_size = {stepsize_x/2, stepsize_y/2};
sf::Vector2f constexpr fence_size = {stepsize_x/1.5, stepsize_y/1.5};

}
