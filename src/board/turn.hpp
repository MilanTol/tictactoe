#pragma once

struct Turn
{
    enum Side
    {
        cross = 1,
        circle = 2,
    };

    int turn = circle;
    int move_counter = 1;

    bool forCross()
    {
        return (turn == cross);
    }

    bool forCircle()
    {
        return (turn == circle);
    }

    void end()
    {
        if (turn == circle)
            turn = cross;

        else if (turn == cross)
            turn = circle;

        move_counter = 0;
    }

    void count_move()
    {
        move_counter += 1;
    }
    void uncount_move()
    {
        if (move_counter > 0)
            move_counter -= 1;
    }

};