#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include "hamza.h"
using namespace std;

void entering_results();
void checkLabResults(const string& patientName);
void labChemicals();
void readLabChemicals(const string& chemicalName);
void testRequests();
void readTestsRequests(const string& patientName);
void mergeTestRequests();

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void entering_results() {
    ofstream labResultsDataFile("lab_test_results.txt", ios::app);

    if (!labResultsDataFile) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    string patientName;
    int patientAge;
    long double totalCharges = 0.0;

    clearInputBuffer();
    cout << "Enter patient name: ";
    getline(cin, patientName);
    cout << "Enter the patient age: ";
    cin >> patientAge;
    clearInputBuffer();

    while (true) {
        string testType, result;
        long double testCharges;

        cout << "Enter test type (or 'stop' to finish entering tests): ";
        getline(cin, testType);

        if (testType == "stop" || testType == "Stop" || testType == "STOP") {
            break;
        }

        cout << "Enter test charges (in USD): ";
        cin >> testCharges;
        clearInputBuffer();
        cout << "Enter test result (Positive or Negative): ";
        getline(cin, result);

        totalCharges += testCharges;

        labResultsDataFile << "Patient Name:" << patientName << "#" << "Patient Age:" << patientAge << "#" << "Test Type:" << testType
                           << "#" << "Test Charges:" << testCharges << "#" << "Test Result:" << result << endl;
    }

    labResultsDataFile << "Total Charges:" << totalCharges << endl;

    labResultsDataFile.close();
    cout << "Test results have been saved to 'lab_test_results.txt'." << endl;
}

void checkLabResults(const string& patientName) {
    ifstream inFile("lab_test_results.txt");

    if (!inFile) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    string line;
    double totalCharges = 0.0;

    while (getline(inFile, line)) {
        size_t found = line.find("Patient Name:" + patientName + "#");
        if (found != string::npos) {
            for (int i = 0; line[i] != '\0'; i++) {
                if (line[i] == '#') {
                    cout << '\n';
                } else {
                    cout << line[i];
                }
            }
            cout << endl;
        }

        size_t totalChargesFound = line.find("Total Charges:");
        if (totalChargesFound != string::npos) {
            string totalChargesStr = line.substr(totalChargesFound + 14);
            totalCharges = stod(totalChargesStr);
        }
    }

    cout << "Total Charges for " << patientName << ": " << totalCharges << " USD" << endl;

    inFile.close();
}

void testRequests() {
    ofstream outfile("test_requests.txt", ios::app);

    if (!outfile) {
        cout << "Error: Could not open the required file" << endl;
        return;
    }

    string patientName, testType;
    int patientAge, testCharges;

    while (true) {
        cout << "Enter the name of the patient (type 'stop' to exit): ";
        cin.ignore();
        getline(cin, patientName);
        clearInputBuffer();

        if (patientName == "Stop" || patientName == "stop" || patientName == "STOP") {
            break;
        }

        cout << "Enter the test type: ";
        cin.ignore();
        getline(cin, testType);
        cout << "Enter the patient age: ";
        cin >> patientAge;
        cout<<"enter tests charges";
        cin>>testCharges;
        outfile << "Patient Name:" << patientName << "#"<< "Patient Age:" << patientAge << "#" << "Test Type:" << testType <<"#"
                << "Test Charges:" << testCharges << endl;
    }

    outfile.close();
    cout << "Test requests have been saved to 'test_requests.txt'." << endl;
}

void readTestsRequests(const string& patientName) {
    ifstream infile("test_requests.txt");
    if (!infile) {
        cout << "Error: Could not open the required file" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '#') {
                cout << '\n';
            } else {
                cout << line[i];
            }
        }

        if (line.find("Patient Name:" + patientName + "#") == 0) {
            found = true;
        }
    }

    if (!found) {
        cout << "Test request for " << patientName << " not found." << endl;
    }

    infile.close();
}


void mergeTestRequests() {
    ifstream testRequestsFile("test_requests.txt");
    ofstream labResultsDataFile("lab_test_results.txt", ios::app);

    if (!testRequestsFile || !labResultsDataFile) {
        cout << "Error: Could not open one of the files." << endl;
        return;
    }

    string line;

    cout << "Do you want to merge 'test_requests.txt' into 'lab_test_results.txt'? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        while (getline(testRequestsFile, line)) {
            labResultsDataFile << line << endl;
        }

        cout << "Merged 'test_requests.txt' into 'lab_test_results.txt'." << endl;
    } else {
        cout << "No files were merged." << endl;
    }

    testRequestsFile.close();
    labResultsDataFile.close();
}

