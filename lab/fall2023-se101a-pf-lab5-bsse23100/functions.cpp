#include "functions.h"
#include <iostream>

using namespace std;

void q1() {
    int y = 1, sum = 0, n;
    cout << "enter a number ";
    cin >> n;
    while (y <= n) {
        sum += y;
        y++;
    }
    cout << sum << endl;


}

void q2() {
    int x, z;
    cout << "enter a number to give prime numbers till then ";
    cin >> x;
    if (x==0){
        cout<<" no prime number "<<endl;
        return;
    }
    for (int i = 1; i <= x; i++) {
        z = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                z++;
            }
        }
        if (z == 2) {
            cout << i << " ";
        }
    }
}

void q3() {
    int x = 4;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

}

void q4() {
    int x;
    cout << "enter number to have factors ";
    cin >> x;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            cout << i << " ";
        }
    }
}

void q5() {
    int x, y, sum = 0;
    cout << "enter number to have sum of digits";
    cin >> x;
    while (x > 0) {
        y = x % 10;
        sum += y;
        x = x / 10;
    }
    cout << sum << endl;
}

