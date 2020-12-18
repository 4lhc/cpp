#include "squareroot.h"
#include <gtest/gtest.h>

TEST(SquareRootTest, PositiveNos) {
    ASSERT_EQ(6, squareRt(36.0));
    ASSERT_EQ(21, squareRt(441.0));
    ASSERT_EQ(134, squareRt(17956.0));
    ASSERT_EQ(0, squareRt(0.0));
}


TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRt(-15.0));
    ASSERT_EQ(-1.0, squareRt(-0.2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
