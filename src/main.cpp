#include <SFML/Graphics.hpp>
#include <iostream>

#include "user_interface/events.hpp"
#include "graphics/draw_grid.hpp"
#include "graphics/draw_house.hpp"
#include "graphics/draw_fence.hpp"

#include "config.hpp"
#include "columnrow.hpp"

#include "board/square.hpp"
#include "board/board.hpp"

Input input;

ColumnRow PositionToRowColumn(sf::Vector2i position)
{
    int column = position.x / cfg::stepsize_x;
    int row = position.y / cfg::stepsize_y;

    return ColumnRow(column, row);
}

ColumnRow clicked_square(-1, -1);

int main()
{   
    std::vector<Board> boards;
    boards.push_back(Board());
    int turns = 0;
    int board_id = 0;

    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play tictactoe!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        processEvents(window, input);              

        Board current_board = boards[board_id];

        if (input.mouseClicked and not (board_id == turns))
        {
            input.mouseClicked = false;
            board_id = turns;
        }

        else if (input.mouseClicked and board_id == turns) // if clicked
        {   
            clicked_square = PositionToRowColumn(sf::Mouse::getPosition(window));
            current_board.playTurn(clicked_square.column, clicked_square.row);
            boards.push_back(current_board);
            turns += 1;
            board_id = turns;
            input.mouseClicked = false;
        }

        if (input.down_pressed and turns > 0)
        {   
            input.down_pressed = false;

            current_board = boards[turns - 1];
            boards.pop_back();

            turns -= 1;
            board_id = turns;
        }

        if (input.left_pressed and board_id > 0)
        {   
            input.left_pressed = false;

            board_id -= 1;
            current_board = boards[board_id];
        }

        if (input.right_pressed and board_id < turns)
        {    
            input.right_pressed = false;

            board_id += 1;
            current_board = boards[board_id];
        }

        window.clear();
        draw_grid(window);
        
        current_board.drawContent(window);

        window.display();
    }
}
