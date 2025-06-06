#include <GOL.hpp>

/*Convoy's game og life (periodic boundary condition)
-----------------------------------------------------
There are four rules for each cell in this game
    1) Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    2) Any live cell with two or three live neighbours lives on to the next generation.
    3) Any live cell with more than three live neighbours dies, as if by overpopulation.
    4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

int main()
{
    constexpr std::size_t N{50};
    std::vector<Point> alivePoints{Point(4, 2), Point(1, 2), Point(3, 1), Point(2, 1), Point(3, 3), Point(2, 3)};
    GOL<N> gameOfLife(alivePoints);
    // gameOfLife.printGrid();
    gameOfLife.start();
    return 0;
}