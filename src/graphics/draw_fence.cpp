#include <SFML/Graphics.hpp>

#include "../config.hpp"

void draw_fence(sf::RenderWindow& window, color col, sf::Vector2f position)
{
    sf::RectangleShape fence_shape(cfg::fence_size);
    fence_shape.setPosition(position);

    fence_shape.setFillColor(sf::Color::Black);
    fence_shape.setOutlineThickness(cfg::fence_size.x / 20.0f);

    if (col == blue)
        fence_shape.setOutlineColor(sf::Color::Blue);
    else if (col == red)
        fence_shape.setOutlineColor(sf::Color::Red);

    window.draw(fence_shape);
}

void draw_fence(sf::RenderWindow& window, color col, int column, int row)
{   
    //compute square size
    float stepsize_x = cfg::window_size.x / (cfg::grid_size.x);
    float stepsize_y = cfg::window_size.y / (cfg::grid_size.y);

    sf::Vector2f position;

    //find the right square
    position.x = column * stepsize_x;
    position.y = row * stepsize_y;

    //add discrepancy size of circle and square size
    position.x += (stepsize_x/2 - cfg::fence_size.x);
    position.y += (stepsize_y/2 - cfg::fence_size.y);

    draw_fence(window, col, position);
}


