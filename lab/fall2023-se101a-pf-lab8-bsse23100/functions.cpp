#include "functions.h"
#include <iostream>
# include <string>
using namespace std;
bool isPalindrome(string s){
    cout<<"ENTER THE STRING"<<endl;
    cin>>s;
    cout<<"enter the size of string ";
    int a;
    cin>>a;
    for (int i = 0; i <a/2 ; i--) {
        if(s[i]!=s[a-i-1]){
            return false;
        }else{
            return true;
        }
    }
    return 0;
}


