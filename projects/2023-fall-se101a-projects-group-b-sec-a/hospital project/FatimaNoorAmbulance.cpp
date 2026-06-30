//
// Created by student on 10/16/2023.
//
#include<iostream>
#include<fstream>
using namespace std;
struct AMBULANCE{
    int ambcode;
    int ambnumber;
    char free;
};
AMBULANCE amb;
// Function to find an available ambulance
bool check(int ambcode){
    fstream ab;
    int number;
    int pcode;
    char a;
    ab.open("fatimaAmbulance", ios::in);
    while (ab >> number >> pcode >> a) {
        if (pcode == ambcode) {
            ab.close();
            return false;
        }
    }
    ab.close();
    return true;
}
void addAmbulance() {
    fstream ab, ab2;
    int number;
    int pcode;
    char a;
    ab.open("fatimaAmbulance", ios::in);
    while (ab >> number >> pcode >>a) {
        amb.ambnumber = number;
    }
    ab2.open("totalAmb", ios::in);
    amb.ambnumber++;
    amb.free='y';
    cout<<endl;
    cout << "Enter ambulance number plate: "<<endl;
    cin >> amb.ambcode;
    if(!check(amb.ambcode)){
        cout<<"number plate is already registered unable to register"<<endl;
        ab.close();
        return;
    }
    cout<<endl;
    cout << "Now storing ambulance number: " << amb.ambnumber << endl;
    ab.close();
    ab.open("fatimaAmbulance", ios::out | ios::app);
    ab << amb.ambnumber << " " << amb.ambcode << " "<<amb.free<<" "<< endl;
    ab.close();
}
// Function to display ambulance information
void Displayambulances(int &n) {
    fstream variable;
    variable.open("fatimaAmbulance", ios::in);
    variable >> amb.ambnumber >> amb.ambcode >> amb.free;
    while (variable >> amb.ambnumber >> amb.ambcode >> amb.free) {
        cout << endl;
        cout << "ambulance number " << amb.ambnumber << endl;
        cout << "number plate " << amb.ambcode << endl;
        cout<<endl;
        n++;
        if(amb.free=='y'){
            cout<<"this ambulance is available for dispatch"<<endl;
        }else {
            cout<<"this ambulance is not available for dispatch"<<endl;
        }
        cout << endl;
    }
    variable.close();
    cout<<"total number of ambulances "<<n;
    cout<<endl;
}
void dispatchAmbulance(){
    fstream file;
    file.open("fatimaAmbulance", ios::in | ios::out);
    bool found = false;
    bool dispatchOccurred = false;
    if (!file.is_open()) {
        cout << "Error: Could not open the file for writing." << endl;
        return;
    } else {
        fstream tempFile("tempAmbulance", ios::out);
        while (file >> amb.ambnumber >> amb.ambcode >> amb.free) {
            if (amb.free == 'y' && !dispatchOccurred) {
                found = true;
                amb.free = 'n';
                cout << endl;
                cout << "Now dispatching the ambulance =" << amb.ambnumber << endl;
                cout << " number plate =" << amb.ambcode;
                cout<<endl;
                dispatchOccurred = true;
            }
            tempFile << amb.ambnumber << " " << amb.ambcode << " "
                     << amb.free << endl;
        }
        //u have to process the rest of the file even if dispatch occurred
        while (file >> amb.ambnumber >> amb.ambcode >> amb.free) {
            tempFile << amb.ambnumber << " " << amb.ambcode << " "
                     << amb.free << endl;
        }
        file.close();
        tempFile.close();
        if (!found) {
            cout << "Unfortunately, no ambulance is available for dispatch" << endl;
            remove("tempAmbulance");  //now remove the temporary file if no ambulance is available
        } else {
            //replace the original file with the temporary file
            if (rename("tempAmbulance", "fatimaAmbulance") != 0) {
                cout << "Error replacing the file." << endl;
            }
        }
    }
}
void ReportAmbulanceReturn() {
    int plate;
    cout<<"enter the number plate of the ambulance that has returned"<<endl;
    cin>>plate;
    fstream file;
    file.open("fatimaAmbulance", ios::in | ios::out);
    bool found = false;
    if (!file.is_open()) {
        cout << "Error: Could not open the file for writing." << endl;
        return;
    } else {
        fstream tempFile("tempAmbulance", ios::out);
        while (file >> amb.ambnumber >> amb.ambcode>> amb.free) {
            if (amb.ambcode==plate) {
                found = true;
                amb.free='y';
                cout<<endl;
                cout<<"Ambulance's availabity has been updated successfully."<<endl;
            }
            tempFile << amb.ambnumber << " " << amb.ambcode << " "
                     << amb.free  << endl;
        }
        file.close();
        tempFile.close();
        if (!found) {
            cout << "invalid code entered" << endl;
            remove("tempAmbulance");  // Remove the temporary file if the roll number is not found
        } else {
            // Replace the original file with the temporary file
            if (rename("tempAmbulance", "fatimaAmbulance") != 0) {
                cout << "Error replacing the file." << endl;
            }
        }
    }
}
void ambulance() {
    int choice;
    do {
        // Display menu
        cout<<" \n";
        cout << "Ambulance Management System\n";
        cout << "1. Dispatch Ambulance\n";//findavailable , minus one
        cout << "2. Report Ambulance return\n";//add one to that specific
        cout << "3. Display Ambulance Information\n";//display all the ambulances
        cout << "4.Register ambulance in file\n";//add ambulances
        cout << "5. Exit\n";
        cout << "Enter your choice: \n";
        cin >> choice;
        cout<<endl;
        switch (choice) {
            case 1: {
                dispatchAmbulance();
                break;
            }
            case 2: {
                ReportAmbulanceReturn();
             break;
            }
            case 3: {
                int i=0;
                Displayambulances(i);
                 break;
            }
            case 4: {
                addAmbulance();
                break;
            }
            case 5:{
                cout<<"now exiting the program"<<endl;
                break;
            }
            default: {
                cout << "invalid input" << endl;

            }
        }
    }
    while(choice!=5);
}









