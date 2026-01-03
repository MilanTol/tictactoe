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

int main()
{   
    std::vector<Board> boards;
    boards.push_back(Board());
    int turns = 0;

    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play tictactoe!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        processEvents(window, input);              

        Board current_board = boards[turns];
        if (input.mouseClicked) // if clicked
        {   
            clicked_square = PositionToSquare(sf::Mouse::getPosition(window));
            current_board.playTurn(clicked_square.column, clicked_square.row);
            boards.push_back(current_board);
            turns += 1;
            input.mouseClicked = false;
        }

        if (input.u_pressed and turns > 0)
        {   
            input.u_pressed = false;

            std::cout << "check" << std::endl;
            current_board = boards[turns - 1];
            boards.pop_back();
            
            turns -= 1;
        }

        window.clear();
        draw_grid(window);
        
        current_board.drawContent(window);

        window.display();
    }
}
