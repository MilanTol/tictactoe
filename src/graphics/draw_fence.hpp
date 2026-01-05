#pragma once

#include <SFML/Graphics.hpp>

#include "../config.hpp"

enum color{none = 0, blue = 1, red =-1};

void draw_fence(sf::RenderWindow& window, color, sf::Vector2f position);
void draw_fence(sf::RenderWindow& window, color, int, int);