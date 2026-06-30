
#include <iostream>
#include<fstream>
using namespace std;

struct DiscountCoupon {
    string code;
    double price;
    double discountValue;
    double finalprice;
    bool isUsed;
    int maxuses;
    int couponCost;
    int number;
};
DiscountCoupon var;
void valuedecide() {//this is for deciding the discount value
    if (var.price > 100.0) {
        var.discountValue = 0.2;  // 20% discount for higher-priced items
    } else {
        var.discountValue = 0.1;
        cout << "Discount value decided: " << (var.discountValue * 100) << "%" << endl;
    }
}
void generatecode() {
    fstream variable,variable2;
    variable.open("secondfile.txtFatimanoor", ios::in | ios::out);

    if (variable.is_open()) {
        int a;
        int i;
        char alphabet;
        int n;
        char c;
        while (variable >> n >> c >>a)  {
            i = n;
            alphabet = c;
        }
        i++;
        if (alphabet == 'z') {
            alphabet = 'a';
        } else {
            alphabet++;
        }
        var.code = to_string(i) + alphabet;
        cout << "Your code is " << var.code << endl;
        int numberofuses = 0;
      variable.close();
      variable2.open("secondfile.txtFatimanoor",ios::out|ios::app);
        variable2<<i<<" "<<alphabet<<" "<<numberofuses<<endl;
      variable2.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}
void discountCalculate() {//this is for calculating discount
    if (var.isUsed) {
        cout << "This coupon has already been used." << endl;
    } else {
        valuedecide();
        cout<<"your orignial price is ="<<var.price<<endl;
        var.finalprice = var.price - (var.price * var.discountValue);
        cout<<"Your discounted price is ="<<var.finalprice<<endl;
    }
}
void check(string cuddle) {//this is for checking if code exists or not and checking if its used or not
    fstream variable;
    variable.open("secondfile.txtFatimanoor", ios::in | ios::out);

    if (variable.is_open()) {
        fstream tempFile("temp.txt", ios::out); // Change the temporary file name
        int i;
        char alphabet;
        int usageCount;
        bool codeExists = false; // Flag to track if the code exists

        while (variable >> i >> alphabet >> usageCount) {
            var.code = to_string(i) + alphabet;

            if (cuddle == var.code) {
                codeExists = true; // Set the flag to true if the code is found
                if (usageCount < var.maxuses) {
                    var.isUsed = false;
                    cout << "Discount applied."<<endl;
                    discountCalculate();
                    usageCount++;
                    cout<<"Number of uses left= "<<var.maxuses-usageCount<<endl;
                } else {
                    var.isUsed = true;
                    cout << "Coupon code has reached its maximum uses or has already been used." << endl;
                }
            }
            tempFile << i << " " << alphabet << " " << usageCount << " " << endl;
        }
        variable.close();
        tempFile.close();
        if (!codeExists) {
            cout << "That code doesn't exist." << endl;
            remove("temp.txt");
        } else {
            // Replace the original file with the temporary file
            if (rename("temp.txt", "secondfile.txtFatimanoor") != 0) {
                cout << "Error replacing the file." << endl;
            }
        }
    } else {
        cout << "Unable to open file" << endl;
    }
}
void generatecouponCost(){
    cout<<"Cost is "<<var.couponCost<<endl;
    fstream variable;
    fstream variable2;
    variable.open("textfilefatimanoor",ios::in);
    variable2.open("temporaryfatima",ios::out|ios::app);
    if(!variable||!variable2){
        cout<<"unable to open file"<<endl;
    }else {
        variable >> var.number;
        var.number++;
        variable2 << var.number;
        variable.close();
        variable2.close();
        remove("textfilefatimanoor");
        rename("temporaryfatima", "textfilefatimanoor");
    }
}
void applydiscount() {//FUNCTION TO CALL
    char c;
    cout << "Do you have a discount coupon? (y/n): " << endl;
    cin >> c;
var.maxuses=5;
var.price=180;
var.couponCost=200;
    switch (c) {
        case 'y': {
            string cud;
           cout << "Enter your code: " << endl;
            cin >> cud;
            check(cud);
            break;
        }
        case 'n': {
            char p;
             cout<<"would u like to generate a code ?"<<endl;
            cout << "pros include=" << endl;
            cout << "10% discount on transactions lesser than 100 , 20% elsewise" << endl;
            cout << "Max number of uses are " << var.maxuses << endl;
            cout<<"Please type ur answer y/n"<<endl;
             cin>>p;
             if(p=='y'|| p=='Y') {
                 generatecouponCost();
                 cout << "Now generating your code." << endl;
                 cout<<"Max number of uses are "<<var.maxuses<<endl;
                 generatecode();
             }
            break;
        }
    }
}
