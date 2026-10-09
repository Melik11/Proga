#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray(int size) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

DynamicArray::DynamicArray(DynamicArray& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

void DynamicArray::print() {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "]" << endl;
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс за границами массива" << endl;
        return;
    }
    if (value < -100 || value > 100) {
        cout << "Ошибка: значение должно быть от -100 до 100" << endl;
        return;
    }
    data[index] = value;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Ошибка: индекс за границами массива" << endl;
        return 0;
    }
    return data[index];
}

void DynamicArray::append(int value) {
    if (value < -100 || value > 100) {
        cout << "Ошибка: значение должно быть от -100 до 100" << endl;
        return;
    }
    int* newData = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    size++;
}

void DynamicArray::add(DynamicArray other) {
    for (int i = 0; i < size; i++) {
        int val = 0;
        if (i < other.size) {
            val = other.data[i];
        }
        data[i] += val;
    }
}

void DynamicArray::subtract(DynamicArray other) {
    for (int i = 0; i < size; i++) {
        int val = 0;
        if (i < other.size) {
            val = other.data[i];
        }
        data[i] -= val;
    }
}