#include <BigInt/BigInt.h>

#include <iostream>

using namespace ACA;
using namespace std;

int main()
{
	BigInt first(string("12345"));
    BigInt second(12934);

    BigInt third(second);
    BigInt forth = third;

    second = first;

    if (first != second) 
    {
        // cout
    }

    BigInt fifth = (first + second);
    BigInt sixth = (1 + second);


	cout << "first = " << first << " second = " << second 
    << " third = " << third << " forth = " << forth 
    << " fifth = " << fifth << " sixth = " << sixth;

    return 0;
}

