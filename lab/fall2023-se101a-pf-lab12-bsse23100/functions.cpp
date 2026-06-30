#include<iostream>
#include "functions.h"

using namespace std;
struct Date{
    int year;
    int month;
    int day;
};
int sumOfNTerms(int n, int sum = 0, int sum2 = 2) {
    if (n <= 0) {
        cout << "sum=" << sum;
    } else {
        sum = sum + sum2;
        return sumOfNTerms(n - 1, sum, sum2 + 3);
    }
    return 0;
}
void unique(int arr[], int sizeOfArr, int& newSize) {
    int duplicate = 0;

    for (int i = 0; i < sizeOfArr - 1; i++) {
        for (int j = i + 1; j < sizeOfArr - duplicate;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < sizeOfArr - duplicate - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                duplicate++;
            } else {
                j++;
            }
        }
    }
    newSize = sizeOfArr - duplicate;
    int uniqueArr[sizeOfArr - duplicate];
    for (int i = 0; i < newSize; i++) {
        uniqueArr[i] = arr[i];
    }
    for (int i = 0; i < newSize; i++) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;
}
void q1()
{
    int size;
    cout << " Enter the size of array: ";
    cin >> size;
    int* x = new int[size];
    cout << " Enter " << size << " elements for an array: " <<endl;
    for(int i=0;i<size;i++) {
        cout << " Enter element No." << i+1 << ": ";
        cin >> x[i];
    }
    cout << "  entered array is  "<< endl;
    for(int j=0;j<size;j++) {
        cout << x[j] << " ";
    }
    cout << endl;
    int newSize;
    cout << " new array is "<<endl;
    unique( x, size, newSize);
    delete[] x;
}
void q2() {
    int n;
    cout << "enter number" << endl;
    cin >> n;
    sumOfNTerms(n);
    return;
}
Date a,b;
void determineAge(){
    cout<<"enter year of birth"<<endl;
    cin>>a.year;
    cout<<"enter month number of birth"<<endl;
    cin>>a.month;
    cout<<"enter date of month of birth "<<endl;
    cin>>a.day;
    cout<<"enter year of current date"<<endl;
    cin>>b.year;
    cout<<"enter month number of current date"<<endl;
    cin>>b.month;
    cout<<"enter date of month of current date "<<endl;
    cin>>b.day;
}
void ageCalculation(){
    int x,y,z;
    determineAge();
    x= b.year-a.year;
    y=b.month-a.month;
    z=b.day-a.day;
    cout<<"calculated age ="<<endl;
   cout<< "year"<<x<<endl;
    cout<<"month"<<y<<endl;
    cout<<"day"<<z<<endl;
    return;
}
void q3(){
     ageCalculation();
    return;
}