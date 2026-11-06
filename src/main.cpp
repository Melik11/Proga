#include <iostream>
#include <stdexcept>
#include <new>
#include <string>
#include "DynamicArray.h"

using namespace std;

int main() {
    cout << " Задание 1" << endl;
    DynamicArray<int> arr1(5);
    arr1.set(0, 10);
    arr1.set(1, -50);
    arr1.set(2, 100);
    try {
        arr1.set(5, 10);
    } catch (const out_of_range& e) {
        cout << "out_of_range: " << e.what() << endl;
    }
    try {
        arr1.set(0, 150);
    } catch (const invalid_argument& e) {
        cout << "invalid_argument: " << e.what() << endl;
    }
    cout << "Массив arr1: " << arr1 << endl;
    cout << "arr1[1] = " << arr1.get(1) << endl;
    try {
        cout << "arr1[10] = " << arr1.get(10) << endl;
    } catch (const out_of_range& e) {
        cout << "out_of_range (get): " << e.what() << endl;
    }

    cout << "\n Задание 2" << endl;
    DynamicArray<int> arr2 = arr1;
    arr2.set(0, 99);
    cout << "arr1 (не изменился): " << arr1 << endl;
    cout << "arr2 (копия, изменён): " << arr2 << endl;

    cout << "\n Задание 3" << endl;
    arr1.append(20);
    arr1.append(-100);
    try {
        arr1.append(101);
    } catch (const invalid_argument& e) {
        cout << "invalid_argument (append): " << e.what() << endl;
    }
    cout << "arr1 после добавления: " << arr1 << endl;

    cout << "\n Задание 4" << endl;
    DynamicArray<int> a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    DynamicArray<int> b(5);
    b.set(0, 1);
    b.set(1, 2);
    b.set(2, 3);
    b.set(3, 4);
    b.set(4, 5);

    cout << "a до сложения: " << a << endl;
    cout << "b: " << b << endl;
    a.add(b);
    cout << "a после сложения с b: " << a << endl;

    DynamicArray<int> c(2);
    c.set(0, 5);
    c.set(1, 5);
    a.subtract(c);
    cout << "a после вычитания c: " << a << endl;

    cout << "\n bad_alloc" << endl;
    try {
        DynamicArray<int> huge(1000000000);
        cout << "Память выделилась" << endl;
    } catch (const bad_alloc&) {
        cout << "Поймали bad_alloc" << endl;
    }

    cout << "\n Часть 3: Шаблоны (double и string)" << endl;
    DynamicArray<double> arrDouble1(3);
    arrDouble1.set(0, 1.5);
    arrDouble1.set(1, 2.5);
    arrDouble1.set(2, 3.5);
    cout << "arrDouble1: " << arrDouble1 << endl;

    DynamicArray<double> arrDouble2(3);
    arrDouble2.set(0, 1.0);
    arrDouble2.set(1, 2.0);
    arrDouble2.set(2, 3.0);
    cout << "arrDouble2: " << arrDouble2 << endl;
    cout << "Расстояние: " << arrDouble1.distance(arrDouble2) << endl;

    DynamicArray<string> arrStr(2);
    arrStr.set(0, "Hello");
    arrStr.set(1, "World");
    cout << "arrStr: " << arrStr << endl;
    try {
        arrStr.distance(arrStr);
    } catch (const bad_typeid&) {
        cout << "Поймали bad_typeid" << endl;
    }

    return 0;
}