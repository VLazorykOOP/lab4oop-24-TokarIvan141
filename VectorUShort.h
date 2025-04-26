#pragma once
#include <iostream>

using namespace std;

class VectorUShort {
private:
    unsigned short* data;
    size_t num;
    int state;
    static int count;

public:
    VectorUShort();
    VectorUShort(size_t n);
    VectorUShort(size_t n, unsigned short value);
    VectorUShort(const VectorUShort& other);

    ~VectorUShort();

    VectorUShort& operator=(const VectorUShort& other);

    VectorUShort& operator++();
    VectorUShort operator++(int);
    VectorUShort& operator--();
    VectorUShort operator--(int);
    bool operator!() const;
    VectorUShort operator~() const;
    VectorUShort operator-() const;

    VectorUShort operator+(const VectorUShort& other) const;
    VectorUShort operator-(const VectorUShort& other) const;
    VectorUShort operator*(const VectorUShort& other) const;
    VectorUShort operator*(unsigned short value) const;
    VectorUShort operator/(unsigned short value) const;
    VectorUShort operator%(unsigned short value) const;

    VectorUShort operator|(const VectorUShort& other) const;
    VectorUShort operator^(const VectorUShort& other) const;
    VectorUShort operator&(const VectorUShort& other) const;

    VectorUShort& operator+=(const VectorUShort& other);
    VectorUShort& operator-=(const VectorUShort& other);
    VectorUShort& operator*=(unsigned short value);
    VectorUShort& operator/=(unsigned short value);
    VectorUShort& operator%=(unsigned short value);


    bool operator==(const VectorUShort& other) const;
    bool operator!=(const VectorUShort& other) const;
    bool operator>(const VectorUShort& other) const;
    bool operator>=(const VectorUShort& other) const;
    bool operator<(const VectorUShort& other) const;
    bool operator<=(const VectorUShort& other) const;

    unsigned short& operator[](size_t index);

    friend ostream& operator<<(ostream& os, const VectorUShort& vec);
    friend istream& operator>>(istream& is, VectorUShort& vec);

    VectorUShort& operator<<=(unsigned short value);
    VectorUShort& operator>>=(unsigned short value);

    void operator()();

    int getState() const;
    static int getCount();
    void print() const;
};
