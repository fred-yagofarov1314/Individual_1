#include "Header.h"

using namespace std;

bool isValidNumber(const string& s) {
    if (s.empty()) return false;
    int start = 0;
    if (s[0] == '-') {
        if (s.size() == 1) return false;
        start = 1;
    }
    for (int i = start; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

long long strToNum(const string& s, bool& valid) {
    long long res = 0;
    valid = isValidNumber(s);
    if (!valid) return 0;

    bool neg = (s[0] == '-');
    int start = neg ? 1 : 0;
    for (int i = start; i < s.size(); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return neg ? -res : res;
}

string numToStr(long long n) {
    if (n == 0) return "0";
    string res;
    bool neg = n < 0;
    if (neg) n = -n;
    while (n) {
        res.insert(res.begin(), '0' + (n % 10));
        n /= 10;
    }
    if (neg) res.insert(res.begin(), '-');
    return res;
}

void splitStrToBlocks(long long* blocks, const string& s, int len, int count) {
    int pos = len - 9;
    for (int i = 0; i < count; i++) {
        int start = pos >= 0 ? pos : 0;
        int length;
        if (pos >= 0) {
            length = 9;
        }
        else {
            length = 9 + pos;
        }
        if (length > 0) {
            bool valid;
            blocks[i] = strToNum(s.substr(start, length), valid);
        }
        else {
            blocks[i] = 0;
        }
        pos -= 9;
    }
}

void multiplyBlocks(long long* a, long long* b, int count) {
    long long carry = 0;
    for (int i = 0; i < count; i++) {
        long long prod = a[i] * b[i] + carry;
        carry = prod / 1000000000;
        a[i] = prod % 1000000000;
    }
    if (carry > 0) {
        a[count] = carry;
    }
}

void addBlocks(long long* a, long long* b, int count) {
    long long carry = 0;
    for (int i = 0; i < count; i++) {
        long long sum = a[i] + b[i] + carry;
        carry = sum / 1000000000;
        a[i] = sum % 1000000000;
    }
    if (carry > 0) {
        a[count] += carry;
    }
}

string buildResult(long long* blocks, int count) {
    string res;
    bool leading = true;
    for (int i = count; i >= 0; i--) {
        string block = numToStr(blocks[i]);
        if (leading && blocks[i] == 0) continue;
        if (leading) {
            res += block;
            leading = false;
        }
        else {
            while (block.size() < 9) block.insert(block.begin(), '0');
            res += block;
        }
    }
    return res.empty() ? "0" : res;
}
