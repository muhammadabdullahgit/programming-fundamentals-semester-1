//
// Created by student on 10/16/2023.
//
#include<iostream>
#include "functions.h"
using namespace std;
template<typename T>
T maxFunction( T x,T y ){
    if (x>y){
        return x;}
        else if (x==y){
            cout<<"both are equal "<<endl;
            return 0;
        }
    else {
        return y;
    }
}
 void q1() {
     cout << "q1 is running " << endl;
     int a, b;
     double c,d;
     cout << "enter first  integer value";
     cin >> a;
     cout << "enter second integer value";
     cin >> b;
     cout << "maximum value is " << maxFunction(a, b) << endl;
     cout<<endl;
     cout << "enter first double  value";
     cin >> c;
     cout << "enter second double  value";
     cin >> d;
     cout << "maximum value is " << maxFunction(c, d) << endl;
     return;
 }
template<typename T>
T minFunction( T x,T y ){
    if (x<y){
        return x;}
    else if (x==y){
        cout<<"both are equal "<<endl;
        return 0;
    }
    else {
        return y;
    }
}
void q2() {
    cout << "q2 is running " << endl;
    int a, b;
    double c,d;
    cout << "enter first integer  value";
    cin >> a;
    cout << "enter second integer value";
    cin >> b;
    cout << "minimum value is " << minFunction(a, b) << endl;
    cout<<endl;
    cout << "enter first double  value";
    cin >> c;
    cout << "enter second double  value";
    cin >> d;
    cout << "minimum value is " << minFunction(c, d) << endl;
    return;
}

template<typename T>
bool searchElement(T**arr, int x,int y,T z)
{
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
          if(arr[i][j]==z){
              return true;
          }
        }
        }
    return false;
}
void q3(){
    cout<< "q3 is running"<<endl;
    int a,b;
    cout<<"enter number of rows";
    cin>>a;
    cout<<"enter  number of columns";
    cin>>b;
    int **arr=new int *[a];
    for (int i = 0; i < a; i++) {
        arr[i]=new int [b];
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            cout<<"enter values for arr["<<i<<"]["<<j<<"]=";
            cin>>arr[i][j];
        }
    }
    int c;
    cout<<"enter element to search in a 2D array";
    cin>>c;
    if(searchElement(arr,a,b,c)){
        cout<<"element is present in the array"<<endl;
    }
    else {
        cout<<"element is  not present in the array"<<endl;
    }
    for (int i = 0; i < a; ++i) {
        delete[]arr[i];
    }
    delete[]arr;
    return ;
}