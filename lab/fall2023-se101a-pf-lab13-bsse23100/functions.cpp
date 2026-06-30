//
// Created by student on 10/16/2023.
//
#include<iostream>
#include "functions.h"
#include<cmath>
using namespace std;
struct Point{
    float x;
    float y;
};
Point wp={0,0};
Point p;
void q1(){
    cout<<"enter value of x";
    cin>>p.x;
    cout<<endl;
    cout<<"enter value of y";
    cin>>p.y;
    cout<<"x coordinate is "<<p.x<<endl;
    cout<<"y coordinate is "<<p.y<<endl;
    return;
}
void q2(){
    q1();
    if(p.x==0&&p.y==0){
        cout<<"x and y are at origin"<<endl;
        return;
    }
    else if(p.x>0&&p.y>0){
        cout<<"x and y are in Quad 1"<<endl;
        return;
    }
    else if(p.x<0&&p.y>0){
        cout<<"x and y are in Quad 2"<<endl;
        return;
    }
    else if(p.x<0&&p.y<0){
        cout<<"x and y are in Quad 3"<<endl;
        return;
    }
    else {
        cout<<"x and y are in Quad 4"<<endl;
        return;
    }
}
void distance(int x,int y){
    float distance=((x-wp.x)*(x-wp.x))+((y-wp.y)*(y-wp.y));
    float distance2;
    distance2= sqrt(distance);
    cout<<"distance is "<<distance2<<endl;
}
void q3(){
    cout<<"enter value of x";
    cin>>p.x;
    cout<<endl;
    cout<<"enter value of y";
    cin>>p.y;
    distance(p.x, p.y);
    return;
}
void q4(){
    int size;
    cout<<"enter size"<<endl;
    cin>>size;
    Point*x=new Point[size];
    for (int i = 0; i < size; ++i) {
        cout<<" point"<<i+1<<endl;
        cout<<endl;
        cout<<"enter x coordinate of point"<<i+1<<"=";
        cin>>x[i].x;
        cout<<endl;
        cout<<"enter y coordinate of point"<<i+1<<"=";
        cin>>x[i].y;
        cout<<endl;
    }
    for (int i = 0; i < size; ++i) {
        cout<<"point"<<i+1<<"=("<<x[i].x<<","<<x[i].y<<")"<<endl;
    }
    delete[]x;
    return;
}