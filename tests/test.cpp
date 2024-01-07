#include <vector>
#include "gtest/gtest.h"
#include "solution.cpp"

using namespace std;


class MyTest : public ::testing::TestWithParam<tuple<vector<int>, int>> {
    // SetUp() and TearDown() methods if needed
};

TEST_P(MyTest, IsPositive) {
    auto p = GetParam();
    ASSERT_EQ(Solution::countFromArr(get<0>(p)), get<1>(p));
}

INSTANTIATE_TEST_SUITE_P(PositiveNumbers, MyTest, ::testing::Values(
        make_tuple(vector<int> {1, 2, 3, 4, 5, 6}, 6),
        make_tuple(vector<int> {}, 0),
        make_tuple(vector<int>{1}, 1)
        ));
