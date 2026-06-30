
//

using namespace std;

#include <iostream>
#include <fstream>
#include "daniyal.h"

void addPatient(Patient*& patients, int& count) {
    // Increase the count of patients
    count++;

    // Allocate memory for the new patient
    Patient* newPatients = new Patient[count];

    // Copy existing patients to the new memory location
    for (int i = 0; i < count - 1; i++) {
        newPatients[i] = patients[i];
    }

    // Input details for the new patient
    Patient newPatient;
    newPatient.id = count;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, newPatient.name);
    cout << "Enter patient condition: ";
    getline(cin, newPatient.condition);

    // Add the new patient to the list
    newPatients[count - 1] = newPatient;

    // Release the old memory and update the pointer
    delete[] patients;
    patients = newPatients;

    // Save patient records to a file
    ofstream file("patient_records.txt", ios::app);
    if (file.is_open()) {
        file << newPatient.id << "," << newPatient.name << "," << newPatient.condition << "\n";
        file.close();
    }
}

void loadPatientsFromFile(Patient*& patients, int& count) {
    ifstream file("patient_records.txt");
    if (file.is_open()) {
        count = 0;
        string line;

        // Count the number of lines in the file to determine the number of patients
        while (getline(file, line)) {
            count++;
        }
        file.close();

        patients = new Patient[count];

        file.open("patient_records.txt");
        int i = 0;
        while (getline(file, line)) {
            size_t pos = 0;

            // Find the position of the first comma
            pos = line.find(',');
            if (pos == string::npos) {
                // Handle invalid data
                continue;
            }

            // Extract and store the patient's ID
            patients[i].id = stoi(line.substr(0, pos));

            // Find the position of the next comma
            size_t prevPos = pos;
            pos = line.find(',', prevPos + 1);
            if (pos == string::npos) {
                // Handle invalid data
                continue;
            }

            // Extract and store the patient's name
            patients[i].name = line.substr(prevPos + 1, pos - prevPos - 1);

            // Extract and store the patient's condition
            patients[i].condition = line.substr(pos + 1);

            i++;
        }
        file.close();
    }
}

void listPatients(const Patient* patients, int count) {
    if (count == 0) {
        cout << "No patients in the system.\n";
        return;
    }

    cout << "List of Patients:\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << patients[i].id << "\n";
        cout << "Name: " << patients[i].name << "\n";
        cout << "Condition: " << patients[i].condition << "\n\n";
    }
}

void releaseMemory(Patient* patients) {
    delete[] patients;
}


const int MaxAppointments = 50; // Maximum number of appointments

struct Appointment {
    string patientName;
    string doctorName;
    string date;
    string time;
};

Appointment appointments[MaxAppointments];
int appointmentCount = 0;

void scheduleAppointment(const string& patientName, const string& doctorName, const string& date, const string& time) {
    if (appointmentCount < MaxAppointments) {
        bool slotAvailable = true;
        for (int i = 0; i < appointmentCount; i++) {
            if (appointments[i].date == date && appointments[i].time == time) {
                slotAvailable = false;
                break;
            }
        }

        if (slotAvailable) {
            appointments[appointmentCount].patientName = patientName;
            appointments[appointmentCount].doctorName = doctorName;
            appointments[appointmentCount].date = date;
            appointments[appointmentCount].time = time;
            appointmentCount++;
            cout << "Appointment scheduled." << endl;
        } else {
            cout << "Slot at " << time << " on " << date << " is already occupied. Please choose another slot." << endl;
        }
    } else {
        cout << "Appointment slots are full." << endl;
    }
}

void viewAppointments() {
    cout << "Scheduled Appointments:" << endl;
    for (int i = 0; i < appointmentCount; i++) {
        cout << "Patient: " << appointments[i].patientName << ", Doctor: " << appointments[i].doctorName << ", Date: " << appointments[i].date << ", Time: " << appointments[i].time << endl;
    }
}

const int MAX_BEDS = 100; // Maximum number of beds in the hospital
struct Bed {
    bool occupied;
    string patientName;
};

