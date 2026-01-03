#include <SFML/Graphics.hpp>
#include <iostream>

#include "user_interface/events.hpp"
#include "graphics/draw_grid.hpp"
#include "graphics/draw_cross.hpp"
#include "graphics/draw_circle.hpp"

#include "config.hpp"

#include "board/square.hpp"
#include "board/board.hpp"

Input input;

Square PositionToSquare(sf::Vector2i position)
{
    int column = position.x / cfg::stepsize_x;
    int row = position.y / cfg::stepsize_y;

    return Square(column, row);
}

Square clicked_square(-1, -1);
Board board;

int main()
{

    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play tictactoe!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        processEvents(window, input);              

        if (input.mouseClicked) // if clicked
        {   
            clicked_square = PositionToSquare(sf::Mouse::getPosition(window));
            board.playTurn(clicked_square.column, clicked_square.row);
            input.mouseClicked = false;
        }

        window.clear();
        draw_grid(window);
        
        board.drawContent(window);

        window.display();
    }
}
