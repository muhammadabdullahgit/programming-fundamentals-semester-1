#include<iostream>
#include "functions.h"

using namespace std;

int main() {
    int x;
    cout << "enter (2) for question number 1 and 2"<< endl;
    cout << "enter (3) for question number 3"<< endl;
    cout << "enter (4) for question number 4 and 5"<< endl;
    cin >> x;
    switch (x) {
        case 2: {
            q2();
            break;
        }
        case 3: {
            q3();
            break;
        }
        case 4: {
            q4();
            break;
        }
        default: {
            cout << "this question does not exist" << endl;
            break;
        }

    }
    return 0;
}
