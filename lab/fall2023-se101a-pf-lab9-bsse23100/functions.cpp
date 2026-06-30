//
// Created by student on 10/16/2023.
//
#include<iostream>
#include "functions.h"
#include<fstream>
#include <string>
using namespace std;
void q1(){
    ofstream studentDataFile("students.txt");
    studentDataFile<<"rollNumber=BSSE 23100"<<endl;
    studentDataFile<<"name= MUHAMMAD ABDULLAH"<<endl;
    studentDataFile<<"phoneNumber= 03234351329"<<endl;
    studentDataFile.close();
    return ;
}
void q3(){
    int count1 =0,count2=0;
     ifstream studentDataFile("students.txt");
     char a;
     while (!studentDataFile.eof()){
         studentDataFile.get(a);
         count1++;
     }
     cout<<"the number of characters in a file is "<<count1<<endl;
     studentDataFile.close();
   return ;
}
void q2(){
    int n,sum=0;
    cout<<"enter size for array";
    cin>>n;
    int *arr=new int [n];
    for (int i = 0; i < n; i++) {
        cout<<"enter values of array ["<<i<<"]=";
        cin>>arr[i];
    }
    for (int j = 0; j < n; j++) {
        sum+= *(arr+j);
    }
    cout<<"sum of all elements in an array is "<< sum<<endl;
    delete[]arr;
    return ;
}
void q4(){
    int a,b;
    cout<<"enter number of rows";
    cin>>a;
    cout<<"enter  number of columns";
    cin>>b;
    int **arr=new int *[a];
    for (int i = 0; i < b; i++) {
        arr[i]=new int [b];
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            cout<<"enter values for arr["<<i<<"]["<<j<<"]=";
            cin>>arr[i][j];
        }
    }
   int x;
    cout<<"enter element to search in a 2D array";
    cin>>x;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (arr[i][j] == x) {
                cout << "element found at index[" << i << "][" << j << "]" << endl;
                break;
            }
            }
        }
    for (int i = 0; i < a; ++i) {
        delete[]arr[i];
    }
    delete[]arr;
    return ;
}
