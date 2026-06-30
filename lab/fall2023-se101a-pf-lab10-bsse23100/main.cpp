#include<iostream>
#include "functions.h"
using namespace std;
int main()
{
    int x;
    cout<<"enter question you want to run"<<endl;
    cin>>x;
    switch (x) {
        case 1:{
            q1();
            break;
        }
        case 2:{
            distanceArray();
            break;
        }
        case 3:{
            employees();
            break;
        }
        default:{
            cout<<"this question does not exist"<<endl;
            break;
        }
    }
return 0;
}
