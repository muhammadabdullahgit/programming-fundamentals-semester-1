#include<iostream>
#include "functions.h"
#include<fstream>
using namespace std;
int main()
{
    int x;
    cout<<"enter question number to run";
    cin>>x;
    switch (x){
        case 1:{
            cout<<"q1 is running"<<endl;
            q1();
            break;
        }
        case 2:{
            cout<<"q2 is running"<<endl;
            q3();
            break;
        }
        case 3:{
            cout<<"q3 is running"<<endl;
            q2();
            break;
        }
        case 4:{
            cout<<"q4 is running"<<endl;
            q4();
            break;
        }
        default:{
            cout<<"this question does not exist"<<endl;
            break;
        }
    }
return 0;
}
