#include <BigInt/BigInt.h>

#include <iostream>
#include <vector>

using namespace std;

namespace ACA
{

BigInt::BigInt(const string& s)
{
	digits = s; // No checks at all, risky
	// TODO
}

BigInt::BigInt(unsigned long long nr)
{
	// TODO
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
	// TODO:
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
	// TODO
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
	// TODO
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
	// TODO
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
	// TODO
    return *this;
}

BigInt operator+(BigInt lhs, const BigInt& rhs)
{
	lhs += rhs;
	return lhs;
}

BigInt& BigInt::operator-=(const BigInt& rhs)
{
	// TODO
    return *this;
}

BigInt operator-(BigInt lhs, const BigInt& rhs)
{
	lhs -= rhs;
	return lhs;
}

BigInt& BigInt::operator*=(const BigInt& rhs)
{
	// TODO
    return *this;
}

BigInt operator*(BigInt lhs, const BigInt& rhs)
{
	lhs *= rhs;
	return lhs;
}

BigInt& BigInt::operator/=(const BigInt& rhs)
{
	// TODO
    return *this;
}

BigInt operator/(BigInt lhs, const BigInt& rhs)
{
	lhs /= rhs;
	return lhs;
}

BigInt& BigInt::operator%=(const BigInt& rhs)
{
	// TODO
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