Bed beds[MAX_BEDS]; // Statically allocated array for bed status

void initializeBeds(int numberOfBeds) {
    for (int i = 0; i < numberOfBeds; i++) {
        beds[i].occupied = false;
        beds[i].patientName = "";
    }
}

void displayBedStatus(int numberOfBeds) {
    cout << "Bed Status:\n";
    for (int i = 0; i < numberOfBeds; i++) {
        cout << "Bed " << (i + 1) << ": " << (beds[i].occupied ? "Occupied" : "Available");
        if (beds[i].occupied) {
            cout << " (Occupied by " << beds[i].patientName << ")";
        }
        cout << "\n";
    }
}

void admitPatient(int numberOfBeds) {
    int bedNumber;
    string patientName;

    cout << "Enter bed number for admission: ";
    cin >> bedNumber;

    if (bedNumber < 1 || bedNumber > numberOfBeds) {
        cout << "Invalid bed number. Please try again.\n";
        return;
    }

    if (beds[bedNumber - 1].occupied) {
        cout << "Bed " << bedNumber << " is already occupied.\n";
        return;
    }

    cout << "Enter patient name: ";
    cin.ignore(); // Clear newline character from the input buffer
    getline(cin, patientName);

    beds[bedNumber - 1].occupied = true;
    beds[bedNumber - 1].patientName = patientName;
    cout << "Patient " << patientName << " admitted to bed " << bedNumber << ".\n";
}

void dischargePatient(int numberOfBeds) {
    int bedNumber;
    cout << "Enter bed number for patient discharge: ";
    cin >> bedNumber;

    if (bedNumber < 1 || bedNumber > numberOfBeds) {
        cout << "Invalid bed number. Please try again.\n";
        return;
    }

    if (!beds[bedNumber - 1].occupied) {
        cout << "Bed " << bedNumber << " is already empty.\n";
        return;
    }

    string patientName = beds[bedNumber - 1].patientName;
    beds[bedNumber - 1].occupied = false;
    beds[bedNumber - 1].patientName = "";
    cout << "Patient " << patientName << " discharged from bed " << bedNumber << ".\n";
}
int menu(){
    Patient *patients = nullptr;
    int patientCount = 0;

    // Load patient records from the file at the start of the program
    loadPatientsFromFile(patients, patientCount);

    while (true) {
        cout << "\nHospital Reception Menu:\n";
        cout << "1. Add Patient\n";
        cout << "2. List Patients\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int decesion;
        cin >> decesion;

        switch (decesion) {
            case 1:
                addPatient(patients, patientCount);
                break;
            case 2:
                listPatients(patients, patientCount);
                break;
            case 3:
                releaseMemory(patients);
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }


    int choice;

    do {
        cout << "Appointment Scheduling System" << endl;
        cout << "1. Schedule Appointment" << endl;
        cout << "2. View Appointments" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string patientName, doctorName, date, time;
                cout << "Enter patient's name: ";
                cin >> patientName;
                cout << "Enter doctor's name: ";
                cin >> doctorName;
                cout << "Enter date (MM/DD/YYYY):" << endl;
                cin >> date;
                cout << "Enter time (HH:MM AM/PM): ";
                cin >> time;
                cout << endl;
                scheduleAppointment(patientName, doctorName, date, time);
                break;
            }
            case 2: {
                viewAppointments();
                break;
            }
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    int numberOfBeds;
    cout << "Enter the number of beds in the hospital: ";
    cin >> numberOfBeds;
    initializeBeds(numberOfBeds);

    while (true) {
        cout << "\nBed Management Menu:\n";
        cout << "1. Display Bed Status\n";
        cout << "2. Admit Patient\n";
        cout << "3. Discharge Patient\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayBedStatus(numberOfBeds);
                break;
            case 2:
                admitPatient(numberOfBeds);
                break;
            case 3:
                dischargePatient(numberOfBeds);
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }




    return 0

}
>>>>>>> 2c5bc32a1c44788f0e9edde86b342276a0f100f2
=======
>>>>>>> Stashed changes
