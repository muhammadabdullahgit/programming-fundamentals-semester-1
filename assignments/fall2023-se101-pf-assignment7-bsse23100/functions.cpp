#include "functions.h"
#include <iostream>

using namespace std;

void q1() {
    cout << "q1 is running" << endl;
    int arr1[5];
    int arr2[5];
    int arr3[5];
    cout << "enter values for first array" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr1[i];
    }
    cout << endl;
    cout << "enter value for second array" << endl;
    for (int j = 0; j < 5; j++) {
        cin >> arr2[j];
    }
    cout << endl;
    cout << "third array = [ ";
    for (int k = 0; k < 5; k++) {
        arr3[k] = arr1[k] + arr2[k];
        cout << arr3[k] << " ";
    }
    cout << "]" << endl;
}

void q2() {
    cout << "q2 is running" << endl;
    int a, frequency = 0;
    int arr[20];
    cout << "enter 20 values for array" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }
    cout << "enter value to check frequency" << endl;
    cin >> a;
    for (int j = 0; j < 20; j++) {
        if (arr[j] == a) {
            frequency++;
        }
    }
    cout << frequency << endl;
}

void q3() {
    cout << "q3 is running" << endl;
    int a;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "enter number to have its  index of first occurrence  " << endl;
    cin >> a;
    for (int i = 0; i < 10; i++) {
        if (a == arr[i]) {
            cout << i << endl;
            break;
        }
    }
}

void q4() {
    cout << "q4 is running" << endl;
    int max;
    int arr[4][4];
    cout << "enter values for 4x4 array" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }
    cout << "entered array is" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    for (int k = 0; k < 4; k++) {
        max = arr[k][0];
        for (int m = 0; m < 4; m++) {
            if (arr[k][m] > max) {
                max = arr[k][m];
            }
        }
        cout << "maximum element in row " << k + 1 << " = " << max << endl;
    }
}

void q5() {
    cout << "q5 is running" << endl;
    int matrix1[5][5];
    int matrix2[5][5];
    int resultantMatrix[5][5];
    cout << "enter values for 5x5 matrix1" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> matrix1[i][j];
        }
    }
    cout << "enter values for 5x5 matrix2" << endl;
    for (int k = 0; k < 5; k++) {
        for (int m = 0; m < 5; m++) {
            cin >> matrix2[k][m];
        }
    }
    cout << "entered values for 5x5 matrix1" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout<< matrix1[i][j];
        }
        cout<<endl;
    }
    cout << "entered values for 5x5 matrix2" << endl;
    for (int k = 0; k < 5; k++) {
        for (int m = 0; m < 5; m++) {
            cout<< matrix2[k][m];
        }
        cout<<endl;
    }
    for (int n = 0; n < 5; n++) {
        for (int p = 0; p < 5; p++) {
            resultantMatrix[n][p] = 0;
            for (int r = 0; r < 5; r++) {
                resultantMatrix[n][p] += matrix1[n][r] * matrix2[r][p];
            }
        }
    }
    cout << "resultant matrix = "<<endl;
    for (int s = 0; s < 5; s++) {
        for (int t = 0; t < 5; t++) {
            cout << resultantMatrix[s][t] << " ";
        }
        cout << endl;
    }
}