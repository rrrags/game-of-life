#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

/*Convoy's game og life
------------------------
There are four rules for each cell in this game
    1) Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    2) Any live cell with two or three live neighbours lives on to the next generation.
    3) Any live cell with more than three live neighbours dies, as if by overpopulation.
    4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

enum State
{
    ALIVE,
    DEAD
};

struct Point
{
    constexpr Point(std::size_t x, std::size_t y) : x(x), y(y) {}
    const std::size_t x;
    const std::size_t y;
};

template <std::size_t N>
class GOL
{
  public:
    GOL(std::vector<Point> alivePoints)
    {
        for (auto& innerArray : m_grid)
        {
            innerArray.fill(DEAD);
        }
        for (const auto& p : alivePoints)
        {
            m_grid[p.x][p.y] = ALIVE;
        }
    }

    void printGrid() const
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (m_grid[i][j] == ALIVE)
                {
                    std::cout << "ALIVE\n";
                }
                else
                {
                    std::cout << "DEAD\n";
                }
            }
        }
    }

  private:
    std::array<std::array<State, N>, N> m_grid{DEAD};
    std::array<std::array<State, N>, N> m_gridTemp{DEAD};
};