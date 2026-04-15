#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int    _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _size(n) {
        if (n == 0) {
            _data = NULL;
        } else {
            _data = new T[n](); 
        }
    }

    Array(const Array& other) : _size(other._size) {
        if (_size == 0) {
            _data = NULL;
        } else {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            if (_size == 0) {
                _data = NULL;
            } else {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _data[i] = other._data[i];
                }
            }
        }
        return *this;
    }

    ~Array() {
        delete[] _data;
    }

    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif