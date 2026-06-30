#include <iostream>
# include "functions.h"
using namespace std;

int main() {
    int x;
    cin >>x;
    switch (x) {
        case 1:
        {
            q1();
            break;
        }
        case 2:
        {
            q1();
            break;
        }case 3:
        {
            q3();
            break;
        }case 4:
        {
            q4();
            break;
        }
        case 5:
        {
            q5();
            break;
        }
        case 6:
        {
            q6();
            break;
        }
        default:{
            break;
        }
    }




    //Call your functions here
   
    return 0;
}
