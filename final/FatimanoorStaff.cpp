
#include <iostream>
#include<fstream>
using namespace std;
//staff includes attendace,salary,types,enrollment
struct StaffMember {
    int enrollmentNumber;
    int age;
    string name;
    string type;
    double salary;
    int attendance;
};
StaffMember staff;
void saveStaffMembersToFile() {
    ifstream readLastEnrollment("fatimanoorhospital");
    if (readLastEnrollment.is_open()) {
        while (readLastEnrollment >> staff.enrollmentNumber >> staff.age >> staff.name >>
        staff.type >> staff.salary >> staff.attendance) {
            // Read the last enrollment number and move to the end of the file
        }
        readLastEnrollment.close();
    }
    staff.enrollmentNumber++;
    fstream file("fatimanoorhospital", ios::out |ios::app);

    if (!file.is_open()) {
        cout << "Error: Could not open the file for writing." << endl;
        return;
    }
    else {
        cout<<"Your enrollment number is: "<<staff.enrollmentNumber<<endl;
        cout << "Enter age: ";
        cin >> staff.age;
         // Clear the newline character from previous input
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, staff.name);
        cout << "Enter job type: ";
        cin.ignore();
        getline(cin, staff.type);
        cout << "Enter salary: ";
        cin >> staff.salary;
        staff.attendance=0;
        file<<" "<<endl;
        file << staff.enrollmentNumber << " " << staff.age << " "
        << staff.name << " " << staff.type << " " << staff.salary << " " << staff.attendance;
        file.close();
    }
}
void Readstaffmember(int roll){
    fstream file;
    file.open("fatimanoorhospital",ios::in);
    bool found=false;

    if (!file.is_open()) {
        cout << "Error: Could not open the file for writing." << endl;
        return;
    }else {
        while (file >> staff.enrollmentNumber >> staff.age >> staff.name >> staff.type
        >> staff.salary>> staff.attendance) {
            if (staff.enrollmentNumber == roll) {
                 found =  true;
                cout << "Information for Enrollment Number " << roll << endl;
                cout << "Age: " << staff.age << endl;
                cout << "Name: " << staff.name << endl;
                cout << "Job Type: " << staff.type << endl;
                cout << "Salary: " << staff.salary << endl;
                cout << "Attendance: " << staff.attendance << endl;
                cout << "-------------------------" << endl;
                break;
            }
        }
        if(!found){
            cout<<"roll number doesn't exist"<<endl;
        }
        file.close();
    }
}
void updateAttendance(int roll) {
    fstream file;
    file.open("fatimanoorhospital", ios::in | ios::out);
    bool found = false;
    if (!file.is_open()) {
        cout << "Error: Could not open the file for writing." << endl;
        return;
    } else {
        fstream tempFile("textfile", ios::out);
        while (file >> staff.enrollmentNumber >> staff.age >> staff.name >> staff.type
                    >> staff.salary >> staff.attendance) {
            if (staff.enrollmentNumber == roll) {
                found = true;
                staff.attendance++;
                cout << "Now updating attendance to " << staff.attendance << endl;
            }
            tempFile << staff.enrollmentNumber << " " << staff.age << " "
                     << staff.name << " " << staff.type << " " << staff.salary << " " << staff.attendance << endl;
        }

        file.close();
        tempFile.close();

        if (!found) {
            cout << "Roll number doesn't exist." << endl;
            remove("textfile");  // Remove the temporary file if the roll number is not found
        } else {
            // Replace the original file with the temporary file
            if (rename("textfile", "fatimanoorhospital") != 0) {
                cout << "Error replacing the file." << endl;
            }
        }
    }
}
void menuOfStaff(){
    int choice;
    do {
        cout<<" "<<endl;
        cout << "Menu:" << endl;
        cout << "1. Add a new staff member" << endl;
        cout << "2. Read staff member information" << endl;
        cout << "3. Update attendance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                saveStaffMembersToFile();
                break;
            case 2:
                int roll;
                cout<<endl;
                cout << "Enter enrollment number to read: ";
                cin >> roll;
                cout<<endl;
                Readstaffmember(roll);
                break;
            case 3:
                int rollToUpdate;
                cout<<endl;
                cout << "Enter enrollment number to update attendance: ";
                cin >> rollToUpdate;
                cout<<endl;
                updateAttendance(rollToUpdate);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
}
