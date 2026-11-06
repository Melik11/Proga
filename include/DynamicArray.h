#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <typeinfo>
#include <type_traits>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

public:
    DynamicArray(int size);
    ~DynamicArray();
    DynamicArray(const DynamicArray<T>& other);

    void set(int index, T value);
    T get(int index) const;
    int getSize() const { return size; }
    void append(T value);
    void add(const DynamicArray<T>& other);
    void subtract(const DynamicArray<T>& other);
    
    double distance(const DynamicArray<T>& other) const;
};

template <typename T>
DynamicArray<T>::DynamicArray(int size) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = T();
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    size = other.size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
void DynamicArray<T>::set(int index, T value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне границ");
    }
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Значение вне диапазона [-100; 100]");
        }
    }
    data[index] = value;
}

template <typename T>
T DynamicArray<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс вне границ");
    }
    return data[index];
}

template <typename T>
void DynamicArray<T>::append(T value) {
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100) {
            throw std::invalid_argument("Значение вне диапазона [-100; 100]");
        }
    }
    T* newData = new T[size + 1];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    size++;
}

template <typename T>
void DynamicArray<T>::add(const DynamicArray<T>& other) {
    for (int i = 0; i < size; i++) {
        T val = T();
        if (i < other.size) {
            val = other.data[i];
        }
        data[i] += val;
    }
}

template <typename T>
void DynamicArray<T>::subtract(const DynamicArray<T>& other) {
    for (int i = 0; i < size; i++) {
        T val = T();
        if (i < other.size) {
            val = other.data[i];
        }
        data[i] -= val;
    }
}

template <typename T>
double DynamicArray<T>::distance(const DynamicArray<T>& other) const {
    if constexpr (!std::is_arithmetic_v<T>) {
        throw std::bad_typeid();
    } else {
        if (size != other.size) {
            throw std::invalid_argument("Размеры массивов не совпадают");
        }
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += (data[i] - other.data[i]) * (data[i] - other.data[i]);
        }
        return std::sqrt(sum);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
    os << "[ ";
    for (int i = 0; i < arr.getSize(); i++) {
        os << arr.get(i) << " ";
    }
    os << "]";
    return os;
}

#endif