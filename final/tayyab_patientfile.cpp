#include <iostream>
#include "tayyab_patientfile.h"

using namespace std;

#include <fstream>

const int MAX_EMERGENCIES = 5;

struct Patient {
    string id, name,age, gender, address, contactNumber, emergency;
};

void Emergency(Patient &patient) {

    int year,month,day;
    cout << "enter the date for appointment :\n";
    cout<<"enter year (i.e 2010 etc) :";
    cin>>year;

    while(year<2000){
        cout<<"invalid year format "<<endl;
        cout<<"enter year (like 2010 etc) :";
        cin>>year;
    }
    cout<<"enter month number (like 10 etc) :";
    cin>>month;
    if (month > 12) {
      cout<<"invalid month "<<endl;
        cout<<"enter month number (like 10 etc) :";
        cin>>month;}


    cout<<"enter day number (like 21 etc) :";
    cin>>day;
    if(month==1 ||month==3 ||month==5 ||month==7 ||month==8 ||month==10 || month==12){
        while(day>31){
            cout<<"invalid day"<<endl;
            cout<<"enter day number (like 21 etc) :";
            cin>>day;
        }
    }while(month==2 && day>28){
                cout<<"invalid day "<<endl;
                cout<<"enter day number (like 21 etc) :";
                cin>>day;
            }
    while(month == 2 && year%4==0 && day>29){
                cout<<"invalid day "<<endl;
                cout<<"enter day number (like 21 etc) :";
                cin>>day;
            }
    ofstream emergency("emergency.txt",ios::app);
    if (!emergency){
        cout<<"file not opened "<<endl;
    }
    emergency  << patient.id << '#' << patient.name << '#' << patient.age << '#' << patient.gender
                << '#' << patient.address << '#' << patient.contactNumber << '#'  << patient.emergency
            << '#'<<year;
    if(month>=10){
        emergency<<month;
    }else{
        emergency<<0<<month;
    }if(day>=10){
        emergency<<day;
    }else{
        emergency<<0<<day;
    }
    emergency<<'\n';
        emergency.close();


    cout << "=====================================\n";
    cout << "data is entered successfully 🏥\n";
    cout << "=====================================\n";
    string verify;
    cout<<"do you want to enter more data ('yes' or 'no')"<<endl;
    cin.ignore();
    getline(cin,verify);
    if (verify == "yes" || verify == "Yes" || verify == "YES" || verify == "Y" || verify == "y" ||
        verify == "\0") {
        tayyab_patient();
    }  else if (verify == "no" || verify == "No" || verify == "n" || verify == "N"){
        return;
    }else{
        cout<<"invalid input "<<endl;
    }
    return;
}


void appointment(Patient &patient) {
    string data, searchdata;
    int year,month,day,time;
    cout << "enter the date for appointment :\n";
    cout<<"enter year (i.e 2010 etc) :";
    cin>>year;

    while(year<2000){
        cout<<"invalid year format "<<endl;
        cout<<"enter year (like 2010 etc) :";
        cin>>year;
    }
    cout<<"enter month number (like 10 etc) :";
    cin>>month;
    if (month > 12) {
        cout<<"invalid month "<<endl;
        cout<<"enter month number (like 10 etc) :";
        cin>>month;}


    cout<<"enter day number (like 21 etc) :";
    cin>>day;
    if(month==1 ||month==3 ||month==5 ||month==7 ||month==8 ||month==10 || month==12){
        while(day>31){
            cout<<"invalid day"<<endl;
            cout<<"enter day number (like 21 etc) :";
            cin>>day;
        }
    }while(month==2 && day>28){
        cout<<"invalid day "<<endl;
        cout<<"enter day number (like 21 etc) :";
        cin>>day;
    }
    while(month == 2 && year%4==0 && day>29){
        cout<<"invalid day "<<endl;
        cout<<"enter day number (like 21 etc) :";
        cin>>day;
    }
    cout<<"enter your time in 24HR format (between 8 to 16) :";
    cin>>time;
    while(time>16 || time<8){
        cout<<"invalid time "<<endl;
        cout<<"enter day number (like 21 etc) :";
        cin>>time;
    }
    ifstream print("doctors_database.txt");
    if (!print) {
        cout << "file not open" << endl;
    }
    cout << "=====================================\n";

    while (!print.eof()) {
        int a=0;
        getline(print, data);
        if(data.size()>2){
        cout<<"doctor name :";}
        for (int i = 0; data[i] != '\0'; ++i) {
                if (data[i] == '#') {
                    a=a+1;
                    cout<<'\n';
                    if(a==1){cout<<"speciality :";}
                    if(a==2){
                        break;
                    }
                } else {
                    cout << data[i];
                }
        }
        if(data.size()>2) {
            cout << "\n=====================================\n";
        }
    }
    cout << "enter the name of doctor you want :" << endl;
    string doctorname;
    cin.ignore();
    getline(cin, doctorname);

    ifstream search("doctors_database.txt");

    while (!search.eof()) {
        int length = 0, matchingdata = 0;
        getline(search, searchdata);
        for (int i = 0; searchdata[i] != '#'; ++i) {
            length = length + 1;
            if (searchdata[i] == doctorname[i]) {
                matchingdata = matchingdata + 1;
            }
        }
        if (length == matchingdata) {

            ofstream appointment("appointment.txt", ios::app);
            for (int i = 0; i < length; i++) {
                appointment << searchdata[i];
            }
            appointment << patient.id << '#' << patient.name << '#' << patient.age << '#' << patient.gender
                        << '#' << patient.address << '#' << patient.contactNumber << '#'  << patient.emergency
                        << '#'<<year;
            if(month>=10){
                appointment<<month;
            }else{
                appointment<<0<<month;
            }if(day>=10){
                appointment<<day;
            }else{
                appointment<<0<<day;
            }
            appointment<<'#';
            if(time<10){
            appointment<<0<<time<<'\n';}
            else{
                appointment<<time<<'\n';
            }
            appointment.close();
        }
            else{
                cout<<"appointment already exist "<<endl;
            }
    }
    
    cout << "\n============================================\n";
    cout << "your appointment is booked successfully🩺 \n";
    cout << "============================================\n";
    cout<<"do you want to book more appointments :"<<endl;
    string verify;
    getline(cin,verify);
    if (verify == "yes" || verify == "Yes" || verify == "YES" || verify == "Y" || verify == "y" ||
        verify == "\0") {
        tayyab_patient();
    }  else if (verify == "no" || verify == "No" || verify == "n" || verify == "N"){
        return;
    }else{
    cout<<"invalid input "<<endl;
    }
    return;
}





