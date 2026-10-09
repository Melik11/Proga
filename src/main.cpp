#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {
    cout << " Задание 1" << endl;
    DynamicArray arr1(5);
    arr1.set(0, 10);
    arr1.set(1, -50);
    arr1.set(2, 100);
    arr1.set(5, 10);
    arr1.set(0, 150);
    cout << "Массив arr1: ";
    arr1.print();
    cout << "arr1[1] = " << arr1.get(1) << endl;
    cout << "arr1[10] = " << arr1.get(10) << endl;

    cout << "\n Задание 2" << endl;
    DynamicArray arr2 = arr1;
    arr2.set(0, 99);
    cout << "arr1 (не изменился): ";
    arr1.print();
    cout << "arr2 (копия, изменён): ";
    arr2.print();

    cout << "\n Задание 3" << endl;
    arr1.append(20);
    arr1.append(-100);
    arr1.append(101);
    cout << "arr1 после добавления: ";
    arr1.print();

    cout << "\n Задание 4" << endl;
    DynamicArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    DynamicArray b(5);
    b.set(0, 1);
    b.set(1, 2);
    b.set(2, 3);
    b.set(3, 4);
    b.set(4, 5);

    cout << "a до сложения: ";
    a.print();
    cout << "b: ";
    b.print();
    a.add(b);
    cout << "a после сложения с b: ";
    a.print();

    DynamicArray c(2);
    c.set(0, 5);
    c.set(1, 5);
    a.subtract(c);
    cout << "a после вычитания c: ";
    a.print();

    return 0;
}