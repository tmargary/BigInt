#include <BigInt/BigInt.h>

#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <string>

using namespace ACA;

int main()
{

    long long a_ = 10, b_ = -45254, c_ = 7575, d_ = 24221;

    std::vector<long long> vec{a_, b_, c_, d_};

    std::string result;
    std::string expected;

    for (auto el1 : vec)
    {
        for (auto el2 : vec)
        {
            result = (BigInt(el1) - BigInt(el2)).toString();
            expected = std::to_string((el1 - el2));
            std::cout <<  el1 << " - " << el2 << " = " << result << " \t\t expected: " << expected << std::endl;
            assert(result == expected);

            result = (BigInt(el1) + BigInt(el2)).toString();
            expected = std::to_string((el1 + el2));
            std::cout <<  el1 << " + " << el2 << " = " << result << " \t\t expected: " << expected << std::endl;
            assert(result == expected);

            result = (BigInt(el1) * BigInt(el2)).toString();
            expected = std::to_string((el1 * el2));
            std::cout <<  el1 << " * " << el2 << " = " << result << " \t\t expected: " << expected << std::endl;
            assert(result == expected);
            
            result = (BigInt(el1) / BigInt(el2)).toString();
            expected = std::to_string((el1 / el2));
            std::cout <<  el1 << " / " << el2 << " = " << result << " \t\t expected: " << expected << std::endl;
            assert(result == expected);
        }
    }

    std::vector<long long> vec2{1, 2, 3, 4};

    for (auto el1 : vec2)
    {
        for (auto el2 : vec2)
        {
            int a = pow(el1, el2);
            result = (BigInt(el1) ^ BigInt(el2)).toString();
            expected = std::to_string(a);
            std::cout <<  el1 << "^" << el2 << " = " << result << " \t\t expected: " << expected << std::endl;
        }
    }

    return 0;
}