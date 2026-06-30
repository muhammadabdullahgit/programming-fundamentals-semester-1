#include <iostream>
#include <string>
#include<fstream>
#include "functions.h"
using namespace std;
struct LoginInfo {
    string username;
    string password;
};
void signup(){
    LoginInfo signup;
    string ch;
    cout<<"enter username"<<endl;
    cin.ignore();
    getline(cin,signup.username);
    ifstream checkFile("username.txt");
    if(!checkFile){
        cout<<"checkFile is not opened"<<endl;
    }
    while(!checkFile.eof()){
        int a=0;
        getline(checkFile,ch);
        for(int i=0;i<ch.size();i++){
            if(ch[i]==signup.username[i]){
                a=a+1;
            }
        }
        if(a==ch.size()){
            cout<<"username already exists "<<endl;
            checkFile.close();
            authentication();
            return;
        }
    }
    cout<<"enter Password"<<endl;
    getline(cin,signup.password);
    ofstream signupUsernameFile("username.txt",ios::app);
    ofstream signupPasswordFile("password.txt",ios::app);
    signupUsernameFile<<signup.username<<'\0'<<endl;
    signupPasswordFile<<signup.password<<'\0'<<endl;
    signupUsernameFile.close();
    signupPasswordFile.close();
    cout<<"account created successfully"<<endl;
    cout<<"for login enter (1) otherwise enter(0) to exit"<<endl;
    int x;
    cin>>x;
    if(x==1) {
        login();
        return;
    }
    else {
        return;
    }
}
void login() {
    LoginInfo login;
    cout << "enter username" << endl;
    cin.ignore();
    getline(cin, login.username);
    cout << "enter Password" << endl;
    getline(cin, login.password);
    ifstream loginUsernameFile("username.txt");
    if (!loginUsernameFile) {
        cout << "file is not open" << endl;
    }
    ifstream loginPasswordFile("password.txt");
    if (!loginPasswordFile) {
        cout << "file is not open" << endl;
    }
    string ch1, ch2;
    int check1 = 0, check2 = 0;
    while (!loginUsernameFile.eof()) {
        int a = 0, b = 0;
        getline(loginUsernameFile, ch1);
        getline(loginPasswordFile, ch2);
        for (int i = 0; i < ch1.size(); i++) {
            if (login.username[i] == ch1[i]) {
                a = a + 1;
            }
        }
        for (int i = 0; i < ch2.size(); i++) {
            if (login.password[i] == ch2[i]) {
                b = b + 1;
            }
        }
        if (a == ch1.size()&&a!=0) {
            check1=check1+1;
            if (b == ch2.size()&&b!=0) {
                check2=check2+1;
                cout << "login successful" << endl;
            }
        }
    }
    loginUsernameFile.close();
    loginPasswordFile.close();
        if (check1 == 0 || check2 == 0) {
            cout << "incorrect username or password" << endl;
            authentication();
        }
    return;
}
void authentication() {
    int choice;
    cout << "enter (1) for login" << endl;
    cout << "enter (2) for creating account" << endl;
    cin >> choice;
    switch (choice) {
        case 1: {
            login();
            break;
        }
        case 2:{
            signup();
            break;
        }
        default:{
            cout<<"you entered wrong choice "<<endl;
            break;
        }
    }
    return;
}