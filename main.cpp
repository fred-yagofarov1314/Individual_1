#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main() {
    string input;

    cout << "������� ����� �����: ";

    cin >> input;

    bool valid;
    long long n = strToNum(input, valid);

    if (!valid) {
        cout << "�������� ����.\n";
        return 1;
    }

    string result = "0";

    if (n < 0) {
        cout << "����� ��������� ��� ������������� ����� �� ����������.\n";
        return 1;
    }

    if (n >= 0 && n < 20000) {
        cout << "����� ������ ���� ������ ��� ����� 20000.\n";
        return 1;
    }

    for (long long i = n; i > 0; i--) {
        string curStr = numToStr(i);
        while (result.size() < curStr.size())
            result.insert(result.begin(), '0');
        while (curStr.size() < result.size())
            curStr.insert(curStr.begin(), '0');

        int len = curStr.size();
        int count = (len + 8) / 9;

        long long* x = new long long[count + 1]();
        long long* y = new long long[count + 1]();

        splitStrToBlocks(x, curStr, len, count);
        splitStrToBlocks(y, result, len, count);

        multiplyBlocks(x, x, count);
        addBlocks(x, y, count);

        result = buildResult(x, count);

        delete[] x;
        delete[] y;
    }

    cout << "����� ��������� ����� �� 1 �� " << n << " �����: " << result << '\n';
    return 0;
}
