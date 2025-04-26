#ifndef BUSSCHEDULE_H
#define BUSSCHEDULE_H

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class BusSchedule {
private:
    unordered_map<int, string> schedule;
    int CodeError;

public:
    BusSchedule();

    void addBus(int busNumber, const string& departureTime);

    string& operator[](int busNumber);

    string operator()(int busNumber);

    friend ostream& operator<<(ostream& os, const BusSchedule& busSchedule);

    friend istream& operator>>(istream& is, BusSchedule& busSchedule);

    int getCodeError() const;
};

#endif
