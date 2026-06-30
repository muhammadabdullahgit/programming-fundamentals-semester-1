#include "functions.h"
#include <iostream>

using namespace std;
int  printNumber(int x) {
    if (x <1) {
        return 0;
    } else {
        printNumber(x - 1);
        cout<<x;
        return 0;
    }
}int sumNumber(int y) {
    if (y == 1) {
        return 1;
} else {
return y+ sumNumber( y- 1);
cout<<y<<endl;
}

}
int printTable(int z) {
    if (z<1){
        return 0;
    }
    else{
        for(int i=1;i<=10;i++){
            cout<<z<<"*"<<i<<"="<<z*i<<endl;
        }
        return z;
    }
}
int sumDigits(int k){
    if(k==0){
        return 0;
    }
    else{
        return k%10+sumDigits(k/10);
    }
}


// Add functions definition here