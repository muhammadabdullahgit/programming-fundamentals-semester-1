#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    cout<<"lab 6"<<endl;
    int x;
    cout<<"enter question number from 1 to 4  to run ";
    cin>>x;
    if (x==1)
    {
            int n;
            cout<<"enter number";
            cin>>n;
            printNumber(n);
    }
    else if (x==2)
    { int n;
        cout<<"enter number";
        cin>>n;
        cout<<sumNumber(n)<<endl;
    }
    else if (x==3){
        int n;
        cout<<"enter number";
        cin>>n;
        printTable(n);
    }

else if (x==4){
    int n;
    cout<<" enter number";
    cin>>n;
    cout<<sumDigits(n)<<endl;
}
else {
    cout<<"the question is not present "<<endl;
}
    //Call your functions here
   
    return 0;
}
