#pragma once
#include <string>

using namespace std;

bool isValidNumber(const string& s);
long long strToNum(const string& s, bool& valid);
string numToStr(long long n);
void splitStrToBlocks(long long* blocks, const string& s, int len, int count);
void multiplyBlocks(long long* a, long long* b, int count);
void addBlocks(long long* a, long long* b, int count);
string buildResult(long long* blocks, int count);

