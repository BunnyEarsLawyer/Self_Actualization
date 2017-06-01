// tests.cpp
#include "source/tic_tac_toe.cpp"
#include <gtest/gtest.h>
 
TEST(PickO, GoodPick) 
{ 
    ASSERT_EQ(" O ", pick_state(1));
}

TEST(PickX, GoodPick) 
{ 
    ASSERT_EQ(" X ", pick_state(2));
}

TEST(PickBlank, GoodPick) 
{ 
    ASSERT_EQ("   ", pick_state(3));
}
 
int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
