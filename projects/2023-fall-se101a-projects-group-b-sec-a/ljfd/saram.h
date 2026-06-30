//
// Created by Tayyab on 07/11/2023.
//

#ifndef HOSPITAL_PROJECT_SARAM_H
#define HOSPITAL_PROJECT_SARAM_H
#include <string>
using namespace std;
struct saram {
    int insuranceNum;
    int age;
    string fname;
    string lname;
    int amount;
    string plan;
};
void insuranceReg(saram arr[]);
void displayReg(int i, saram arr[]);
int randCheck(int i, saram arr[]);
void login(saram arr[], int i);
#endif //HOSPITAL_PROJECT_SARAM_H
