#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

bool isNumber(const std::string &str);
std::string addBigInt(std::string a, std::string b);
std::string subtractBigInt(std::string a, std::string b);
std::string multiplyBigInt(std::string a, std::string b);
std::string divideBigInt(std::string dividend, std::string divisor);
std::string modBigInt(std::string a, std::string b);
int compareBigInt(const std::string &a, const std::string &b);

#endif