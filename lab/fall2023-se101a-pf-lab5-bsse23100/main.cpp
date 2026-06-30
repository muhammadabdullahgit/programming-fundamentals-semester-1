#include <iostream>
#include "functions.h"
using namespace std;
int main() 
{ cout << "lab 5" << endl;
    int x;
    cout << "enter question number";
    cin >> x;
    if (x == 1) {
        q1();
    }
    else if (x == 2) {
        q2();
    }
    else if (x == 3) {
        q3();
    }
    else if (x == 4) {
        q4();
    }
    else if (x == 5) {
        q5();
    }
    else {
        cout << "that question does not exist" << endl;
    }
   

    return 0;
}