void tayyab_patient() {

    cout << "██╗  ██╗███████╗██╗     ██╗      ██████╗      ████████═╗████████╗ ████████ ████████ ███████╗  █████═╗ ████████ " << endl;
    cout << "██║  ██║██╔════╝██║     ██║     ██╔═══██╗     ██║    ██║██║   ██║    ██║      ██║   ██╔════╝ ██   ██║    ██║   " << endl;
    cout << "███████║███████╗██║     ██║     ██║   ██║     ██║█████ ╝████████║    ██║      ██║   ███████╗ ██   ██║    ██║   " << endl;
    cout << "██╔══██║██╚════║██║     ██║     ██║   ██║     ██║       ██║   ██║    ██║      ██║   ██╚════╝ ██   ██║    ██║   " << endl;
    cout << "██║  ██║███████║███████╗███████╗╚██████╔╝     ██║       ██║   ██║    ██║   ████████╗███████║ ██   ██║    ██║   " << endl;
    cout << "╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝      ╚═╝       ╚═╝   ╚═╝    ╚═╝    ╚══════╝╚══════╝ ╚═╝  ╚═╝    ╚═╝   " << endl;
    Patient patient;

    cout << "Enter Patient ID: ";
    cin.ignore();
    getline(cin, patient.id);

    cout << "Enter Patient Name: ";
    getline(cin, patient.name);

    cout << "Enter Patient Age: ";
    cin >> patient.age;
    cin.ignore();

    cout << "Enter Patient Gender: ";
    getline(cin, patient.gender);

    cout << "Enter Patient emergency description: ";
    getline(cin, patient.emergency);

    cout << "Enter Patient Address: ";
    getline(cin, patient.address);

    cout << "Enter Patient contact number: ";
    getline(cin, patient.contactNumber);
    cout << endl << "check the data is true or not (enter 'yes' or 'no') :";
    cout << "\n=============================================\n";
    cout << "Enter Patient ID: ";
    cout << patient.id << endl;

    cout << "Enter Patient Name: ";
    cout << patient.name << endl;

    cout << "Enter Patient Age: ";
    cout << patient.age << endl;

    cout << "Enter Patient Gender: ";
    cout << patient.gender << endl;

    cout << "Enter Patient emergency description: ";
    cout << patient.emergency<<endl;

    cout << "Enter Patient Address: ";
    cout << patient.address << endl;

    cout << "Enter Patient Contact Number: ";
    cout << patient.contactNumber << endl;
    cout << "=============================================\n";
    string check;
    getline(cin,check);
    if (check == "yes" || check == "Yes" || check == "YES" || check == "Y" || check == "y" ||
        check == "\0"){
        int choice;
    cout << "\nAppointment Management System\n";
    cout << "1. emergency\n";
    cout << "2. Add Appointments\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from the buffer

    switch (choice) {
        case 1: {
            Emergency(patient);

            break;
        }
        case 2: {
            appointment(patient);
            break;
        }

        default: {
            cout << "Invalid choice. Please try again.\n";
            tayyab_patient();
        }

    }
    }
    else if (check == "no" || check == "No" || check == "n" || check == "N"){
        tayyab_patient();
    }
    else{
        cout<<"invalid input"<<endl;
    }
}