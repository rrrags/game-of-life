#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

/*Convoy's game og life (periodic boundary condition)
-----------------------------------------------------
There are four rules for each cell in this game
    1) Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    2) Any live cell with two or three live neighbours lives on to the next generation.
    3) Any live cell with more than three live neighbours dies, as if by overpopulation.
    4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

enum State
{
    DEAD = 0,
    ALIVE
};

struct Point
{
    constexpr Point(std::size_t x, std::size_t y) : x(x), y(y) {}
    std::size_t x;
    std::size_t y;
};

template <std::size_t N>
class GOL
{
  public:
    GOL(const std::vector<Point>& pointsToAliveCells)
    {
        for (const auto& p : pointsToAliveCells)
        {
            m_grid[p.x][p.y] = ALIVE;
        }
        m_gridTemp = m_grid;
    }

    void start()
    {
        printStateOfGrid();
        while (getNumberOfAliveCells() > 0)
        {
            m_gridTemp = m_grid;
            for (std::size_t i = 0; i < N; ++i)
            {
                for (std::size_t j = 0; j < N; ++j)
                {
                    std::size_t aliveNeighbours = getNumberOfAliveNeighbours(i, j);
                    applyRulesToTempGrid(aliveNeighbours, i, j);
                }
            }
            m_grid = m_gridTemp;
            printStateOfGrid();
        }
    }

    void printGrid() const
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            for (std::size_t j = 0; j < N; ++j)
            {
                if (m_grid.at(i).at(j) == ALIVE)
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

    std::size_t getNumberOfAliveNeighbours(std::size_t i, std::size_t j) const
    {
        // modulus operator
        auto modN = [](int dividend) { return (dividend % static_cast<int>(N) + N) % N; };

        // periodic boundary
        std::size_t aliveNeighbours{0};
        if (m_grid.at(modN(i + 1)).at(j) == ALIVE) aliveNeighbours += 1;            // lower neighbour
        if (m_grid.at(modN(i - 1)).at(j) == ALIVE) aliveNeighbours += 1;            // upper neighbour
        if (m_grid.at(i).at(modN(j + 1)) == ALIVE) aliveNeighbours += 1;            // right neighbour
        if (m_grid.at(i).at(modN(j - 1)) == ALIVE) aliveNeighbours += 1;            // left neighbour
        if (m_grid.at(modN(i - 1)).at(modN(j + 1)) == ALIVE) aliveNeighbours += 1;  // upper right neighbour
        if (m_grid.at(modN(i + 1)).at(modN(j + 1)) == ALIVE) aliveNeighbours += 1;  // lower right neighbour
        if (m_grid.at(modN(i - 1)).at(modN(j - 1)) == ALIVE) aliveNeighbours += 1;  // upper left neighbour
        if (m_grid.at(modN(i + 1)).at(modN(j - 1)) == ALIVE) aliveNeighbours += 1;  // lower left neighbour
        return aliveNeighbours;
    }

    void applyRulesToTempGrid(std::size_t aliveNeighbours, std::size_t i, std::size_t j)
    {
        if (m_grid.at(i).at(j) == ALIVE)
        {
            if (aliveNeighbours < 2 || aliveNeighbours > 3) m_gridTemp.at(i).at(j) = DEAD;  // rule 1,2 and 3
        }
        else
        {
            if (aliveNeighbours == 3) m_gridTemp.at(i).at(j) = ALIVE;  // rule 4
        }
    }

    std::size_t getNumberOfAliveCells() const
    {
        std::size_t count{0};
        for (const auto& row : m_grid)
        {
            count += std::count(row.begin(), row.end(), ALIVE);
        }
        return count;
    }

    void printStateOfGrid()
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            for (std::size_t j = 0; j < N; ++j)
            {
                switch (m_grid.at(i).at(j))
                {
                    case DEAD: {
                        std::cout << "-";
                        break;
                    }
                    case ALIVE: {
                        std::cout << "+";
                        break;
                    }
                }
                if (j == N - 1)
                {
                    std::cout << "\n";
                }
            }
        }
        std::cout << "\n";
    }

    std::array<std::array<State, N>, N> getTempGrid() { return m_gridTemp; }

  private:
    std::array<std::array<State, N>, N> m_grid{};
    std::array<std::array<State, N>, N> m_gridTemp{};
};