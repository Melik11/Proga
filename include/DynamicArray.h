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
    class Cell {
    private:
        DynamicArray<T>& arr;
        int index;
    public:
        Cell(DynamicArray<T>& a, int i) : arr(a), index(i) {}
        operator T() const { return arr.get(index); }
        Cell& operator=(T value) {
            arr.set(index, value);
            return *this;
        }
    };

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

    Cell operator[](int index) { return Cell(*this, index); }
    T operator[](int index) const { return get(index); }

    bool operator==(const DynamicArray<T>& other) const;
    bool operator!=(const DynamicArray<T>& other) const;

    DynamicArray<T>& operator+=(const DynamicArray<T>& other);
    DynamicArray<T>& operator-=(const DynamicArray<T>& other);
    DynamicArray<T>& operator+=(T scalar);
    DynamicArray<T>& operator-=(T scalar);

    T* begin() { return data; }
    T* end() { return data + size; }
    const T* begin() const { return data; }
    const T* end() const { return data + size; }
};

template <typename T>
DynamicArray<T>::DynamicArray(int size) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; i++) data[i] = T();
}

template <typename T>
DynamicArray<T>::~DynamicArray() { delete[] data; }

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    size = other.size;
    data = new T[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
}

template <typename T>
void DynamicArray<T>::set(int index, T value) {
    if (index < 0 || index >= size) throw std::out_of_range("Индекс вне границ");
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100) throw std::invalid_argument("Значение вне диапазона [-100; 100]");
    }
    data[index] = value;
}

template <typename T>
T DynamicArray<T>::get(int index) const {
    if (index < 0 || index >= size) throw std::out_of_range("Индекс вне границ");
    return data[index];
}

template <typename T>
void DynamicArray<T>::append(T value) {
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100) throw std::invalid_argument("Значение вне диапазона [-100; 100]");
    }
    T* newData = new T[size + 1];
    for (int i = 0; i < size; i++) newData[i] = data[i];
    newData[size] = value;
    delete[] data;
    data = newData;
    size++;
}

template <typename T>
void DynamicArray<T>::add(const DynamicArray<T>& other) {
    for (int i = 0; i < size; i++) {
        T val = T();
        if (i < other.size) val = other.data[i];
        data[i] += val;
    }
}

template <typename T>
void DynamicArray<T>::subtract(const DynamicArray<T>& other) {
    for (int i = 0; i < size; i++) {
        T val = T();
        if (i < other.size) val = other.data[i];
        data[i] -= val;
    }
}

template <typename T>
double DynamicArray<T>::distance(const DynamicArray<T>& other) const {
    if constexpr (!std::is_arithmetic_v<T>) {
        throw std::bad_typeid();
    } else {
        if (size != other.size) throw std::invalid_argument("Размеры массивов не совпадают");
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

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

template <typename T>
bool DynamicArray<T>::operator!=(const DynamicArray<T>& other) const {
    return !(*this == other);
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator+=(const DynamicArray<T>& other) {
    add(other);
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator-=(const DynamicArray<T>& other) {
    subtract(other);
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator+=(T scalar) {
    for (int i = 0; i < size; i++) {
        set(i, data[i] + scalar);
    }
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator-=(T scalar) {
    for (int i = 0; i < size; i++) {
        set(i, data[i] - scalar);
    }
    return *this;
}

#endif