#include "VectorUShort.h"
#include <climits>

int VectorUShort::count = 0;

VectorUShort::VectorUShort() : num(1), state(0) {
    data = new unsigned short[num]{0};
    count++;
}

VectorUShort::VectorUShort(size_t n) : num(n), state(0) {
    data = new unsigned short[num]{0};
    count++;
}

VectorUShort::VectorUShort(size_t n, unsigned short value) : num(n), state(0) {
    data = new unsigned short[num];
    for (size_t i = 0; i < num; i++) {
        data[i] = value;
    }
    count++;
}

VectorUShort::VectorUShort(const VectorUShort& other) : num(other.num), state(other.state) {
    data = new unsigned short[num];
    for (size_t i = 0; i < num; i++) {
        data[i] = other.data[i];
    }
    count++;
}

VectorUShort::~VectorUShort() {
    delete[] data;
    count--;
}

VectorUShort& VectorUShort::operator=(const VectorUShort& other) {
    if (this != &other) {
        delete[] data;
        num = other.num;
        state = other.state;
        data = new unsigned short[num];
        for (size_t i = 0; i < num; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

VectorUShort& VectorUShort::operator++() {
    for (size_t i = 0; i < num; i++) data[i]++;
    return *this;
}

VectorUShort VectorUShort::operator++(int) {
    VectorUShort temp = *this;
    ++(*this);
    return temp;
}

VectorUShort& VectorUShort::operator--() {
    for (size_t i = 0; i < num; i++) data[i]--;
    return *this;
}

VectorUShort VectorUShort::operator--(int) {
    VectorUShort temp = *this;
    --(*this);
    return temp;
}

bool VectorUShort::operator!() const {
    return num == 0;
}

VectorUShort VectorUShort::operator~() const {
    VectorUShort temp = *this;
    for (size_t i = 0; i < num; i++) {
        temp.data[i] = ~data[i];
    }
    return temp;
}

VectorUShort VectorUShort::operator-() const {
    VectorUShort temp(num);
    for (size_t i = 0; i < num; i++) {
        temp.data[i] = (~data[i]) + 1;
    }
    return temp;
}

VectorUShort VectorUShort::operator+(const VectorUShort& other) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

VectorUShort VectorUShort::operator-(const VectorUShort& other) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

VectorUShort VectorUShort::operator*(const VectorUShort& other) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}

VectorUShort VectorUShort::operator*(unsigned short scalar) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] * scalar;
    }
    return result;
}

VectorUShort VectorUShort::operator/(unsigned short value) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] / value;
    }
    return result;
}

VectorUShort VectorUShort::operator%(unsigned short value) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] % value;
    }
    return result;
}

VectorUShort VectorUShort::operator|(const VectorUShort& other) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] | other.data[i];
    }
    return result;
}

VectorUShort VectorUShort::operator^(const VectorUShort& other) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] ^ other.data[i];
    }
    return result;
}

VectorUShort VectorUShort::operator&(const VectorUShort& other) const {
    VectorUShort result(num);
    for (size_t i = 0; i < num; i++) {
        result.data[i] = data[i] & other.data[i];
    }
    return result;
}


VectorUShort& VectorUShort::operator+=(const VectorUShort& other) {
    for (size_t i = 0; i < num; i++) {
        data[i] += other.data[i];
    }
    return *this;
}

VectorUShort& VectorUShort::operator-=(const VectorUShort& other) {
    for (size_t i = 0; i < num; i++) {
        data[i] -= other.data[i];
    }
    return *this;
}

VectorUShort& VectorUShort::operator*=(unsigned short value) {
    for (size_t i = 0; i < num; i++) {
        data[i] *= value;
    }
    return *this;
}

VectorUShort& VectorUShort::operator/=(unsigned short value) {
    for (size_t i = 0; i < num; i++) {
        data[i] /= value;
    }
    return *this;
}

VectorUShort& VectorUShort::operator%=(unsigned short value) {
    for (size_t i = 0; i < num; i++) {
        data[i] %= value;
    }
    return *this;
}

bool VectorUShort::operator==(const VectorUShort& other) const {
    if (num != other.num) return false;
    for (size_t i = 0; i < num; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

bool VectorUShort::operator!=(const VectorUShort& other) const {
    return !(*this == other);
}

bool VectorUShort::operator>(const VectorUShort& other) const {
    return num > other.num;
}

bool VectorUShort::operator>=(const VectorUShort& other) const {
    return num >= other.num;
}

bool VectorUShort::operator<(const VectorUShort& other) const {
    return num < other.num;
}

bool VectorUShort::operator<=(const VectorUShort& other) const {
    return num <= other.num;
}


unsigned short& VectorUShort::operator[](size_t index) {
    return data[index];
}

ostream& operator<<(ostream& os, const VectorUShort& vec) {
    for (size_t i = 0; i < vec.num; i++) {
        if (vec.data[i] > 32767) {
            os << static_cast<int>(vec.data[i] - USHRT_MAX - 1) << " ";
        } else {
            os << static_cast<int>(vec.data[i]) << " ";
        }
    }
    return os;
}


istream& operator>>(istream& is, VectorUShort& vec) {
    for (size_t i = 0; i < vec.num; i++) {
        is >> vec.data[i];
    }
    return is;
}

VectorUShort& VectorUShort::operator<<=(unsigned short value) {
    for (size_t i = 0; i < num; i++) {
        data[i] <<= value;
    }
    return *this;
}

VectorUShort& VectorUShort::operator>>=(unsigned short value) {
    for (size_t i = 0; i < num; i++) {
        data[i] >>= value;
    }
    return *this;
}


void VectorUShort::operator()() {
    cout << "Vector size: " << num << endl;
}


int VectorUShort::getState() const {
    return state;
}

int VectorUShort::getCount() {
    return count;
}

void VectorUShort::print() const {
    for (size_t i = 0; i < num; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
