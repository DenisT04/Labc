#include "board.hpp"
#include <gtest/gtest.h>

TEST(BoardTests, TestIsFull) {
    Board board;
    EXPECT_FALSE(board.IsFull());
}

TEST(BoardTests, TestPlaceMarker) {
    Board board;
    Point pos{1, 1};
    board.PlaceMarker(pos, 'X');
    EXPECT_FALSE(board.IsEmpty(pos));
}

TEST(BoardTests, TestCheckWin) {
    Board board;
    board.PlaceMarker({0, 0}, 'X');
    board.PlaceMarker({1, 1}, 'X');
    board.PlaceMarker({2, 2}, 'X');
    EXPECT_TRUE(board.CheckWin('X'));
}