void labChemicals() {
    ofstream ChemicalsDataFile("lab_chemicals.txt", ios::app);

    if (!ChemicalsDataFile) {
        cout << "Error: Could not open the file" << endl;
        return;
    }

    string chemicalName;
    double chemicalQuantity;

    while (true) {
        cout << "Enter the name of the chemical (type 'stop' to exit): ";
        cin.ignore();
        getline(cin, chemicalName);

        if (chemicalName == "stop" || chemicalName == "Stop" || chemicalName == "STOP") {
            break;
        }

        cout << "Enter the quantity of " << chemicalName << " (in ml): ";
        cin >> chemicalQuantity;
        ChemicalsDataFile << chemicalName << "#" << chemicalQuantity << " (ml)" << endl;
    }

    ChemicalsDataFile.close();
    cout << "Chemicals Name and Quantity have been added to the file 'lab_chemicals.txt'." << endl;
}


void readLabChemicals(const string& chemicalName){
    ifstream infile("lab_chemicals.txt");
    if (!infile) {
        cout << "Error: Could not open the required file" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '#') {
                cout << '\n';
            } else {
                cout << line[i];
            }
        }

        if (line.find(chemicalName) != string::npos) {
            found = true;
        }
    }

    if (!found) {
        cout << "Chemical: " << chemicalName << " not found." << endl;
    }

    infile.close();

}

void lab_main() {
    int choice_of_lab;
    cout << "\n************************Laboratory Terminal***************************" << endl;
    cout << "Please select one of the options below:" << endl;
    cout << "[1] Store the test results of a patient" << endl;
    cout << "[2] Check the test results of a patient" << endl;
    cout << "[3] Add the test requests of new patients" << endl;
    cout << "[4] Check the test requests of new patients" << endl;
    cout << "[5] Add the quantity of chemicals into the records" << endl;
    cout << "[6] Check the quantity of chemicals into the records" << endl;
    cout << "[7] Merge the tests requests and the lab results" << endl;

    cout << "Enter your choice: ";
    cin >> choice_of_lab;

    switch (choice_of_lab) {
        case 1:
            entering_results();
            break;
        case 2: {
            string patientName;
            cout << "Enter the patient's name to search for lab results: ";
            cin.ignore();
            getline(cin, patientName);
            checkLabResults(patientName);
        }
            break;
        case 3:
            testRequests();
            break;
        case 4: {
            string patientName;
            cout << "Enter the patient's name to search for test requests: ";
            cin.ignore();
            getline(cin, patientName);
            readTestsRequests(patientName);
        }
            break;
        case 5:
            labChemicals();
            break;
        case 6:{
            string chemicalName;
            cout << "Enter the patient's name to search for test requests: ";
            cin.ignore();
            getline(cin, chemicalName);
            readLabChemicals(chemicalName);
        }
            break;
        case 7:
            mergeTestRequests();
            break;
        default:
            cout << "Invalid choice, please try again" << endl;
            lab_main();
            break;
    }
}



void registerPatient();
;


const int MAX_PATIENTS = 100;
const int MAX_INVOICES = 100;

struct Patient {
    string name;
    int age;
    string address;
    string phone;
    string medicalHistory;
    int priority;
    bool admitted;
    string admissionDate;
    string dischargeDate;

    Patient() : name(""), age(0), address(""), phone(""), medicalHistory(""), priority(0), admitted(false), admissionDate(""), dischargeDate("") {}
};

struct Invoice {
    string patientName;
    double totalCharges;
    double totalPayments;
};

Patient patients[MAX_PATIENTS];
int numPatients = 0;
Invoice invoices[MAX_INVOICES];
int numInvoices = 0;


void registerPatient() {
    if (numPatients >= MAX_PATIENTS) {
        cout << "Patient database is full. Cannot register more patients." << endl;
        return;
    }

    Patient newPatient;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, newPatient.name);
    cout << "Enter patient age: ";
    cin >> newPatient.age;
    cin.ignore(); // Consume newline character
    cout << "Enter patient address: ";
    getline(cin, newPatient.address);
    cout << "Enter patient phone number: ";
    getline(cin, newPatient.phone);
    cout << "Enter patient medical history: ";
    getline(cin, newPatient.medicalHistory);

    patients[numPatients] = newPatient;
    numPatients++;

    // Write patient data to a file (patients.txt)
    ofstream patientFile("patients.txt", ios::app);

    if (patientFile.is_open()) {
        patientFile << "Patient Name: " << newPatient.name << " # "
                    << "Patient Age: " << newPatient.age << " # "
                    << "Patient Address: " << newPatient.address << " # "
                    << "Patient Phone number: " << newPatient.phone << " # "
                    << "Patient Medical History: " << newPatient.medicalHistory << endl;
        patientFile.close();
        cout << "Patient registered successfully." << endl;
    } else {
        cout << "Error: Could not open the patient file for writing." << endl;
    }
}

