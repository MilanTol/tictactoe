
#include <SFML/Graphics.hpp>

#include "../config.hpp"

void draw_secure(sf::RenderWindow& window, sf::Vector2f position)
{
    sf::CircleShape shape(cfg::circle_radius / 5.0f);

    shape.setFillColor(sf::Color::Red);

    shape.setPosition(position);

    window.draw(shape);
}

void draw_secure(sf::RenderWindow& window, int column, int row)
{
    //compute square size
    float stepsize_x = cfg::window_size.x / (cfg::grid_size.x);
    float stepsize_y = cfg::window_size.y / (cfg::grid_size.y);

    sf::Vector2f position;

    //find the right square
    position.x = column * stepsize_x;
    position.y = row * stepsize_y;

    //add discrepancy size of circle and square size
    position.x += (stepsize_x/2 - cfg::circle_radius/5.0f);
    position.y += (stepsize_y/2 - cfg::circle_radius/5.0f);

    draw_secure(window, position);  
}