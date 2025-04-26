#include "MatrixUShort.h"
#include <iostream>

int MatrixUShort::num_matrix = 0;

MatrixUShort::MatrixUShort() : UShortArray(nullptr), n(0), size(0), codeError(0) {
    num_matrix++;
}

MatrixUShort::MatrixUShort(int size) : n(size), size(size), codeError(0) {
    UShortArray = new VectorUShort[size];
    for (int i = 0; i < size; i++) {
        UShortArray[i] = VectorUShort(size);
    }
    num_matrix++;
}

MatrixUShort::MatrixUShort(int n, int size) : n(n), size(size), codeError(0) {
    UShortArray = new VectorUShort[n];
    for (int i = 0; i < n; i++) {
        UShortArray[i] = VectorUShort(size);
    }
    num_matrix++;
}

MatrixUShort::MatrixUShort(int n, int size, unsigned short initValue) : n(n), size(size), codeError(0) {
    UShortArray = new VectorUShort[n];
    for (int i = 0; i < n; i++) {
        UShortArray[i] = VectorUShort(size, initValue);
    }
    num_matrix++;
}

MatrixUShort::MatrixUShort(const MatrixUShort& other) : n(other.n), size(other.size), codeError(other.codeError) {
    UShortArray = new VectorUShort[n];
    for (int i = 0; i < n; i++) {
        UShortArray[i] = other.UShortArray[i];
    }
    num_matrix++;
}

MatrixUShort::~MatrixUShort() {
    delete[] UShortArray;
    num_matrix--;
}

int MatrixUShort::getN() const {
    return n;
}

int MatrixUShort::getSize() const {
    return size;
}

int MatrixUShort::getCodeError() const {
    return codeError;
}

MatrixUShort& MatrixUShort::operator=(const MatrixUShort& other) {
    if (this != &other) {
        delete[] UShortArray;
        n = other.n;
        size = other.size;
        codeError = other.codeError;
        UShortArray = new VectorUShort[n];
        for (int i = 0; i < n; i++) {
            UShortArray[i] = other.UShortArray[i];
        }
    }
    return *this;
}

MatrixUShort& MatrixUShort::operator++() {
    for (int i = 0; i < n; i++) {
        ++UShortArray[i];
    }
    return *this;
}

MatrixUShort MatrixUShort::operator++(int) {
    MatrixUShort temp = *this;
    ++(*this);
    return temp;
}

MatrixUShort& MatrixUShort::operator--() {
    for (int i = 0; i < n; i++) {
        --UShortArray[i];
    }
    return *this;
}

MatrixUShort MatrixUShort::operator--(int) {
    MatrixUShort temp = *this;
    --(*this);
    return temp;
}

bool MatrixUShort::operator!() const {
    return n == 0 || size == 0;
}

MatrixUShort MatrixUShort::operator~() const {
    MatrixUShort temp = *this;
    for (int i = 0; i < n; i++) {
        temp.UShortArray[i] = ~UShortArray[i];
    }
    return temp;
}

MatrixUShort MatrixUShort::operator-() const {
    MatrixUShort temp(n, size);
    for (int i = 0; i < n; i++) {
        temp.UShortArray[i] = -UShortArray[i];
    }
    return temp;
}

MatrixUShort MatrixUShort::operator+(const MatrixUShort& other) const {
    MatrixUShort result(n, size);
    for (int i = 0; i < n; i++) {
        result.UShortArray[i] = UShortArray[i] + other.UShortArray[i];
    }
    return result;
}

MatrixUShort MatrixUShort::operator-(const MatrixUShort& other) const {
    MatrixUShort result(n, size);
    for (int i = 0; i < n; i++) {
        result.UShortArray[i] = UShortArray[i] - other.UShortArray[i];
    }
    return result;
}

ostream& operator<<(ostream& os, const MatrixUShort& matrix) {
    for (int i = 0; i < matrix.n; i++) {
        os << matrix.UShortArray[i] << std::endl;
    }
    return os;
}

istream& operator>>(istream& is, MatrixUShort& matrix) {
    for (int i = 0; i < matrix.n; i++) {
        is >> matrix.UShortArray[i];
    }
    return is;
}

MatrixUShort MatrixUShort::operator*(const MatrixUShort& other) const {
    MatrixUShort result(n, size);
    for (int i = 0; i < n; i++) {
        result.UShortArray[i] = UShortArray[i] * other.UShortArray[i];
    }
    return result;
}

MatrixUShort MatrixUShort::operator*(unsigned short scalar) const {
    MatrixUShort result(n, size);
    for (int i = 0; i < n; i++) {
        result.UShortArray[i] = UShortArray[i] * scalar;
    }
    return result;
}

MatrixUShort MatrixUShort::operator/(unsigned short scalar) const {
    if (scalar == 0) {
        return *this;
    }

    MatrixUShort result(n, size);
    for (int i = 0; i < n; i++) {
        result.UShortArray[i] = UShortArray[i] / scalar;
    }
    return result;
}


MatrixUShort MatrixUShort::operator%(unsigned short scalar) const {
    MatrixUShort result(n, size);
    for (int i = 0; i < n; i++) {
        result.UShortArray[i] = UShortArray[i] % scalar;
    }
    return result;
}

MatrixUShort& MatrixUShort::operator+=(const MatrixUShort& other) {
    for (int i = 0; i < n; i++) {
        UShortArray[i] += other.UShortArray[i];
    }
    return *this;
}

MatrixUShort& MatrixUShort::operator+=(unsigned short scalar) {
    for (int i = 0; i < n; i++) {
        UShortArray[i] += scalar;
    }
    return *this;
}

MatrixUShort& MatrixUShort::operator-=(const MatrixUShort& other) {
    for (int i = 0; i < n; i++) {
        UShortArray[i] -= other.UShortArray[i];
    }
    return *this;
}

MatrixUShort& MatrixUShort::operator-=(unsigned short scalar) {
    for (int i = 0; i < n; i++) {
        UShortArray[i] -= scalar;
    }
    return *this;
}

MatrixUShort& MatrixUShort::operator*=(unsigned short scalar) {
    for (int i = 0; i < n; i++) {
        UShortArray[i] *= scalar;
    }
    return *this;
}

MatrixUShort& MatrixUShort::operator/=(unsigned short scalar) {
    if (scalar == 0) {
        codeError = 1;
        return *this;
    }

    for (int i = 0; i < n; i++) {
        UShortArray[i] /= scalar;
    }
    return *this;
}

MatrixUShort& MatrixUShort::operator%=(unsigned short scalar) {
    for (int i = 0; i < n; i++) {
        UShortArray[i] %= scalar;
    }
    return *this;
}
