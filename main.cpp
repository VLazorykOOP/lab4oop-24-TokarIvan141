#include <iostream>
#include "VectorUShort.h"
#include "BusSchedule.h"
#include "MatrixUShort.h"

using namespace std;

void task1()
{
    VectorUShort v1(5, 10);
    VectorUShort v2(5, 2);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    VectorUShort sum = v1 + v2;
    cout << "v1 + v2: " << sum << endl;

    VectorUShort neg = -v1;
    cout << "-v1: " << neg << endl;

    cout << "Count of objects: " << VectorUShort::getCount() << endl;
}

void task2()
{
    BusSchedule schedule;

    schedule.addBus(101, "08:00");
    schedule.addBus(102, "09:15");
    schedule.addBus(103, "10:30");

    cout << schedule;

    try {
        cout << "Bus 101 departs at: " << schedule[101] << endl;
        cout << "Bus 102 departs at: " << schedule(102) << endl;
        cout << "Bus 999 departs at: " << schedule[999] << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
        cout << "CodeError: " << schedule.getCodeError() << endl;
    }
}

void task3()
{
    MatrixUShort matrix1(3, 3, 5);
    MatrixUShort matrix2(3, 3, 10);

    cout << "Matrix 1:" << endl;
    cout << matrix1;

    cout << "Matrix 2:" << endl;
    cout << matrix2;

    MatrixUShort result = matrix1 + matrix2;
    cout << "Matrix 1 + Matrix 2:" << endl;
    cout << result;

    result = matrix1 - matrix2;
    cout << "Matrix 1 - Matrix 2:" << endl;
    cout << result;

    result = matrix1 * 2;
    cout << "Matrix 1 * 2:" << endl;
    cout << result;

    result = matrix1 / 2;
    cout << "Matrix 1 / 2:" << endl;
    cout << result;

    result = matrix1 % 3;
    cout << "Matrix 1 % 3:" << endl;
    cout << result;

    matrix1 += matrix2;
    cout << "Matrix 1 += Matrix 2:" << endl;
    cout << matrix1;

    matrix1 -= 5;
    cout << "Matrix 1 -= 5:" << endl;
    cout << matrix1;

    matrix1 *= 3;
    cout << "Matrix 1 *= 3:" << endl;
    cout << matrix1;

    matrix1 /= 2;
    cout << "Matrix 1 /= 2:" << endl;
    cout << matrix1;

    matrix1 %= 4;
    cout << "Matrix 1 %= 4:" << endl;
    cout << matrix1;
}

int main()
{
    srand(time(nullptr));

    int choice;
    do
    {
        cout << "\n============ Main Menu ============" << endl;
        cout << "1 - Task 1" << endl;
        cout << "2 - Task 2" << endl;
        cout << "3 - Task 3" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again\n";
        }
    } while (choice != 0);

    return 0;
}
