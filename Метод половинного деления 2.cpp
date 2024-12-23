﻿// Подключение необходимых библиотек 
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
float f(float a, float b, float eps) // Функция для создания уменьшающихся к корню промежутков
{
    float x = (b + a) / 2; // Середина промежутка [a;b]
    if (abs(b - a) / 2 <= eps) // Условие для выхода из рекурсии. Если промежуток меньше константы E = 0.000001, рекурсия прекращается
        return x; // Возвращается приближенный корень 
    else
        if ((0.1 * pow(x, 2) - x * log(x)) * (0.1 * pow(a, 2) - a * log(a)) < 0) {// Условие для сокращения промежутка и перемещения его концов к точкам x
            cout << "Промежуточный корень: " << (x + a) / 2 << endl;
            return f(a, x, eps); // Сужение до промежутка [a;x]
        }
        else {
            cout << "Промежуточный корень: " << (b + x) / 2 << endl;
            return f(x, b, eps); // Сужение до промежутка [x;b]
        }
}
int main()
{
    setlocale(LC_ALL, "RU");
    float a, b, E; // ВЫделение памяти под необходимых переменных
    cout << "Введите координаты концов промежутка [a;b] внутри которого необходимо найти корень уравнения 0.1x^2 - xln(x) = 0: " << endl;
    cin >> a >> b; // Ввод концов первого промежутка [a;b]
    E = 0.000001; // Константа созданная для определения точности корня
    cout << "Приближенный корень уравнения x = " << f(a, b, E); // Вывод корня с учетом точности
    return 0;
}
