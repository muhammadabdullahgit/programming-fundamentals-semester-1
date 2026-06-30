# include <iostream>

using namespace std;

int main() {
    cout << "welcome to assignment 5" << endl;
    int x;
    cout << "enter question number to run";
    cin >> x;
    if (x == 2) {
        cout << "ascii values and their equivalent character  are as follows" << endl;
        for (int a = 0; a <= 255; a++) {
            cout << a << "  =  " << char(a) << endl;
        }
    } else if (x == 3) {
        int b = 0000;
        while (b >= 0000) {
            cout << "enter a 4 digit  pin ";
            cin >> b;
            if (b == 1234) {
                cout << "you have successfully entered the correct pin" << endl;
                break;
            } else {
                cout << "the pin you entered is incorrect " << endl;
            }
        }
    } else if (x == 4) {
        int c = 5;
        for (int d = 1; d <= c; d++) {
            for (int e = 1; e <= 4; e++) {
                cout << "* ";
            }
            cout << "*" << endl;
        }

    } else if (x == 5) {
        float f = 0;
        float total = 0;
        while (f >= 0) {
            cout << "enter price of item ";
                if (cin>>f&&f >= 0) {
                    total += f;
                }
        }
        cout << "total  cost of items is: $" << total << endl;
    } else {
        cout << "the question does not exist" << endl;
    }
    return 0;
}