void readPatientsFromFile() {
    ifstream inFile("patients.txt");

    if (!inFile) {
        cerr << "Error: Could not open the patient file." << endl;
        return;
    }

    string line;
    string name, address, phone, medicalHistory;
    int age;
    numPatients = 0;  // Reset the patient count when reading from file

    while (getline(inFile, line)) {
        size_t found;

        found = line.find("Patient Name:");
        if (found != string::npos) {
            name = line.substr(found + 13);  // Assuming "Patient Name:" has 13 characters
            continue;
        }

        found = line.find("Patient Age:");
        if (found != string::npos) {
            age = stoi(line.substr(found + 12));
            continue;
        }

        found = line.find("Patient Address:");
        if (found != string::npos) {
            address = line.substr(found + 15);
            continue;
        }

        found = line.find("Patient Phone number:");
        if (found != string::npos) {
            phone = line.substr(found + 20);
            continue;
        }

        found = line.find("Patient Medical History:");
        if (found != string::npos) {
            medicalHistory = line.substr(found + 24);

            // Add the patient to the array
            patients[numPatients].name = name;
            patients[numPatients].age = age;
            patients[numPatients].address = address;
            patients[numPatients].phone = phone;
            patients[numPatients].medicalHistory = medicalHistory;

            numPatients++;  // Increment the number of patients
        }
    }

    inFile.close();
}

void assignPriorityLevels() {
    for (int i = 0; i < numPatients; i++) {
        // Here, you can implement your priority calculation logic based on patient's condition
        // For example, you can calculate priority levels based on age (higher age, higher priority).
        patients[i].priority = patients[i].age;
    }
}

int partition(int low, int high) {
    int pivot = patients[high].priority;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (patients[j].priority < pivot) {
            i++;
            swap(patients[i], patients[j]);
        }
    }
    swap(patients[i + 1], patients[high]);
    return i + 1;
}

void quickSortByPriority(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        quickSortByPriority(low, pivot - 1);
        quickSortByPriority(pivot + 1, high);
    }
}


void admitPatient(int patientIndex) {
    patients[patientIndex].admitted = true;

    // Get the current date
    time_t now = time(0);
    tm* current_time = localtime(&now);
    char date[11];
    strftime(date, 11, "%Y-%m-%d", current_time);
    patients[patientIndex].admissionDate = date;
}

void dischargePatient(int patientIndex) {
    patients[patientIndex].admitted = false;

    // Get the current date
    time_t now = time(0);
    tm* current_time = localtime(&now);
    char date[11];
    strftime(date, 11, "%Y-%m-%d", current_time);
    patients[patientIndex].dischargeDate = date;

    // You can also generate a discharge summary and save it to a file.
    ofstream outFile(patients[patientIndex].name + "_discharge_summary.txt");
    outFile << "Patient Name: " << patients[patientIndex].name << "\n";
    outFile << "Patient Age: " << patients[patientIndex].age << "\n";
    outFile << "Admission Date: " << patients[patientIndex].admissionDate << "\n";
    outFile << "Discharge Date: " << patients[patientIndex].dischargeDate << "\n";
    outFile << "Medical History: " << patients[patientIndex].medicalHistory << "\n";
    outFile.close();
}

void recordMedicalHistory(const string& patientName, const string& history) {
    ofstream historyFile("patient_history.txt", ios::app);

    if (!historyFile) {
        cerr << "Error: Could not open the history file." << endl;
        return;
    }

    historyFile << "Patient Name: " << patientName << " # " << "Medical History: " << history << endl;

    historyFile.close();
}

void accessMedicalHistory(const string& patientName) {
    ifstream historyFile("patient_history.txt");

    if (!historyFile) {
        cerr << "Error: Could not open the history file." << endl;
        return;
    }

    string line;

    while (getline(historyFile, line)) {
        size_t found = line.find("Patient Name: " + patientName + " #");

        if (found != string::npos) {
            cout << "Medical history for " << patientName << ":" << endl;
            cout << line.substr(found + 20) << endl;  // Assuming "Patient Name: " has 14 characters
            return;
        }
    }

    cout << "Medical history not found for " << patientName << endl;
}

