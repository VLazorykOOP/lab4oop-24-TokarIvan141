#include "BusSchedule.h"

BusSchedule::BusSchedule() : CodeError(0) {}

void BusSchedule::addBus(int busNumber, const string& departureTime) {
    schedule[busNumber] = departureTime;
}

string& BusSchedule::operator[](int busNumber) {
    if (schedule.find(busNumber) == schedule.end()) {
        CodeError = 1;
        throw out_of_range("Bus number not found!");
    }
    CodeError = 0;
    return schedule[busNumber];
}

string BusSchedule::operator()(int busNumber) {
    if (schedule.find(busNumber) == schedule.end()) {
        CodeError = 1;
        return "Error: Bus number not found!";
    }
    CodeError = 0;
    return schedule[busNumber];
}

ostream& operator<<(ostream& os, const BusSchedule& busSchedule) {
    for (const auto& entry : busSchedule.schedule) {
        os << "Bus " << entry.first << " departs at " << entry.second << endl;
    }
    return os;
}

istream& operator>>(istream& is, BusSchedule& busSchedule) {
    int busNumber;
    string departureTime;
    cout << "Enter bus number: ";
    is >> busNumber;
    cout << "Enter departure time: ";
    is >> departureTime;
    busSchedule.addBus(busNumber, departureTime);
    return is;
}

int BusSchedule::getCodeError() const {
    return CodeError;
}
