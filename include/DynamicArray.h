#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int size);
    ~DynamicArray();
    DynamicArray(DynamicArray& other);

    void print();
    void set(int index, int value);
    int get(int index);
    void append(int value);
    void add(DynamicArray other);
    void subtract(DynamicArray other);
};

#endif