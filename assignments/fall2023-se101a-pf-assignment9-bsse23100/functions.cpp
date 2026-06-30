#include "functions.h"
#include <iostream>
using namespace std;
int  q1(){
   int size,count=0;
   int arr[100][100];
   cout<<"enter size of array";
   cin>>size;

   for(int i=0;i<size;i++){
       for(int j=0;j<size;j++){
           cout<<"enter elements of array["<<i<<"]["<<j<<"]   ";
           cin>>arr[i][j];
       }
   }
   for(int k=0;k<size;k++){
       for(int l=0;l<size;l++){
           if(k==l && arr[k][l]!=1){
               count=1;
               break;
           }
           else if(k!=l && arr[k][l]!=0){
               count=1;
               break;
           }
           else {
               count=0;
               break;
           }
       }
   }
   cout<<endl;
   if(count==0){
       cout<<"it is an identity matrix"<<endl;
   }
   else{
       cout<<"it is not an identity matrix"<<endl;
   }
   return 0;
  //write your code for function q1 here
}

int q2()
{
    int size ;
    int arr[100][100];
    cout<<"enter size of array";
    cin>>size;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<"enter elements of array["<<i<<"]["<<j<<"]   ";
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    cout<<"input matrix is:"<<endl;
    cout<<endl;
    for(int k=0;k<size;k++){
        for(int l=0;l<size;l++){
            cout<<arr[k][l]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"After rotating above matrix at 90 degree is "<<endl;
    for(int m=0;m<size;m++){
        for(int n=size-1;n>=0;n--){
            cout<<arr[n][m]<<"  ";
        }
        cout<<endl;
    }

    //write your code for function q2 here
    return 0;
}

int q3()
{
    int size,count=0;
    int arr[100][100];
    cout<<"enter size of array";
    cin>>size;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<"enter elements of array["<<i<<"]["<<j<<"]   ";
            cin>>arr[i][j];
        }
    }
    for(int k=0;k<size;k++) {
        for (int l = 0; l < size; l++) {
            if (k>l && arr[k][l]!=0){
                count=1;
                break;
            }
            else{
                count=0;
                break;
            }
        }
    }
    cout<<endl;
    if(count==0){
        cout<<"it is an upper triangular matrix"<<endl;
    }
    else{
        cout<<"it is  not an upper triangular matrix"<<endl;
    }
    //write your code for function q3 here
    return 0;
}