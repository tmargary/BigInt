#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

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

int compareBigInt(const std::string &a, const std::string &b) {
  if (a.length() < b.length()) return -1;
  if (a.length() > b.length()) return 1;
  for (int i = 0; i < a.length(); ++i) {
    if (a[i] < b[i]) return -1;
    if (a[i] > b[i]) return 1;
  }
  return 0;
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

std::string multiplyBigInt(const std::string &a, const std::string &b)
{
  std::vector<int> result(a.size() + b.size(), 0);

  for (int i = a.size() - 1; i >= 0; i--)
  {
    for (int j = b.size() - 1; j >= 0; j--)
    {
      int a_digit = a[i] - '0';
      int b_digit = b[j] - '0';
      result[i + j + 1] += a_digit * b_digit;
      result[i + j] += result[i + j + 1] / 10;
      result[i + j + 1] %= 10;
    }
  }

  int non_zero = 0;
  while (non_zero < result.size() - 1 && result[non_zero] == 0)
  {
    non_zero++;
  }

  std::string str;
  for (int i = non_zero; i < result.size(); i++)
  {
    str += (char)(result[i] + '0');
  }

  return str;
}

std::string divideBigInt(std::string dividend, std::string divisor) {
    int n = dividend.size(), m = divisor.size();
    if (n < m) return "0";
    int sign = ((dividend[0] == '-' && divisor[0] == '-') || (dividend[0] != '-' && divisor[0] != '-')) ? 1 : -1;
    if (dividend[0] == '-') dividend = dividend.substr(1);
    if (divisor[0] == '-') divisor = divisor.substr(1);
    int count = 0;
    while (compareBigInt(dividend, divisor) >= 0) {
        count++;
        dividend = subtractBigInt(dividend, divisor);
    }
    std::string quotient = std::to_string(count);
    if (sign == -1) quotient = "-" + quotient;
    return quotient;
}



std::string modBigInt(std::string a, std::string b)
{
  std::string quotient = divideBigInt(a, b);
  return subtractBigInt(a, multiplyBigInt(quotient, b));
}

