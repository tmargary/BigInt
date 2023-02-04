#include <BigInt/BigInt.h>
#include <gtest/gtest.h>
#include <cmath>
#include <vector>

using namespace ACA;
using namespace std;

TEST(BigInt, IsNumber)
{
    EXPECT_THROW({BigInt("123a");}, std::runtime_error);
    EXPECT_THROW({BigInt("0123");}, std::runtime_error);
}

TEST(BigInt, Increment)
{
    const vector<pair<BigInt, BigInt>> ExpectedActualList = {
        {BigInt("0"), BigInt("1")},
        {BigInt("8"), BigInt("9")},
        {BigInt("9"), BigInt("10")},
        {BigInt("99999"), BigInt("100000")}};

    for (auto [num, num_plus_one] : ExpectedActualList)
    {
        EXPECT_EQ(++num, num_plus_one);
    }
}

TEST(BigInt, Decrement)
{
    const vector<pair<BigInt, BigInt>> ExpectedActualList = {
        {BigInt("0"), BigInt("-1")},
        {BigInt("8"), BigInt("7")},
        {BigInt("9"), BigInt("8")},
        {BigInt("100000"), BigInt("99999")}};

    for (auto [num, num_minus_one] : ExpectedActualList)
    {
        EXPECT_EQ(--num, num_minus_one);
    }
}

TEST(BigInt, Addition)
{

    std::vector<long long> vec{12345, -54321, 0, 24221, 1, -1};

    std::string result;
    std::string expected;

    for (auto el1 : vec)
    {
        for (auto el2 : vec)
        {
            result = (BigInt(el1) - BigInt(el2)).toString();
            expected = std::to_string((el1 - el2));
            EXPECT_EQ(result, expected);
        }
    }
}

TEST(BigInt, Subtraction)
{

    std::vector<long long> vec{12345, -54321, 0, 24221, 1, -1};

    std::string result;
    std::string expected;

    for (auto el1 : vec)
    {
        for (auto el2 : vec)
        {
            result = (BigInt(el1) - BigInt(el2)).toString();
            expected = std::to_string((el1 - el2));
            EXPECT_EQ(result, expected);
        }
    }
}

TEST(BigInt, Multiplication)
{

    std::vector<long long> vec{12345, -54321, 0, 24221, 1, -1};

    std::string result;
    std::string expected;

    for (auto el1 : vec)
    {
        for (auto el2 : vec)
        {
            result = (BigInt(el1) * BigInt(el2)).toString();
            expected = std::to_string((el1 * el2));
            EXPECT_EQ(result, expected);
        }
    }
}

TEST(BigInt, Division)
{

    std::vector<long long> vec{12345, -54321, 24221, 1, -1};

    std::string result;
    std::string expected;

    for (auto el1 : vec)
    {
        for (auto el2 : vec)
        {
            result = (BigInt(el1) / BigInt(el2)).toString();
            expected = std::to_string((el1 / el2));
            EXPECT_EQ(result, expected);
        }
    }

    // expect exception when division with 0
    EXPECT_THROW({BigInt(12345) / BigInt(0);}, std::runtime_error);

}

TEST(BigInt, Mod)
{

    std::vector<long long> vec{12345, -54321, 24221, 1, -1};

    std::string result;
    std::string expected;

    for (auto el1 : vec)
    {
        for (auto el2 : vec)
        {
            result = (BigInt(el1) % BigInt(el2)).toString();
            expected = std::to_string((el1 % el2));
            EXPECT_EQ(result, expected);
        }
    }

    // expect exception when division with 0
    EXPECT_THROW({BigInt(12345) / BigInt(0);}, std::runtime_error);

}

TEST(BigInt, Exp)
{
    
    std::vector<long long> vec{1, 2, 3, 4};

    std::string result;
    std::string expected;

    for (auto el1 : vec)
    {
        for (auto el2 : vec)
        {
            int a = pow(el1, el2);
            result = (BigInt(el1) ^ BigInt(el2)).toString();
            expected = std::to_string(a);
            EXPECT_EQ(result, expected);
        }
    }

}

TEST(BigInt, ConstructorString)
{
    BigInt first("12345");
    EXPECT_EQ(first.toString(), std::string("12345"));
}

TEST(BigInt, ConstructorBigInt)
{
    BigInt first(string("12345"));
    BigInt second(first);
    EXPECT_EQ(first.toString(), second.toString());
}

TEST(BigInt, ConstructorLongLong)
{
    BigInt first(12345);
    EXPECT_EQ(first.toString(), "12345");
}

TEST(BigInt, OpAsgm)
{
    BigInt first(string("12345"));
    BigInt second = first;
    EXPECT_EQ(first.toString(), second.toString());
}

TEST(BigInt, OpCmpr)
{
    BigInt first(string("12345"));
    BigInt second(12345);
    EXPECT_EQ(first, second);
}

TEST(BigInt, OpSmaller)
{
    BigInt first(string("12344"));
    BigInt second(12345);
    EXPECT_GT(second, first);
}

TEST(BigInt, OpGreater)
{
    BigInt first(string("12345"));
    BigInt second(12344);
    EXPECT_GT(first, second);
}

TEST(BigInt, OpSmallOrEq)
{
    BigInt first(string("12345"));
    BigInt second(12345);

    EXPECT_TRUE(first <= first);
}

TEST(BigInt, OpGreaterOrEq)
{
    BigInt first(string("12345"));
    BigInt second(12345);

    EXPECT_TRUE(first >= first);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
