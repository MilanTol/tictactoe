#include <SFML/Graphics.hpp>

#include "draw_line.hpp"
#include "../config.hpp"

void draw_cross(sf::RenderWindow& window, sf::Vector2f position)
{
    draw_line(
        window, 
        position + sf::Vector2f(-cfg::cross_radius, -cfg::cross_radius), 
        position + sf::Vector2f(+cfg::cross_radius, +cfg::cross_radius)
    );
    
    draw_line(
        window,
        position + sf::Vector2f(+cfg::cross_radius, -cfg::cross_radius),
        position + sf::Vector2f(-cfg::cross_radius, +cfg::cross_radius)
    );
}

void draw_cross(sf::RenderWindow& window, int column, int row)
{
    //compute square size
    float stepsize_x = cfg::window_size.x / (cfg::grid_size.x);
    float stepsize_y = cfg::window_size.y / (cfg::grid_size.y);

    sf::Vector2f position;

    position.x = column * stepsize_x;
    position.y = row * stepsize_y;

    position.x += stepsize_x/2;
    position.y += stepsize_y/2;

    draw_cross(window, position);
}


