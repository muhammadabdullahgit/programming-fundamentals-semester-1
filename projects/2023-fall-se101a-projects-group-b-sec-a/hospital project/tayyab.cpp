//
// Created by Tayyab on 07/11/2023.
//
<<<<<<< Updated upstream
#include <iostream>
#include <fstream>

using namespace std;
struct Doctor {
    string name;
    string specialty;
    int yearsOfExperience;
    string location;
    string username;
    string password;
};

#include "tayyab.h"

void chief_selector() {
    cout << "██╗  ██╗███████╗██╗     ██╗      ██████╗      ████████╗ ██╗  ██╗████████ ███████╗████████     ███████ ████████╗██╗     ███████╗████████╗████████ ██████╗   █████  " << endl;
    cout << "██║  ██║██╔════╝██║     ██║     ██╔═══██╗     ██╔═════╝ ██║  ██║   ██    ██╔════╝██║          ██║     ██╔═════╝██║     ██╔════╝██╔═════╝   ██║  ██╔═══██╗╔██   ██ " << endl;
    cout << "███████║███████╗██║     ██║     ██║   ██║     ██║       ███████║   ██    ███████╗████████     ███████║███████╗ ██║     ███████║██║         ██║  ██║   ██║║███████ " << endl;
    cout << "██╔══██║██╚════║██║     ██║     ██║   ██║     ██║       ██║  ██║   ██    ██╚════╝██║              ║██║██╚════╝ ██║     ██╚════╝██║         ██║  ██║   ██║║██ ██   " << endl;
    cout << "██║  ██║███████║███████╗███████╗╚██████╔╝     ████████╗ ██║  ██║████████╗███████║██║          ███████║███████║ ███████╗███████║████████╗   ██║  ╚██████╔╝║██  ██  " << endl;
    cout << "╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝      ╚═══════╝ ╚═╝  ╚═╝╚═══════╝╚══════╝╚═╝          ╚══════╝╚══════╝ ╚══════╝╚══════╝╚═══════╝   ╚═╝   ╚═════╝ ║██   ██ "  << endl;


    string see;
    cout << "welcome chief selector " << endl;
    ifstream read1("application.txt");
    while (!read1.eof()) {
        getline(read1, see);
        if(see.size()>3){
            cout << "\n=====================================\n";
        }
        for (int i = 0; see[i] != '\0'; ++i) {
            if (see[i] == '#') {
                cout << '\n';
            } else {
                cout << see[i];
            }
        }
//display of all candidates who have applied
    }
    cout << "\n=====================================\n";
    cout << "enter the name of successful candidate :";
    string successful_candidate;
    cin.ignore();
    getline(cin, successful_candidate);
    ifstream read2("applicant_d_username.txt");
    ifstream read3("applicant_d_password.txt");
    ifstream read4("application.txt");
    string application, username, password;
    int total_matched_name = 0;
    while (!read4.eof()) {
        int name_length = 0, matched_data = 0;
        getline(read4, application);
        getline(read2, username);
        getline(read3, password);
        for (int i = 0; application[i] != '#'; ++i) {
            name_length = name_length + 1;
            if (application[i] == successful_candidate[i]) {
                matched_data = matched_data + 1;
            }
        }
        if (matched_data == name_length) {
            total_matched_name = total_matched_name + 1;
            cout << "\n=====================================\n";

            for (int i = 0; application[i] != '\0'; ++i) {
                if (application[i] == '#') {
                    cout << '\n';
                } else {
                    cout << application[i];
                }
            }        cout << "\n=====================================\n";

            cout << endl << "please verify the person you are searching for (enter 'yes' or 'no')";
            string verify;
            cin >> verify;
            if (verify == "yes" || verify == "Yes" || verify == "YES" || verify == "Y" || verify == "y" ||
                verify == "\0") {
                ofstream write1("doctors_database.txt", ios::app);
                ofstream write2("d_password.txt", ios::app);
                ofstream write3("d_username.txt", ios::app);
                write1 << application << '\n';
                write2 << password << '\n';
                write3 << username << '\n';
                write1.close();
                write2.close();
                write3.close();
                read1.close();
                read2.close();
                read3.close();
                read4.close();
                cout << "data is stored successfully " << endl;
            } else if (verify == "no" || verify == "No" || verify == "n" || verify == "N") {
                chief_selector();
            } else {
                cout << "invalid input " << endl;
            }
        }
    }
    read1.close();
    read2.close();
    read3.close();
    read4.close();

    if (total_matched_name == 0) {
        cout << "name does not exist " << endl;
    }
    return;}


