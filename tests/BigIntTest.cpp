#include <BigInt/BigInt.h>
#include <gtest/gtest.h>

#include <vector>

using namespace ACA;
using namespace std;

TEST(BigInt, Increment) {
    const vector<pair<BigInt, BigInt>> ExpectedActualList = {
        { BigInt("0"), BigInt("1") },
        { BigInt("8"), BigInt("9") },
        { BigInt("9"), BigInt("10") },
        { BigInt("99999"), BigInt("100000") }
    };

    for (auto [num, num_plus_one] : ExpectedActualList) {
        EXPECT_EQ(++num, num_plus_one);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

