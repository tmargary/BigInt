#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool isNumber(const std::string &str)
{
    std::string::const_iterator it = str.begin();

    // Check for optional sign
    if (*it == '+' || *it == '-')
        it++;

    // Check for digits before decimal point
    bool hasDigits = false;
    while (std::isdigit(*it))
    {
        hasDigits = true;
        it++;
    }

    // Check for decimal point
    if (*it == '.')
    {
        it++;

        // Check for digits after decimal point
        while (std::isdigit(*it))
        {
            hasDigits = true;
            it++;
        }
    }

    // Check for exponential part
    if (*it == 'e' || *it == 'E')
    {
        it++;

        // Check for optional sign
        if (*it == '+' || *it == '-')
            it++;

        // Check for digits
        if (!std::isdigit(*it))
            return false;

        while (std::isdigit(*it))
            it++;
    }

    return hasDigits && it == str.end();
}

std::string addBigInt(const std::string &a, const std::string &b)
{
    std::string result;
    int carry = 0;

    int lenA = a.length();
    int lenB = b.length();
    int maxLen = std::max(lenA, lenB);

    for (int i = 0; i < maxLen; i++)
    {
        int d1 = i < lenA ? a[lenA - i - 1] - '0' : 0;
        int d2 = i < lenB ? b[lenB - i - 1] - '0' : 0;
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    if (carry > 0)
    {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string subtractBigInt(const std::string &a, const std::string &b)
{
    std::string result;
    int borrow = 0;

    int lenA = a.length();
    int lenB = b.length();
    int maxLen = std::max(lenA, lenB);

    for (int i = 0; i < maxLen; i++)
    {
        int d1 = i < lenA ? a[lenA - i - 1] - '0' : 0;
        int d2 = i < lenB ? b[lenB - i - 1] - '0' : 0;
        int diff = d1 - d2 - borrow;
        if (diff < 0)
        {
            borrow = 1;
            diff += 10;
        }
        else
        {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }

    while (result.length() > 1 && result.back() == '0')
    {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    return result;
}
