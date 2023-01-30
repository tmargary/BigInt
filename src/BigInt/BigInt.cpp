#include <BigInt/BigInt.h>

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

#include <utils.h>

namespace ACA
{

BigInt::BigInt(const string& s)
{
	if (!(isNumber(s))){
		throw std::runtime_error("Input must be a number.");
	} else {
		digits = s;
	}
}

BigInt::BigInt(unsigned long long nr)
{
	digits = std::to_string(nr);
}

BigInt::BigInt(const BigInt& other)
{
	digits = other.digits;
}

BigInt& BigInt::operator=(const BigInt& other)
{
    // Guard self assignment
    if (this == &other)
    {
        return *this;
    }
	digits = other.digits;
    return *this;
}

/*
BigInt& BigInt::operator=(BigInt other) noexcept
{
    // exchange resources between *this and other
    std::swap(digits, other.digits);
    return *this;
}
*/

bool operator==(const BigInt& lhs, const BigInt& rhs)
{
    return lhs.digits == rhs.digits;
}

bool operator!=(const BigInt& lhs, const BigInt& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const BigInt& lhs, const BigInt& rhs)
{
	int n = lhs.digits.size(), m = rhs.digits.size();
    if(n != m)
        return n < m;
    while(n--)
        if(lhs.digits[n] != rhs.digits[n])
            return lhs.digits[n] < rhs.digits[n];
    return true;
}

bool operator>(const BigInt& lhs, const BigInt& rhs)
{
	return rhs < lhs;
}

bool operator>=(const BigInt& lhs, const BigInt& rhs)
{
	return !(lhs < rhs);
}

bool operator<=(const BigInt& lhs, const BigInt& rhs)
{
	return !(lhs > rhs);
}

BigInt& BigInt::operator++()
{
	digits = addBigInt(digits, string("1"));
    return *this;
}

BigInt BigInt::operator++(int /* tmp */)
{
	BigInt old = *this;
	operator++(); // prefix increment
	return old;
}

BigInt& BigInt::operator--()
{
	digits = addBigInt(digits, string("1"));
    return *this;
}

BigInt BigInt::operator--(int /* tmp */)
{
	BigInt old = *this;
	operator--(); // prefix decrement
	return old;
}

BigInt& BigInt::operator+=(const BigInt& rhs)
{
	string other = rhs.toString();
	digits = addBigInt(digits, other);
    return *this;
}

BigInt operator+(BigInt lhs, const BigInt& rhs)
{
	lhs += rhs;
	return lhs;
}

BigInt& BigInt::operator-=(const BigInt& rhs)
{
	string other = rhs.toString();
	digits = subtractBigInt(digits, other);
    return *this;
}

BigInt operator-(BigInt lhs, const BigInt& rhs)
{
	lhs -= rhs;
	return lhs;
}

BigInt& BigInt::operator*=(const BigInt& rhs)
{
	digits = multiplyBigInt(digits, rhs.digits);
    return *this;
}

BigInt operator*(BigInt lhs, const BigInt& rhs)
{
	lhs *= rhs;
	return lhs;
}

BigInt& BigInt::operator/=(const BigInt& rhs)
{
	digits = divideBigInt(digits, rhs.digits);
    return *this;
}

BigInt operator/(BigInt lhs, const BigInt& rhs)
{
	lhs /= rhs;
	return lhs;
}

BigInt& BigInt::operator%=(const BigInt& rhs)
{
	digits = modBigInt(digits, rhs.digits);
    return *this;
}

BigInt operator%(BigInt lhs, const BigInt& rhs)
{
	lhs %= rhs;
	return lhs;
}

BigInt& BigInt::operator^=(const BigInt& rhs)
{
	// TODO
    return *this;
}

BigInt operator^(BigInt lhs, const BigInt& rhs)
{
	lhs ^= rhs;
	return lhs;
}

istream& operator>>(istream& in, BigInt& a)
{
    // TODO
    return in;
}

ostream& operator<<(ostream& out, const BigInt& a)
{
	out << a.toString();
    return out;
}

} // namespace ACA