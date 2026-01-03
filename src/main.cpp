#include <SFML/Graphics.hpp>

#include "user_interface/events.hpp"
#include "graphics/draw_grid.hpp"
#include "graphics/draw_cross.hpp"
#include "graphics/draw_circle.hpp"

#include "config.hpp"

#include "board/square.hpp"


Input input;

Square PositionToSquare(sf::Vector2i position)
{
    int column = position.x / cfg::grid_size.x;
    int row = position.y / cfg::grid_size.y;

    return Square(column, row);
}

Square clicked_square(-1, -1);

int main()
{
    Square square(1, 2);
    square.setCircle();

    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play tictactoe!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        processEvents(window, input);              

        if (input.mouseClicked) // if clicked
        {   
            clicked_square = PositionToSquare(sf::Mouse::getPosition(window));
        }

        window.clear();
        draw_grid(window);
        
        square.drawContent(window);

        window.display();
    }
}