void generateInvoice(const string& patientName, double totalCharges) {
    if (numInvoices >= MAX_INVOICES) {
        cout << "Invoice database is full. Cannot generate more invoices." << endl;
        return;
    }

    Invoice newInvoice;
    newInvoice.patientName = patientName;
    newInvoice.totalCharges = totalCharges;
    newInvoice.totalPayments = 0;

    invoices[numInvoices++] = newInvoice;
    cout << "Invoice generated for " << patientName << "." << endl;
}

void updateInvoiceTotal(const string& patientName, double payment) {
    for (int i = 0; i < numInvoices; i++) {
        if (invoices[i].patientName == patientName) {
            invoices[i].totalPayments += payment;
            break;
        }
    }
}

void displayInvoices() {
    for (int i = 0; i < numInvoices; i++) {
        cout << "Invoice for " << invoices[i].patientName << ":" << endl;
        cout << "Total Charges: " << invoices[i].totalCharges << " USD" << endl;
        cout << "Total Payments: " << invoices[i].totalPayments << " USD" << endl;
        cout << "Balance Due: " << (invoices[i].totalCharges - invoices[i].totalPayments) << " USD" << endl;
        cout << endl;
    }
}

void recordPayment(const string& patientName, double payment) {
    ofstream paymentFile("payments.txt", ios::app);

    if (!paymentFile) {
        cerr << "Error: Could not open the payment file." << endl;
        return;
    }

    paymentFile << "Patient Name: " << patientName << " # " << "Payment: " << payment << endl;

    paymentFile.close();
}


int emergency() {
    int choice;
    while (true) {
        cout << "Hospital Administration Menu" << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Triage Patients" << endl;
        cout << "3. Admit and Discharge Patients" << endl;
        cout << "4. Display Medical Records" << endl;
        cout << "5. Generate Bills" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                readPatientsFromFile();
                assignPriorityLevels();
                quickSortByPriority(0, numPatients - 1);

                cout << "Triage Queue (Patients ordered by priority):" << endl;

                for (int i = 0; i < numPatients; i++) {
                    cout << "Name: " << patients[i].name << ", Age: " << patients[i].age
                         << ", Priority: " << patients[i].priority << endl;
                }
                break;
            case 3:
                readPatientsFromFile();

                if (numPatients > 0) {
                    // Admitting
                    admitPatient(0);
                    cout << "Admitted patient: " << patients[0].name << endl;

                    // Discharging
                    dischargePatient(0);
                    cout << "Discharged patient: " << patients[0].name << endl;
                }

                break;
            case 4:
                while (true) {
                    int subChoice;
                    cout << "1. Record Medical History" << endl;
                    cout << "2. Access Medical History" << endl;
                    cout << "3. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    if (subChoice == 1) {
                        string patientName, history;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                        cout << "Enter patient name: ";
                        getline(cin, patientName);
                        cout << "Enter medical history: ";
                        getline(cin, history);
                        recordMedicalHistory(patientName, history);
                    } else if (subChoice == 2) {
                        string patientName;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                        cout << "Enter patient name to access medical history: ";
                        getline(cin, patientName);
                        accessMedicalHistory(patientName);
                    } else if (subChoice == 3) {
                        break;
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }

                break;
            case 5:
                while (true) {
                    int subChoice;
                    cout << "1. Record Payment" << endl;
                    cout << "2. Generate Invoice" << endl;
                    cout << "3. Display Invoices" << endl;
                    cout << "4. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    if (subChoice == 1) {
                        string patientName;
                        double payment;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter patient name: ";
                        getline(cin, patientName);
                        cout << "Enter payment amount (in USD): ";
                        cin >> payment;
                        recordPayment(patientName, payment);

                        // Update the invoice total after payment
                        updateInvoiceTotal(patientName, payment);

                        cout << "Payment recorded." << endl;
                    } else if (subChoice == 2) {
                        string patientName;
                        double totalCharges;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter patient name: ";
                        getline(cin, patientName);
                        cout << "Enter total charges (in USD): ";
                        cin >> totalCharges;
                        generateInvoice(patientName, totalCharges);
                        cout << "Invoice generated." << endl;
                    } else if (subChoice == 3) {
                        displayInvoices();
                    } else if (subChoice == 4) {
                        break;
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }

                break;
            case 6:
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
