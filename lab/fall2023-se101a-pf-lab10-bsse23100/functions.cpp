//
// Created by student on 10/16/2023.
//
#include<iostream>
#include "functions.h"
# include <string>
using namespace std;
struct Distance{
    int feet;
    float inches;
};
[[maybe_unused]] Distance sumOfDistances ( Distance x, Distance y){
    Distance resultOFSum;
    resultOFSum.feet =x.feet+y.feet;
    resultOFSum.inches=x.inches+y.inches;
    if(resultOFSum.inches>=12){
        resultOFSum.inches -=12;
        resultOFSum.feet+=1;
    }
    return resultOFSum;
}
void q1(){
    Distance a , b,c;
    cout<<"enter first distance in feet";
    cin>>a.feet;
    cout<<"enter first distance in inches";
    cin>>a.inches;
    cout<<"enter second distance in feet";
    cin>>b.feet;
    cout<<"enter second distance in inches";
    cin>>b.inches;
    c=sumOfDistances(a,b);
    cout<<"sum of distances is "
    <<c.feet<<"feet"<<c.inches<<"inches"<<endl;
    return;
}

 void distanceArray(){
    int size;
    cout<<"enter size of array";
    cin>>size;
    Distance*arr=new Distance[size];
    for(int i=0;i<size;i++){
        cout<<"enter arr["<<i<<"]"<<"in feet";
        cin>>arr[i].feet;
        cout<<endl;
        cout<<"enter arr["<<i<<"]"<<"in inches";
        cin>>arr[i].inches;
        cout<<endl;
    }
    cout<<endl;
    cout<<"arr in descending order is"<<endl;
    for(int i=size;i>=0;i--){
        cout<<arr[i].feet<<" feet   "<<arr[i].inches<<" inches";
        cout<<endl;
    }
    delete[]arr;
    return ;
}
 struct Employee{
    string name;
    int id;
    double salary;
};
void employees(){
    Employee employee;
    cout<<"enter employee name :";
    cin>>employee.name;
    cout<<endl;
    cout<<"enter employee id :";
    cin>>employee.id;
    cout<<endl;
    cout<<"enter salary of employee("<<employee.id<<"):";
    cin>>employee.salary;
    cout<<endl;
    cout<<"employee information is "<<endl;
    cout<<"name :"<<employee.name<<endl;
    cout<<"id :"<<employee.id<<endl;
    cout<<"salary :"<<employee.salary<<endl;
    return ;
}
