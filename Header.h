#pragma once
#include <string>

using namespace std;

bool isValidNumber(const std::string& s);
long long strToNum(const std::string& s, bool& valid);
string numToStr(long long n);
void splitStrToBlocks(long long* blocks, const std::string& s, int len, int count);
void multiplyBlocks(long long* a, long long* b, int count);
void addBlocks(long long* a, long long* b, int count);
string buildResult(long long* blocks, int count);

