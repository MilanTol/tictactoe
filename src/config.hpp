#pragma once
#include <SFML/Graphics.hpp>

namespace cfg
{

sf::Vector2u constexpr window_size = {1000, 1000};
sf::Vector2i constexpr grid_size = {3, 3};
float constexpr stepsize_x = window_size.x/grid_size.x;
float constexpr stepsize_y = window_size.y/grid_size.y;

float constexpr cross_radius = 100;
float constexpr circle_radius = 100;

}
