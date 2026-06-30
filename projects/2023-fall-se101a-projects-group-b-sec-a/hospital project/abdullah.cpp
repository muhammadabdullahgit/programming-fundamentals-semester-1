#include <iostream>
# include <string>
#include <fstream>
#include"abdullah.h"
using namespace std;
struct PatientFeedback{
    string username;
    float rating{} ;
    string suggestions;
    string complete;
};
void patientFeedback(){
    cout<<"please gave us your feedback about our hospital services"<<endl;
    PatientFeedback userFeedback;
    while (true){
        cout<<"enter  (done) for not giving feedback  and exit or write agree to give feedback  "<<endl;
        getline(cin,userFeedback.complete);
        if(userFeedback.complete=="done"){
            cout<<"feedback is not given by patient"<<endl;
            break;
        }
        else if(userFeedback.complete=="agree") {
            cout << "enter your name " << endl;
            cin.ignore();
            getline(cin, userFeedback.username);
            cout << endl;
            cout << "gave rating about our hospital services from 1(very poor) to 5(very good)" << endl;
            cin >> userFeedback.rating;
            cin.ignore();
            cout << endl;
            cout << " gave some suggestions about our hospital services " << endl;
            getline(cin, userFeedback.suggestions);
            cout << endl;
            string feedbackFileName = ("feedback_") + (userFeedback.username) + (".txt");
            ofstream feedbackFile(feedbackFileName,ios ::app);
            if (feedbackFile.is_open()) {
                feedbackFile << "name of patient : " << userFeedback.username << endl;
                feedbackFile << "rating given by patient : " << userFeedback.rating << endl;
                feedbackFile << " suggestions given by patient :  " << userFeedback.suggestions << endl;
                feedbackFile.close();
                cout<<"filename is from where data is collected : "<<feedbackFileName<<endl;
                ifstream feedbackFile(feedbackFileName);
                while(!feedbackFile.eof()) {
                    string ch;
                    getline(feedbackFile, ch);
                    cout << ch;
                    cout<<endl;
                }
                break;
            }
            else {
                cout << "some error has error has occurred for creating file" << endl;
            }
            break;
        }
        else{
            cout<<"some error has occurred "<<endl;
            break;
        }
    }
    return;
}
struct PatientReport {
    string username;
    long cellNumber{};
    float rating{};
};

void patientReport() {
    cout << "following are the lists of tests " << endl;
    cout << "1.  CBC test , press 1 for it" << endl;
    cout << endl;
    cout << "2.  lipid panel test , press 2 for it" << endl;
    cout << endl;
    cout << "3.  urinalysis test , press 3 for it" << endl;
    cout << endl;
    cout << "4.  thyroid function test , press 4 for it" << endl;
    cout << endl;
    cout << "5.  liver function test , press 5 for it" << endl;
    cout << endl;
    cout << "6.  blood clotting test , press 6 for it" << endl;
    cout << endl;
    cout << "7.  X ray  test , press 7 for it" << endl;
    cout << endl;
    cout << "8.  ECG test , press 8 for it" << endl;
    cout << endl;
    cout << "9.  MRI , press 9 for it" << endl;
    cout << endl;
    cout << "10. CT scan  , press 10 for it" << endl;
    cout << endl;
    cout << "11. biopsy test , press 11 for it" << endl;
    cout << endl;
    cout << "12. EKG test , press 12 for it" << endl;
    cout << endl;
    int choice;
    cout << "enter number for test you want to perform" << endl;
    cin >> choice;
    switch (choice) {
        case 1 : {
            cout << "it costs  RS 800" << endl;
            break;
        }
        case 2: {
            cout << "it costs  RS 1900" << endl;
            break;
        }
        case 3: {
            cout << "it costs  RS 350" << endl;
            break;
        }
        case 4: {
            cout << "it costs  RS 4000" << endl;
            break;
        }
        case 5: {
            cout << "it costs  RS 1000" << endl;
            break;
        }
        case 6: {
            cout << "it costs  RS 1000" << endl;
            break;
        }
        case 7: {
            cout << "it costs  RS 800" << endl;
            break;
        }
        case 8: {
            cout << "it costs  RS 800" << endl;
            break;
        }
        case 9: {
            cout << "it costs  RS 30000" << endl;
            break;
        }
        case 10: {
            cout << "it costs  RS 20000" << endl;
            break;
        }
        case 11: {
            cout << "it costs  RS 2500" << endl;
            break;
        }
        case 12: {
            cout << "it costs  RS 1000" << endl;
            break;
        }
        default: {
            cout << "this test is not available in our hospital" << endl;
            break;
        }
    }
    PatientReport patientDetails;
    cout << "enter your name" << endl;
    getline(cin , patientDetails.username);
    cout << endl;
    cout << "enter your cell number" << endl;
    cin >> patientDetails.cellNumber;
    cout << "give rating about our services from 1(very poor) to 5(very good)" << endl;
    cin >> patientDetails.rating;
    string patientFileName = ("patient_") + (patientDetails.username) + (".txt");
    ofstream patientFile(patientFileName,ios::app);
    while (true) {
        if (patientFile.is_open()) {
            patientFile << "name of patient : " << patientDetails.username << endl;
            patientFile << "cell number of  patient : " << patientDetails.cellNumber << endl;
            patientFile << "test number patient want to perform: " << choice << endl;
            patientFile << "rating given by patient : " << patientDetails.rating << endl;
            patientFile.close();
            cout << "patient details is stored" << endl;
            break;
        }
        else {
            cout << "some error has error has occurred for creating file" << endl;
            break;
        }
    }
    while (true) {
        int choice2;
        cout << "if you want to perform more test enter (1) otherwise enter (0)" << endl;
        cin >> choice2;
        if (choice2 == 1) {
            patientReport();
            break;
        } else {
            cout<<"filename is :"<< patientFileName<<endl;
            ifstream patientFile(patientFileName);
            while(!patientFile.eof()) {
                string ch;
                getline(patientFile, ch);
                cout << ch;
                cout<<endl;
            }
            break;
        }
    }
}