void doctor_job_application() {

    Doctor d;
    cout << "Enter your name: ";
    getline(cin, d.name);

    cout << "Enter your specialty: ";
    getline(cin, d.specialty);

    cout << "Enter years of experience: ";
    cin >> d.yearsOfExperience;

    cin.ignore();
    cout << "Enter your location: ";
    getline(cin, d.location);

    cout << "Enter a username: ";
    getline(cin, d.username);

    cout << "Enter a password: ";
    getline(cin, d.password);

    cout << "=====================================\n";
    cout << "Account created successfully!😊\n";
    cout << "=====================================\n";
    ofstream write("application.txt", ios::app);

    write << d.name << "#" << d.specialty << "#" << d.yearsOfExperience << "#" << d.location << '\n';
    write.close();
    ofstream write1("applicant_d_username.txt", ios::app);
    write1 << d.username;
    write1.close();
    ofstream write2("applicant_d_password.txt", ios::app);
    write1 << d.password;
    write2.close();


}


void applicant() {
    string answer;
    cout << "do you have any account? (yes/no): ";
    cin.ignore();
    getline(cin, answer);
    if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "Y" || answer == "y" || answer == "\0") {
        cout << "██╗      ██████╗  █████████     ████████  █████═╗     ███████═╗████████╗█████████ ███████╗   " << endl;
        cout << "██║     ██╔═══██╗ ██║              ██║   ██   ██║     ██║   ██║██║   ██║██║       ██╔════╝   " << endl;
        cout << "██║     ██║   ██║ ██║██████        ██║   ██   ██║     ██║█████╝██║   ██║██║██████ ███████╗   " << endl;
        cout << "██║     ██║   ██║ ██║  █ ██        ██║   ██   ██║     ██║      ████████║██║  █ ██ ██╚════╝   " << endl;
        cout << "███████╗ ╚█████╔╝ ██████ ██     ████████╗██   ██║     ██║      ██║   ██║██████ ██ ███████║   " << endl;
        cout << "╚══════╝  ╚════╝  ╚═════╝       ╚═══════╝╚═╝  ╚═╝     ╚═╝      ╚═╝   ╚═╝╚═════╝   ╚══════╝   " << endl;
        cout << "applicant page " << endl;
        string s, se, see, name, pass;
        cout << "enter your name :" << endl;
        getline(cin, name);
        cout << "enter your password :" << endl;
        getline(cin, pass);
        ifstream read_u("applicant_d_username.txt");
        if (!read_u) {
            cout << "file not open" << endl;
        }

        ifstream read_p("applicant_d_password.txt");

        if (!read_p) {
            cout << "file not open" << endl;
        }
        //checking for username and password
        string a_c_d_name, a_c_d_password, applicant_data;
        while (!read_u.eof()) {
            int d = 0, e = 0;
            getline(read_u, a_c_d_name);
            getline(read_p, a_c_d_password);
            cout << applicant_data << endl;
            for (int i = 0; i < a_c_d_name.size(); i++) {
                if (name[i] == a_c_d_name[i]) {
                    d = d + 1;
                }
            }

            for (int i = 0; i < a_c_d_password.size(); i++) {
                if (pass[i] == a_c_d_password[i]) {
                    e = e + 1;
                }
            }
            if (d == (a_c_d_name.size() - 1)) {
                if (e == (a_c_d_password.size() - 1)) {
                    cout << "logged in successfully " << endl;
                    ifstream read_u2("d_username.txt");
                    if (!read_u2) {
                        cout << "file not open" << endl;
                    }

                    ifstream read_p2("d_password.txt");

                    if (!read_p2) {
                        cout << "file not open" << endl;
                    }
                    //checking for username and password
                    string c_d_name, c_d_password;
                    int check = 0;
                    while (!read_u2.eof()) {
                        int d = 0, e = 0;
                        getline(read_u2, c_d_name);
                        getline(read_p2, c_d_password);
                        for (int i = 0; i < c_d_name.size(); i++) {
                            if (name[i] == c_d_name[i]) {
                                d = d + 1;
                            }
                        }

                        for (int i = 0; i < c_d_password.size(); i++) {
                            if (pass[i] == c_d_password[i]) {
                                e = e + 1;
                            }
                        }
                        if (d == (c_d_name.size() - 1)) {
                            if (e == (c_d_password.size() - 1)) {
                                cout << "=====================================\n";
                                cout << "you are selected !🎇🤩\n";
                                cout << "=====================================\n";
                                check = check + 1;
                                cout<<"login to doctors faculty using your same user name and password that you used for application login\n";
                                doctor();
                            }
                        }
                    }
                    if (check == 0) {
                        cout << "you are not selected yet " << endl;
                    }

                }
            }
        }


    } else if (answer == "no" || answer == "No" || answer == "n" || answer == "N") {
        doctor_job_application();
    } else {
        cout << "invalid input " << endl;
    }
    return;
}


