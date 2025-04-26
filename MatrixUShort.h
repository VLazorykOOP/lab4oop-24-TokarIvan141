#pragma once
#include "VectorUShort.h"

class MatrixUShort {
private:
    VectorUShort* UShortArray;
    int n, size, codeError;
    static int num_matrix;

public:
    MatrixUShort();
    MatrixUShort(int size);
    MatrixUShort(int n, int size);
    MatrixUShort(int n, int size, unsigned short initValue);
    MatrixUShort(const MatrixUShort& other);
    ~MatrixUShort();

    int getN() const;
    int getSize() const;
    int getCodeError() const;

    MatrixUShort& operator=(const MatrixUShort& other);
    MatrixUShort& operator++();
    MatrixUShort operator++(int);
    MatrixUShort& operator--();
    MatrixUShort operator--(int);
    bool operator!() const;
    MatrixUShort operator~() const;
    MatrixUShort operator-() const;

    MatrixUShort operator+(const MatrixUShort& other) const;
    MatrixUShort operator-(const MatrixUShort& other) const;
    MatrixUShort operator*(const MatrixUShort& other) const;
    MatrixUShort operator*(unsigned short scalar) const;

    MatrixUShort operator/(unsigned short scalar) const;

    MatrixUShort operator%(unsigned short scalar) const;

    MatrixUShort& operator+=(const MatrixUShort& other);
    MatrixUShort& operator+=(unsigned short scalar);
    MatrixUShort& operator-=(const MatrixUShort& other);
    MatrixUShort& operator-=(unsigned short scalar);
    MatrixUShort& operator*=(unsigned short scalar);
    MatrixUShort& operator/=(unsigned short scalar);
    MatrixUShort& operator%=(unsigned short scalar);

    friend ostream& operator<<(ostream& os, const MatrixUShort& matrix);
    friend istream& operator>>(istream& is, MatrixUShort& matrix);
};
