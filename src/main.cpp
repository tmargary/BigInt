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

    cout << "first and second are ";
    if (first != second) 
    {
        cout << "not equal!\n";
    } else {
        cout << "equal!\n";
    }

    BigInt fifth = (first + second);
    BigInt sixth = (1 + second);
    BigInt seventh(string("25"));
    seventh %= string("4");


	cout << 
    "first = " << first << endl << 
    "second = " << second << endl << 
    "third = " << third << endl << 
    "forth = " << forth << endl << 
    "fifth = " << fifth << endl << 
    "sixth = " << sixth << endl <<
    "seventh = " << (seventh <= first) << endl << 
    endl;

    return 0;
}

