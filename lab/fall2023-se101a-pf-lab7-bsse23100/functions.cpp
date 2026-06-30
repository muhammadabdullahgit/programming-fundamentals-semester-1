#include "functions.h"
#include <iostream>

using namespace std;

void q1() {

    cout << "q1 is running" << endl;
    int value[5];
    for (int i = 0; i <= 4; i++) {
        cout << "enter value";
        cin >> value[i];
    }
    for (int j = 4; j >= 0; j--) {
        cout << value[j] << endl;
    }
}
void q2() {
    cout << "enter size" << endl;
    int size;
    cin >> size;
    int value[size];
    for (int i = 0; i < size; i++) {
        cout << "enter arr[" << i << "]=";
        cin >> value[i];
    }
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "]=" << value[i] << endl;
    }
    cout << "enter number to search" << endl;
    int x;
    cin >> x;
    for (int i = 0; i < size; ++i) {
        if (value[i] == x) {
            cout << "value is present at index= arr[" << i << "]" << endl;
            cout << "the value =" << x << endl;
            break;
        }
    }
}
