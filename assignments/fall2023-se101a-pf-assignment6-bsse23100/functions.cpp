#include "functions.h"
#include <iostream>
using namespace std;
int productOfNumbers(int x,int y){
    if (x==0||y==0){
        return 0;
    }
    else if (x==1){
        return y;
    }
    else {
        return x+productOfNumbers(x,y-1);
    }
}
 int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sumOfDigits(n / 10);
    }
}
int primeNumber(int x, int y) {

    if (y ==1){
        return 1;}
    if (x%y==0)
        return 0;
    return primeNumber(x,y-1);
}
int sumOfEvenNumbers(int x, int y){
if (x>y){
    return 0;
}
else if (x%2==0){
    return x+sumOfEvenNumbers(x+2,y);
}
else(x%2==1);{
    return sumOfEvenNumbers(x+1,y);
}
}
int sumOfOddNumbers(int x,int y){
    if(x>y){
        return 0;
    }
    else if(x%2==1){
     return x+sumOfOddNumbers(x+2,y);
    }
    else(x%2==0);{
        return sumOfOddNumbers(x+1,y);
    }
}
int squarePatternOfRows(char w,int x) {

    if (x == 1) {
        return 0;
    } else {
        squarePatternOfRows(w, x - 1);
        cout << w;
        return 0;
    }
}
       int squarePatternOfColumns(char w,int y) {
            if (y == 0) {
                return 0;
            } else {

                squarePatternOfColumns(w, y-1);

                squarePatternOfRows(w,4);
                cout <<w;
                cout<<endl;
                return 0;
            }
        }


void q1() {
    cout<<"q1 is running"<<endl;
    int a, b;
    cout << "enter first number";
    cin >> a;
    cout << "enter second number";
    cin >> b;
    cout << productOfNumbers(a, b) << endl;
}
void q2(){
    cout<<"q2 is running now"<<endl;
    int c;
    cout << " enter number to calculate sum of digits";
    cin >> c;
    cout << sumOfDigits(c) << endl;

}
void q3() {
    cout<<"q3 is running now"<<endl;
    int d, e;
    cout << "enter number to check prime or not";
    cin >> d;
    if (d == 0 || d == 1) {
        cout << "the number entered is not a prime number" << endl;
    } else {
        e = primeNumber(d, d / 2);
        if (e == 1) {
            cout << " the number entered is a prime number" << endl;
        } else {
            cout << "the number entered is not a prime number" << endl;
        }
    }
}
void q4(){
    cout<<"q4 is running now"<<endl;
    int f=1,g;
    cout<<"enter number to have sum of even and odd number";
    cin>>g;
    cout<<"sum of even numbers="<<sumOfEvenNumbers(f,g)<<endl;
    cout<<"sum of odd numbers"<<sumOfOddNumbers(f,g)<<endl;
}
void q5(){
    cout<<"q5 is running now"<<endl;
   char h;
    int  j=0;
    cout<<"enter key";
    cin>>h;
    cout<<"enter number of rows to print";
    cin>>j;
   squarePatternOfColumns(h,j);
}
int r(int a){
  if (a==0){
     return 0;
  }
  else if(a==1){
      return 1;
  }
  else {
      return (r(a-1)+r(a-2));
  }
}
void q6(){
    int x;
    cout<<"enter number"<<endl;
    cin>>x;
    for (int i = 0; i < x; ++i) {
        cout<<r(i);
    }
}