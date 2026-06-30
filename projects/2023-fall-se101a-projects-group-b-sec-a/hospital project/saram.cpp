//
// Created by Tayyab on 07/11/2023.
//
#include <sstream>
#include <fstream>
#include "saram.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int randCheck(int i, saram arr[]){//checking whether the Random number generated is already used in file
    for (int x=0; x<i; x++){
        ifstream insuranceRegs("insurance number");
        int value;
        while (insuranceRegs >> value) {
            if (arr[i].insuranceNum == value){ //If the random number was already in file then it creates a new random number
                insuranceRegs.close();
                arr[i].insuranceNum = rand() % 9000 + 1000;
                return randCheck(i, arr); //recursion:Function called so the new number can go through the same process
            }
        }
        insuranceRegs.close();
    }
    return arr[i].insuranceNum; //if the generated number isn't used in the file before then it returns this number
}
void displayReg(int i, saram arr[]){
    // Displaying registration details
    cout << "\n\nThank you for registering with us!" << endl;
    cout << "Your registration details are as follows:" << endl;
    cout << "Name: " << arr[i].fname << " " << arr[i].lname << endl;
    cout << "Age: " << arr[i].age << endl;
    cout << "Insurance Number: " << arr[i].insuranceNum << endl;
    cout << "Please remember insurance number to login next time!!!"<< endl;
    cout << "You have to pay $"<< arr[i].amount << " for your insurance"<< endl;
    cout << "you opted for "<< arr[i].plan <<endl;
    ofstream insuranceRegs("insurance number", ios::app);                     //storing details in their respective files
    insuranceRegs << arr[i].insuranceNum <<"\n";
    ofstream insuranceFile("insurance.txt", ios::app);
    insuranceFile << "Name: " << arr[i].fname <<" "<< arr[i].lname << "#" << "Age: " << arr[i].age<< "#"<<"Charges:"<< arr[i].amount<<"#"<<arr[i].plan<< "\n";
    i=i+1;                                                                    // increasing index for next registration
    ofstream write("index.txt");
    write<<i;                                                                 // storing index in the file
    write.close();
}
void insuranceReg(saram arr[]) { // the process of registering for insurance
    int i;
    string p;
    ifstream read("index.txt"); // index increases every time someone registers
    read >> i;                    // every person's details are stored in 1 index
    int package;
    cout << "Please enter your age: ";
    cin >> arr[i].age;
    if (arr[i].age >= 55) {    // checking if user is eligible for Health insurance, only under 55 are eligible
        cout << "Sorry you are not eligible for Health insurance" << endl;
    } else {
        cout << "Do you have any diseases?(yes or no)" << endl;
        cin >> p;
        if (p == "yes") {
            cout<<"Sorry you are not eligible for Health insurance"<<endl; // sick people are not eligible
        }
        else if (p == "no") { // user inputting details
            cout << "Enter your first name" << endl;
            cin >> arr[i].fname;
            cout << "Enter your last name" << endl;
            cin >> arr[i].lname;

            cout << "0 for no plan \n 1 for 1 year plan($100) \n 2 for 5 year plan($300) \n 3 for 10 year plan($700) \n 4 for lifetime plan($2000)"
                    << endl;
            cout << "choose a package: " << endl; //user chooses a package
            cin >> package;
            switch (package) {
                case 1: {
                    cout << "Congratulations!! you have selected 1 year package \n Please pay $100" << endl;
                    arr[i].amount = 100;                         //insurance charges
                    arr[i].plan = "1 year plan";                 //insurance plan
                    arr[i].insuranceNum = rand() % 9000 + 1000;  //random number generated for insurance number
                    randCheck(i, arr);                           //randcheck function called which checks if random number has been used before
                    displayReg(i, arr);                          //displayreg function called which displays insurance details and stores them in a file
                    break;
                }
                case 2: {
                    cout << "Congratulations!! you have selected 5 year package \n Please pay $300" << endl;
                    arr[i].amount = 300;                         //insurance charges
                    arr[i].plan = "5 year plan";                 //insurance plan
                    arr[i].insuranceNum = rand() % 9000 + 1000;  //random number generated for insurance number
                    randCheck(i, arr);                           //randcheck function called which checks if random number has been used before
                    displayReg(i, arr);                          //displayreg function called which displays insurance details and stores them in a file
                    break;
                }
                case 3: {
                    cout << "Congratulations!! you have selected 10 year package \n Please pay $700" << endl;
                    arr[i].amount = 700;                          //insurance charges
                    arr[i].plan = "10 year plan";                 //insurance plan
                    arr[i].insuranceNum = rand() % 9000 + 1000;  //random number generated for insurance number
                    randCheck(i, arr);                           //randcheck function called which checks if random number has been used before
                    displayReg(i, arr);                          //displayreg function called which displays insurance details and stores them in a file
                    break;
                }
                case 4: {
                    cout << "Congratulations!! you have selected lifetime package \n Please pay $2000" << endl;
                    arr[i].amount = 2000;                        //insurance charges
                    arr[i].plan = "lifetime plan";              //insurance plan
                    arr[i].insuranceNum = rand() % 9000 + 1000;  //random number generated for insurance number
                    randCheck(i, arr);                           //randcheck function called which checks if random number has been used before
                    displayReg(i, arr);                          //displayreg function called which displays insurance details and stores them in a file
                    break;
                }
                default: {
                    cout << "you didnt choose any plan" << endl;
                    break;
                }
            }
        }
        else {
            cout<< "Invalid Answer :(";
        }
    }
}
void login(saram arr[], int i) {  //login function
    int y;
    cout << "Enter your Insurance Number: ";
    cin >> y;                                                    //takes insurance number as input

    ifstream insuranceRegs("insurance number");
    ifstream insuranceFile("insurance.txt");

    int value;
    string line;
    bool found = false;

    while (insuranceRegs >> value && getline(insuranceFile, line)) {
        if (value == y) {                                           // if y = any value in the insuranceRegs file
            found = true;
            cout << "\n\nWelcome back! Your details are as follows:" << endl;
            stringstream ss(line);
            string segment;                                          //takes the line on the same index from insuranceFile file, which includes details
            int index = 0;

            while (getline(ss, segment, '#')) {                     //outputs every word till it reaches # when # is reached
                if (index >= 0) {                                   //the rest of the output moves to the next line and stops when the line ends
                    cout << segment << endl;
                }
                index++;
            }
            cout<<"you dont have to pay any dues"<<endl;

            break;
        }
    }

    insuranceRegs.close();
    insuranceFile.close();

    if (!found) {                                                   // if the insurance number added is not found
        cout << "Invalid Insurance Number. Please try again." << endl;
        login(arr, i);
    }
}