void doctor_page(string doctorname) {
    cout << "██╗  ██╗███████╗██╗     ██╗      ██████╗      ████████═╗ ██████╗ ███████╗████████ ██████╗   █████   " << endl;
    cout << "██║  ██║██╔════╝██║     ██║     ██╔═══██╗     ██║    ██║██╔═══██╗██╔════╝   ██║  ██╔═══██╗╔██   ██  " << endl;
    cout << "███████║███████╗██║     ██║     ██║   ██║     ██║    ██║██║   ██║██║        ██║  ██║   ██║║███████  " << endl;
    cout << "██╔══██║██╚════║██║     ██║     ██║   ██║     ██║    ██║██║   ██║██║        ██║  ██║   ██║║██ ██    " << endl;
    cout << "██╔══██║██╚════║██║     ██║     ██║   ██║     ██║    ██║██║   ██║██║        ██║  ██║   ██║║██  ██   " << endl;
    cout << "██║  ██║███████║███████╗███████╗╚██████╔╝     █████████║╚██████╔╝███████╗   ██║  ╚██████╔╝║██   ██  " << endl;
    cout << "╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝      ╚════════╝ ╚═════╝ ╚══════╝   ╚═╝   ╚═════╝ ╚═╝   ╚═╝ "<< endl;
    int a;
    cout << "=====================================\n";
    cout << "Menu:\n";
    cout << "1. Print All Appointments\n";
    cout << "2. Search for patient\n";
    cout << "3. Print Emergency Patients\n";
    cout << "4. search Appointments by date\n";
    cout << "=====================================\n";
    cout<<"enter your choice :";
    cin >> a;
    switch (a) {
        case 1: {
            ifstream search("appointment.txt");
            string searchdata, choice;
            while (!search.eof()) {
                int length = 0, matchingdata = 0;
                getline(search, searchdata);
                for (int i = 0; doctorname[i] != '#'; ++i) {
                    length = length + 1;
                    if (searchdata[i] == doctorname[i]) {
                        matchingdata = matchingdata + 1;
                    }
                }
                int a = 0;
                if (length == matchingdata) {
                    for (int i = 0; searchdata[i] != '\0'; ++i) {
                        if (searchdata[i] == '#') {
                            a = a + 1;
                        }
                        if (a >= 1) {
                            if (searchdata[i] == '#') {
                                cout << '\n';
                                if (a == 1) { cout << "patient id :"; }
                                if (a == 2) { cout << "patient name :"; }
                                if (a == 3) { cout << "patient age :"; }
                                if (a == 4) { cout << "patient gender :"; }
                                if (a == 5) { cout << "patient emergency :"; }
                                if (a == 6) { cout << "patient  address:"; }
                                if (a == 7) { cout << "patient contact number :"; }
                                if (a == 8) { cout << "patient date :"; }
                                if (a == 9) { cout << "patient time in 24 HR format :"; }
                            } else {
                                cout << searchdata[i];
                            }
                        }
                    }
                    cout << '\n';
                    cout
                            << "============================================================================================\n";

                }
            }
            break;
        }
        case 2: {
            int a;
            cout<< "============================================================================================\n";
            cout<<"\nmenu\n";
            cout << "how would you like to search for patient :\n";
            cout << "1. search patient by id\n";
            cout << "2. search patient by name\n";
            cout<< "============================================================================================\n";
            cout << "enter your choice :";
            cin >> a;
            switch (a) {
                case 1: {
                    cout << "enter id of patient :";
                    string id;
                    cin.ignore();
                    getline(cin, id);
                    ifstream search("appointment.txt");
                    string searchdata;
                    while (!search.eof()) {
                        int length = 0, matchingdata = 0;
                        getline(search, searchdata);
                        for (int i = 0; doctorname[i] != '#'; ++i) {
                            length = length + 1;
                            if (searchdata[i] == doctorname[i]) {
                                matchingdata = matchingdata + 1;
                            }
                        }
                        int a = 0;
                        if (length == matchingdata) {
                            int ida = 0, idb = 0, k = 0;
                            for (int i = 0; searchdata[i] != '\0'; ++i) {
                                if (searchdata[i] == '#') {
                                    a = a + 1;
                                }
                                if (a == 1) {
                                    if (searchdata[i] != '#') {
                                        ida = ida + 1;
                                        if (id[k] == searchdata[i]) {
                                            idb = idb + 1;
                                        }
                                        k = k + 1;
                                    }
                                }
                            }

                            if (ida == idb) {
                                a = 0;
                                for (int i = 0; searchdata[i] != '\0'; ++i) {
                                    if (searchdata[i] == '#') {
                                        a = a + 1;
                                    }
                                    if (a >= 1) {

                                        if (searchdata[i] == '#') {
                                            cout << '\n';
                                            if (a == 1) { cout << "patient id :"; }
                                            if (a == 2) { cout << "patient name :"; }
                                            if (a == 3) { cout << "patient age :"; }
                                            if (a == 4) { cout << "patient gender :"; }
                                            if (a == 5) { cout << "patient emergency :"; }
                                            if (a == 6) { cout << "patient  address:"; }
                                            if (a == 7) { cout << "patient contact number :"; }
                                            if (a == 8) { cout << "patient date :"; }
                                            if (a == 9) { cout << "patient time in 24 HR format :"; }
                                        } else {
                                            cout << searchdata[i];
                                        }
                                    }
                                }
                            }
                            cout << "\n========================================================\n";

                        }
                    }
                    break;
                }
                case 2: {
                    cout << "enter name of patient :";
                    string id;
                    cin.ignore();
                    getline(cin, id);
                    ifstream search("appointment.txt");
                    string searchdata;

                    while (!search.eof()) {
                        int length = 0, matchingdata = 0;
                        getline(search, searchdata);
                        for (int i = 0; doctorname[i] != '#'; ++i) {
                            length = length + 1;
                            if (searchdata[i] == doctorname[i]) {
                                matchingdata = matchingdata + 1;
                            }
                        }
                        int a = 0;
                        if (length == matchingdata) {
                            int ida = 0, idb = 0, k = 0;
                            for (int i = 0; searchdata[i] != '\0'; ++i) {
                                if (searchdata[i] == '#') {
                                    a = a + 1;
                                }
                                if (a == 2) {
                                    if (searchdata[i] != '#') {
                                        ida = ida + 1;
                                        if (id[k] == searchdata[i]) {
                                            idb = idb + 1;
                                        }
                                        k = k + 1;
                                    }
                                }
                            }

                            if (ida == idb) {
                                cout << "\n========================================================\n";
                                a = 0;
                                for (int i = 0; searchdata[i] != '\0'; ++i) {
                                    if (searchdata[i] == '#') {
                                        a = a + 1;
                                    }
                                    if (a >= 1) {

                                        if (searchdata[i] == '#') {
                                            cout << '\n';
                                            if (a == 1) { cout << "patient id :"; }
                                            if (a == 2) { cout << "patient name :"; }
                                            if (a == 3) { cout << "patient age :"; }
                                            if (a == 4) { cout << "patient gender :"; }
                                            if (a == 5) { cout << "patient emergency :"; }
                                            if (a == 6) { cout << "patient  address:"; }
                                            if (a == 7) { cout << "patient contact number :"; }
                                            if (a == 8) { cout << "patient date :"; }
                                            if (a == 9) { cout << "patient time in 24 HR format :"; }
                                        } else {
                                            cout << searchdata[i];
                                        }
                                    }
                                }

                                cout << "\n========================================================\n";
                            }
                        }
                    }
                    break;
                }
                default:{
                    cout<<"invalid input"<<endl;
                }
            }
        break;}
        case 3: {
            cout << "=====================================\n";
            cout << "menu\n";
            cout << "1. search patient by id\n";
            cout << "2. search patient by name\n";
            cout << "3. print all emergency patients\n";
            cout << "=====================================\n";
            cout << "enter your choice :";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << "enter id of patient :";
                    string id;
                    cin.ignore();
                    getline(cin, id);
                    ifstream search("emergency.txt");
                    string searchdata;
                    while (!search.eof()) {
                        getline(search,searchdata);
                        int ida = 0, idb = 0;
                        for (int j = 0; searchdata[j] != '#'; ++j) {
                            ida = ida + 1;
                            if (id[j] == searchdata[j]) {
                                idb = idb + 1;
                            }
                        }
                        if (ida == idb) {
                            a = 0;
                            int k=0;
                            for (int i = 0; searchdata[i] != '\0'; ++i) {
                                if (searchdata[i] == '#') {
                                    a = a + 1;
                                }
                                if (a == 7) {
                                    k = k + 1;
                                    if (k == 6) {
                                        cout << '/';
                                    }
                                    if (k == 8) {
                                        cout << '/';
                                    }
                                }

                                if (searchdata[i] == '#') {
                                    cout << '\n';
                                    if (a == 0) { cout << "patient id :"; }
                                    if (a == 1) { cout << "patient name :"; }
                                    if (a == 2) { cout << "patient age :"; }
                                    if (a == 3) { cout << "patient gender :"; }
                                    if (a == 4) { cout << "patient emergency :"; }
                                    if (a == 5) { cout << "patient  address:"; }
                                    if (a == 6) { cout << "patient contact number :"; }
                                    if (a == 7) { cout << "patient date :"; }
                                } else {
                                    cout << searchdata[i];
                                }
                            }
                            cout<< "\n============================================================================================\n";

                        }

                    }
               break; }

                case 3: {
                    cout << "menu\n";
                    cout << "how would you like to search for patient :" << endl;


                    ifstream emergencyfile("emergency.txt");

                    if (!emergencyfile) {
                        cout << "file not opened " << endl;
                    }
                    string data;
                    cout
                            << "\n============================================================================================\n";
                    while (!emergencyfile.eof()) {
                        a = 0;
                        int k = 0;
                        getline(emergencyfile, data);
                        for (int i = 0; data[i] != '\0'; ++i) {
                            if (data[i] == '#') {
                                a = a + 1;
                            }
                            if (a == 7) {
                                k = k + 1;
                                if (k == 6) {
                                    cout << '/';
                                }
                                if (k == 8) {
                                    cout << '/';
                                }
                            }

                            if (data[i] == '#') {
                                cout << '\n';
                                if (a == 0) { cout << "patient id :"; }
                                if (a == 1) { cout << "patient name :"; }
                                if (a == 2) { cout << "patient age :"; }
                                if (a == 3) { cout << "patient gender :"; }
                                if (a == 4) { cout << "patient emergency :"; }
                                if (a == 5) { cout << "patient  address:"; }
                                if (a == 6) { cout << "patient contact number :"; }
                                if (a == 7) { cout << "patient date :"; }
                            } else {
                                cout << data[i];
                            }
                        }

                        cout
                                << "\n============================================================================================\n";

                    }
                    break;
                }


            }
        }

                case 4: {
                    cout << "=====================================\n";
                    cout << "Menu:\n";
                    cout << "1. Print today or specific date appointment \n";
                    cout << "2. Search print future appointment\n";
                    cout << "3. Print past appointment\n";
                    cout<<"how would you like to search appointment for \n";
                    cout << "=====================================\n";
                    cout<<"enter your choice :";
                    int a;
                    cin>>a;
                    switch (a) {
                        case 1:{
                            cout<<"enter today date \n";
                    int year,month,day,entered_date=0;
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
                    entered_date=(year*100)+month;
                    entered_date=(entered_date*100)+day;

                    ifstream search("appointment.txt");
                    string searchdata, choice;
                    int dat,realdate=0;
                    while (!search.eof()) {
                        int length = 0, matchingdata = 0;
                        getline(search, searchdata);
                        for (int i = 0; doctorname[i] != '#'; ++i) {
                            length = length + 1;
                            if (searchdata[i] == doctorname[i]) {
                                matchingdata = matchingdata + 1;
                            }
                        }
                        int a = 0;
                        if (length == matchingdata) {
                            for (int i = 0; searchdata[i] != '\0'; ++i) {
                                if (searchdata[i] == '#') {
                                    a = a + 1;
                                }
                                char date ;
                                if (a >= 1) {
                                    if(a==8) {
                                        if(searchdata[i+1]!='#'){
                                            date = searchdata[i+1];
                                            cout<< searchdata[i+1]<<endl;
                                            cout << "date" << date << endl;
                                    dat=date-'0';
                                    realdate=(realdate * 10 )+dat;

                                    }
                                    }
                                    if(a==9){
                                        if(realdate==entered_date){
                                             int k=0;
                                            a=0;
                                    for (int i = 0; searchdata[i] != '\0'; ++i) {
                                        if (searchdata[i] == '#') {
                                            a = a + 1;
                                        }
                                        if(a==8){
                                            k=k+1;
                                            if(k==6){
                                                cout<<'/';
                                            }if(k==8){
                                                cout<<'/';
                                            }
                                        }
                                        if (a >= 1) {
                                            if (searchdata[i] == '#') {
                                                cout << '\n';
                                                if (a == 1) { cout << "patient id :"; }
                                                if (a == 2) { cout << "patient name :"; }
                                                if (a == 3) { cout << "patient age :"; }
                                                if (a == 4) { cout << "patient gender :"; }
                                                if (a == 5) { cout << "patient emergency :"; }
                                                if (a == 6) { cout << "patient  address:"; }
                                                if (a == 7) { cout << "patient contact number :"; }
                                                if (a == 8) { cout << "patient date :"; }
                                                if (a == 9) { cout << "patient time in 24 HR format :"; }
                                            } else {
                                                cout << searchdata[i];
                                            }
                                        }
                                    }
                                    cout << '\n';
                                    cout
                                            << "============================================================================================\n";
                            }
                    }
                                }
                            }
                }
                    }
                    break;                }
                    case 2:{
                        cout<<"enter today date \n";
                        int year,month,day,entered_date=0;
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
                        entered_date=(year*100)+month;
                        entered_date=(entered_date*100)+day;

                        ifstream search("appointment.txt");
                        string searchdata, choice;
                        int dat,realdate=0;
                        while (!search.eof()) {
                            int length = 0, matchingdata = 0;
                            getline(search, searchdata);
                            for (int i = 0; doctorname[i] != '#'; ++i) {
                                length = length + 1;
                                if (searchdata[i] == doctorname[i]) {
                                    matchingdata = matchingdata + 1;
                                }
                            }
                            int a = 0;
                            if (length == matchingdata) {
                                for (int i = 0; searchdata[i] != '\0'; ++i) {
                                    if (searchdata[i] == '#') {
                                        a = a + 1;
                                    }
                                    char date ;
                                    if (a >= 1) {
                                        if(a==8) {
                                            if(searchdata[i+1]!='#'){
                                                date = searchdata[i+1];
                                                cout<< searchdata[i+1]<<endl;
                                                cout << "date" << date << endl;
                                                dat=date-'0';
                                                realdate=(realdate * 10 )+dat;

                                            }
                                        }
                                        if(a==9){
                                            if(realdate>entered_date){
                                                int k=0;
                                                a=0;
                                                for (int i = 0; searchdata[i] != '\0'; ++i) {
                                                    if (searchdata[i] == '#') {
                                                        a = a + 1;
                                                    }
                                                    if(a==8){
                                                        k=k+1;
                                                        if(k==6){
                                                            cout<<'/';
                                                        }if(k==8){
                                                            cout<<'/';
                                                        }
                                                    }
                                                    if (a >= 1) {
                                                        if (searchdata[i] == '#') {
                                                            cout << '\n';
                                                            if (a == 1) { cout << "patient id :"; }
                                                            if (a == 2) { cout << "patient name :"; }
                                                            if (a == 3) { cout << "patient age :"; }
                                                            if (a == 4) { cout << "patient gender :"; }
                                                            if (a == 5) { cout << "patient emergency :"; }
                                                            if (a == 6) { cout << "patient  address:"; }
                                                            if (a == 7) { cout << "patient contact number :"; }
                                                            if (a == 8) { cout << "patient date :"; }
                                                            if (a == 9) { cout << "patient time in 24 HR format :"; }
                                                        } else {
                                                            cout << searchdata[i];
                                                        }
                                                    }
                                                }
                                                cout << '\n';
                                                cout
                                                        << "============================================================================================\n";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;                }
                        case 3:{
                            cout<<"enter today date \n";
                            int year,month,day,entered_date=0;
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
                            entered_date=(year*100)+month;
                            entered_date=(entered_date*100)+day;

                            ifstream search("appointment.txt");
                            string searchdata, choice;
                            int dat,realdate=0;
                            while (!search.eof()) {
                                int length = 0, matchingdata = 0;
                                getline(search, searchdata);
                                for (int i = 0; doctorname[i] != '#'; ++i) {
                                    length = length + 1;
                                    if (searchdata[i] == doctorname[i]) {
                                        matchingdata = matchingdata + 1;
                                    }
                                }
                                int a = 0;
                                if (length == matchingdata) {
                                    for (int i = 0; searchdata[i] != '\0'; ++i) {
                                        if (searchdata[i] == '#') {
                                            a = a + 1;
                                        }
                                        char date ;
                                        if (a >= 1) {
                                            if(a==8) {
                                                if(searchdata[i+1]!='#'){
                                                    date = searchdata[i+1];
                                                    cout<< searchdata[i+1]<<endl;
                                                    cout << "date" << date << endl;
                                                    dat=date-'0';
                                                    realdate=(realdate * 10 )+dat;

                                                }
                                            }
                                            if(a==9){
                                                if(realdate<entered_date){
                                                    int k=0;
                                                    a=0;
                                                    for (int i = 0; searchdata[i] != '\0'; ++i) {
                                                        if (searchdata[i] == '#') {
                                                            a = a + 1;
                                                        }
                                                        if(a==8){
                                                            k=k+1;
                                                            if(k==6){
                                                                cout<<'/';
                                                            }if(k==8){
                                                                cout<<'/';
                                                            }
                                                        }
                                                        if (a >= 1) {
                                                            if (searchdata[i] == '#') {
                                                                cout << '\n';
                                                                if (a == 1) { cout << "patient id :"; }
                                                                if (a == 2) { cout << "patient name :"; }
                                                                if (a == 3) { cout << "patient age :"; }
                                                                if (a == 4) { cout << "patient gender :"; }
                                                                if (a == 5) { cout << "patient emergency :"; }
                                                                if (a == 6) { cout << "patient  address:"; }
                                                                if (a == 7) { cout << "patient contact number :"; }
                                                                if (a == 8) { cout << "patient date :"; }
                                                                if (a == 9) { cout << "patient time in 24 HR format :"; }
                                                            } else {
                                                                cout << searchdata[i];
                                                            }
                                                        }
                                                    }
                                                    cout << '\n';
                                                    cout
                                                            << "============================================================================================\n";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;                }
                        default:{
                            cout<<"invalid input"<<endl;
                        }
                    }
                }

                default: {
                    cout << "invalid input\n";

                }
            }
}

            void doctor() {
                //taking credentials for login
                cout << "██╗      ██████╗  █████████     ████████  █████═╗     ███████═╗████████╗█████████ ███████╗   "<< endl;
                cout << "██║     ██╔═══██╗ ██║              ██║   ██   ██║     ██║   ██║██║   ██║██║       ██╔════╝   "<< endl;
                cout << "██║     ██║   ██║ ██║██████        ██║   ██   ██║     ██║█████╝██║   ██║██║██████ ███████╗   "<< endl;
                cout << "██║     ██║   ██║ ██║  █ ██        ██║   ██   ██║     ██║      ████████║██║  █ ██ ██╚════╝   "<< endl;
                cout << "███████╗ ╚█████╔╝ ██████ ██     ████████╗██   ██║     ██║      ██║   ██║██████ ██ ███████║   "<< endl;
                cout << "╚══════╝  ╚════╝  ╚═════╝       ╚═══════╝             ╚═╝      ╚═╝   ╚═╝╚═════╝   ╚══════╝   "<< endl;
                cout << "welcome to doctors portal " << endl;
                cout << "enter your name :";
                string d_name, d_password, c_d_name, c_d_password, databasecarrier;
                cin.ignore();
                getline(cin, d_name);

                cout << "enter your password :";
                getline(cin, d_password);
                ifstream database("doctors_database.txt");
                if (!database) {
                    cout << "file not open" << endl;
                }
                //opening of file and checking if they are open or not
                ifstream read_u("d_username.txt");
                if (!read_u) {
                    cout << "file not open" << endl;
                }

                ifstream read_p("d_password.txt");

                if (!read_p) {
                    cout << "file not open" << endl;
                }
                //checking for username and password

                while (!read_u.eof()) {
                    int d = 0, e = 0;
                    getline(read_u, c_d_name);
                    getline(read_p, c_d_password);
                    getline(database, databasecarrier);
                    for (int i = 0; i < c_d_name.size(); i++) {
                        if (d_name[i] == c_d_name[i]) {
                            d = d + 1;
                        }
                    }

                    for (int i = 0; i < c_d_password.size(); i++) {
                        if (d_password[i] == c_d_password[i]) {
                            e = e + 1;
                        }
                    }
                    if (d == (c_d_name.size() - 1)) {
                        if (e == (c_d_password.size() - 1)) {
                            doctor_page(databasecarrier);

                        }
                    }
                }
            return;}



=======

#include "tayyab.h"
>>>>>>> Stashed changes
