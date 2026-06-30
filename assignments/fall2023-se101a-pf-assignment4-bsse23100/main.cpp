#include <iostream>
using namespace std;

void q1()
{int x,y;
    int remainder=0;
    cout<<"enter a number";
    cin>>x;
    for (y=1;y<=x;y++)
    {
        if(x%y==0)
        {
            remainder++;
        }
    }
      if (remainder==2)
      {
          cout<<"number is prime"<<endl;
      }
      else {
          cout<<"number is not prime"<<endl;
      }

    // Write your solution for question 1 here
}
void q2()
{int x ,y;
    int temp;
    cout<<"enter first number";
    cin>>x;
    cout<<"enter second number";
    cin>>y;
    temp = x;
    x=y;
    y=temp;
    cout<<"swapped values are"<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
    // Write your solution for question 2 here
}
void q3()
{int x,y,z,sum;
    cout<<"enter first angle";
    cin>>x;
    cout<<"enter second angle";
    cin>>y;
    cout<<"enter third angle";
    cin>>z;
    sum=x+y+z;
    if (sum==180){
        cout<<"the triangle is valid"<<endl;
    }
    else {
        cout<<"the triangle is not valid"<<endl;
    }
    // Write your solution for question 3 here
}
void q4()
{int x;
    cout<<"enter number of a day";
    cin>>x;
    switch(x){
        case 1:
        {
            cout<<"sunday"<<endl;
            break;
        }
        case 2:{
            cout<<"monday"<<endl;
            break;
        }
        case 3:{
        cout<<"tuesday"<<endl;
        break;}
        case 4 :{
            cout<<"wednesday"<<endl;
            break;
        }
        case 5:{
            cout<<"thursday"<<endl;
            break;
        }
        case 6:{
            cout<<"friday"<<endl;
            break;
        }
        case 7:{
            cout<<"saturday"<<endl;
        }
        default:{
            cout<<"the number entered is invalid"<<endl;
            break;
        }
    }
    // Write your solution for question 4 here
}
void q5()
{int x;
    cout<<"enter year";
    cin>>x;
    if (x%400==0){
        cout<<"it is a leap year"<<endl;
    }
    else if(x%100!=0&&x%4==0){
        cout<<"it is a leap year"<<endl;
    }
    else{
        cout<<"it is not a leap year"<<endl;
    }
    // Write your solution for question 5 here
}

int main() {

    q5();

    return 0;
}