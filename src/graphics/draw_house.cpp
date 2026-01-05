
#include <SFML/Graphics.hpp>

#include "../config.hpp"

void draw_house(sf::RenderWindow& window, color col, sf::Vector2f position)
{
    sf::RectangleShape house_shape(cfg::house_size);
    house_shape.setPosition(position);

    if (col == blue)
        house_shape.setFillColor(sf::Color::Blue);

    else if (col == red)
        house_shape.setFillColor(sf::Color::Red);

    window.draw(house_shape);
}

void draw_house(sf::RenderWindow& window, color col, int column, int row)
{
    //compute square size
    float stepsize_x = cfg::window_size.x / (cfg::grid_size.x);
    float stepsize_y = cfg::window_size.y / (cfg::grid_size.y);

    sf::Vector2f position;

    //find the right square
    position.x = column * stepsize_x;
    position.y = row * stepsize_y;

    //add discrepancy size of circle and square size
    position.x += (stepsize_x/2 - cfg::house_size.x);
    position.y += (stepsize_y/2 - cfg::house_size.y);

    draw_house(window, col, position);  
}