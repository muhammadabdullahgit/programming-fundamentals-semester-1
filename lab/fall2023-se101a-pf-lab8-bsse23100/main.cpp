#include <iostream>
#include "functions.h"
#include <string>
using namespace std;
void q1(){
    string s;
    cout<<"enter string to check"<<endl;
    cin>>s;
    if (isPalindrome(s)){
        cout<<"it is palindrome"<<endl;
    }
    else {
        cout<<"it is not a palindrome"<<endl;
    }
}
int main(){
    int arr[50];
    cout<<"enter the size of array";
    q1();

    //Call your functions here
   
    return 0;
}
