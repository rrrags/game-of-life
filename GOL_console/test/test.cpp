#include <gtest/gtest.h>

#include <cstddef>

#include "GOL.hpp"

TEST(test, testgetNumberOfAliveNeighbours)
{
    // five test cases. Test for each corner plus in the middle
    constexpr std::size_t N{10};
    std::vector<Point> alivePoints1{Point(0, 0), Point(9, 9)};  // test for upper right and lower left corner
    std::vector<Point> alivePoints2{Point(0, 9), Point(9, 0)};  // test for upper left and lower right corner
    std::vector<Point> alivePoints3{Point(5, 6), Point(5, 4), Point(6, 5), Point(4, 5),
                                    Point(6, 6), Point(6, 4), Point(4, 4), Point(4, 6)};  // test for middle

    GOL<N> gameOfLife1(alivePoints1);  // test for upper right and lower left corner
    GOL<N> gameOfLife2(alivePoints2);  // test for upper left and lower right corner
    GOL<N> gameOfLife3(alivePoints3);  // test for middle

    EXPECT_EQ(gameOfLife1.getNumberOfAliveNeighbours(0, 9), 2)
        << "counted wrong number of neighbours for upper right corner\n";
    EXPECT_EQ(gameOfLife1.getNumberOfAliveNeighbours(9, 0), 2)
        << "counted wrong number of neighbours lower left corner\n";
    EXPECT_EQ(gameOfLife2.getNumberOfAliveNeighbours(9, 9), 2)
        << "counted wrong number of neighbours for lower right corner\n";
    EXPECT_EQ(gameOfLife2.getNumberOfAliveNeighbours(0, 0), 2) << "counted wrong number of neighbours for upper left\n";
    EXPECT_EQ(gameOfLife3.getNumberOfAliveNeighbours(5, 5), 8) << "counted wrong number of neighbours for middle\n";
}

TEST(test, testApplyRulesToTempGrid)
{
    // test all four rules. We make a 10x10 grid and make a T-shape of alive points
    constexpr std::size_t N{10};
    std::vector<Point> alivePoints{Point(5, 5), Point(5, 6), Point(5, 4), Point(6, 5), Point(7, 5)};
    GOL<N> gameOfLife(alivePoints);
    std::size_t aliveNeighbours1{1};  // alive neighbours for point(7,5). should die due to rule 1
    std::size_t aliveNeighbours2{3};  // alive neighbours for point(5,5). should live due to rule 2
    std::size_t aliveNeighbours3{4};  // alive neighbours for point(6,5). should die due to rule 3
    std::size_t aliveNeighbours4{3};  // alive neighbours for point(4,5). should ressurect due to rule 4

    gameOfLife.applyRulesToTempGrid(aliveNeighbours1, 7, 5);
    gameOfLife.applyRulesToTempGrid(aliveNeighbours2, 5, 5);
    gameOfLife.applyRulesToTempGrid(aliveNeighbours3, 6, 5);
    gameOfLife.applyRulesToTempGrid(aliveNeighbours4, 4, 5);

    std::array<std::array<State, N>, N> grid = gameOfLife.getTempGrid();

    EXPECT_EQ(grid.at(7).at(5), DEAD) << "test case for rule 1 failed";
    EXPECT_EQ(grid.at(5).at(5), ALIVE) << "test case for rule 2 failed";
    EXPECT_EQ(grid.at(6).at(5), DEAD) << "test case for rule 3 failed";
    EXPECT_EQ(grid.at(4).at(5), ALIVE) << "test case for rule 4 failed";
}

TEST(test, testGetNumberOfAliveCells)
{
    // test all four rules. We make a 10x10 grid and make a T-shape of alive points
    constexpr std::size_t N{10};
    std::vector<Point> alivePoints{Point(5, 5), Point(5, 6), Point(5, 4), Point(6, 5), Point(7, 5)};
    GOL<N> gameOfLife(alivePoints);
    std::size_t count = gameOfLife.getNumberOfAliveCells();
    EXPECT_EQ(count, 5) << "counted wrong";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS(); 
}
