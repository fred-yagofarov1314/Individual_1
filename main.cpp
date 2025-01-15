#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main() {
    // Запрос ввода числа от пользователя
    string input;
    cout << "Введите целое число: ";
    cin >> input;

    // Проверка и преобразование ввода
    bool valid;
    long long n = strToNum(input, valid);
    if (!valid) {
        cout << "Неверный ввод.\n";
        return 1; // Завершение программы в случае некорректного ввода
    }

    // Проверка на отрицательные числа
    if (n < 0) {
        cout << "Сумма квадратов для отрицательных чисел не определена.\n";
        return 1;
    }

    // Проверка на минимальное значение n
    if (n >= 0 && n < 20000) {
        cout << "Число должно быть больше или равно 20000.\n";
        return 1;
    }

    // Вычисление суммы квадратов чисел от 1 до n
    string result = "0";
    for (long long i = n; i > 0; i--) {
        // Преобразование текущего числа в строку
        string curStr = numToStr(i);

        // Выравнивание строк по длине, добавляя ведущие нули
        while (result.size() < curStr.size())
            result.insert(result.begin(), '0');
        while (curStr.size() < result.size())
            curStr.insert(curStr.begin(), '0');

        int len = curStr.size();
        int count = (len + 8) / 9;

        // Разбиение текущего числа и результата на блоки
        long long* x = new long long[count + 1]();
        long long* y = new long long[count + 1]();

        splitStrToBlocks(x, curStr, len, count);
        splitStrToBlocks(y, result, len, count);

        // Возведение текущего числа в квадрат и добавление к результату
        multiplyBlocks(x, x, count);
        addBlocks(x, y, count);

        // Сбор нового результата из блоков
        result = buildResult(x, count);

        // Освобождение выделенной памяти
        delete[] x;
        delete[] y;
    }

    // Вывод результата
    cout << "Сумма квадратов чисел от 1 до " << n << " равна: " << result << '\n';
    return 0;
}