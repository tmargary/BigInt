#include <BigInt/BigInt.h>

#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <string>

using namespace ACA;

int main()
{
    std::string result;
    std::string expected;
    
    BigInt a("123456789");
    BigInt b("987654321");

    result = (a * b).toString();
    expected = "121932631112635269";

    if(result==expected){
        std::cout << "Success!" << std::endl;
    }

    /* std::vector<long long> vec{10, -45254, 7575, 24221};

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
    } */

    return 0;
}