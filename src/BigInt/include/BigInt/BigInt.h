#ifndef BIGINT_H
#define BIGINT_H

#include <string>

namespace ACA
{

class BigInt
{

public:
	BigInt(unsigned long long n = 0);
	BigInt(const std::string&);
	BigInt(const BigInt&);

	/* * * * Operator Overloading * * * */

	// assignment
	BigInt& operator=(const BigInt&);
    // assignment: copy and swap idiom (strong exception safety guarantee)
    // BigInt& operator=(BigInt) noexcept;

	//Post/Pre - Incrementation
	BigInt& operator++();
	BigInt operator++(int);
	BigInt& operator--();
	BigInt operator--(int);

	//Comparison operators
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);

	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);

    //Addition and Subtraction
	BigInt& operator+=(const BigInt&);
	friend BigInt operator+(BigInt, const BigInt&);
    BigInt& operator-=(const BigInt&);
	friend BigInt operator-(BigInt, const BigInt&);

	//Multiplication and Division
	BigInt& operator*=(const BigInt&);
	friend BigInt operator*(BigInt, const BigInt&);
	BigInt& operator/=(const BigInt&);
	friend BigInt operator/(BigInt, const BigInt&);

	//Modulo
	BigInt& operator%=(const BigInt&);
	friend BigInt operator%(BigInt, const BigInt&);

	//Power Function
	BigInt& operator^=(const BigInt&);
	friend BigInt operator^(BigInt, const BigInt&);

	std::string toString() const { return digits; }

private:
	std::string digits;

};

//Read and Write
std::ostream& operator<<(std::ostream&, const BigInt&);
std::istream& operator>>(std::istream&, BigInt&);

} // namespace ACA

#endif
