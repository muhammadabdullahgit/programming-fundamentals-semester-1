#include <iostream>
#include <string>
#include "hamza.h"
#include "tayyab.h"
#include "tehreem.h"
#include "abdullah.h"
#include "Umer_Ahmed.h"
#include "saram.h"
#include "FatimaDiscount.h"
#include "FatimanoorStaff.h"
#include "FatimaNoorAmbulance.h"
#include "daniyal.h"
#include "tayyab_patientfile.h"

using namespace std;

int main()
{

    cout << "█████████   █████   ██████╗  ██║    ██║ ███████═╗      ██████       " << endl;
    cout << "██║       ╔██   ██ ██╔═══██╗ ██║    ██║ ██║   ██║     ██║   ██      " << endl;
    cout << "██║██████ ║███████ ██║   ██║ ██║    ██║ ██║█████╝     ██║   ██      " << endl;
    cout << "██║  █ ██ ║██ ██   ██║   ██║ ██║    ██║ ██║           ███████       " << endl;
    cout << "██║  █ ██ ║██  ██  ██║   ██║ ██║    ██║ ██║           ██║   ██      " << endl;
    cout << "██║  █ ██ ║██  ██  ██║   ██║ ██║    ██║ ██║           ██║   ██      " << endl;
    cout << "██████ ██ ║██   ██ ╚██████╔╝  ███████╔╝ ██║            ██████       " << endl;
    cout << "╚═════╝   ╚═╝   ╚═╝ ╚═════╝   ╚══════╝  ╚═╝                         " << endl;
    cout << "=============================================\n";
    cout << "         Hospital Management System\n";
    cout << "=============================================\n";
    cout << "1. Laboratory\n";
    cout << "2. Doctor,Patient,chief selector and applicant as docotr\n";
    cout << "3. Car parking,Medical Inventory, Finance System\n";
    cout << "4. Patient feedback or report\n";
    cout << "5. Umer Ahmed\n";
    cout << "6. Insurance\n";
    cout << "7. Discount,Ambulance,staff\n";
    cout << "8. Bed system\n";
    cout << "0. Exit\n";
    cout << "---------------------------------------------\n";
    cout << "Enter your choice (0-8): ";
    int a = 0;
        cin>>a;
        while(a>8){
            cout<<"invalid input\n";
            cout<<"Input again\n";
            cin>>a;
        }
    switch (a)
    {
        case 0:{
            return 0;
            break;
        }
    case 1:
    {
        cout << "Welcome to our hospital." << endl;

        int choice_of_lab;
        cout << "Enter the program you want to run:" << endl;
        cout << "[1] Laboratory" << endl;
        cin >> choice_of_lab;

        switch (choice_of_lab) {
            case 1:
                lab_main();
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
            main();
        return 0;
    } // hamza
    case 2:{
            int choice;
            cout << "=====================================\n";
            cout << "   Welcome to the Medical System Menu\n";
            cout << "=====================================\n";
            cout << "1. 🩺  Doctor\n";
            cout << "2. 🏥  Patient\n";
            cout << "3. 👩‍⚕️  Chief selector\n";
            cout << "4. 👩‍💼  Applicant as doctor \n";
            cout << "-------------------------------------\n";
            cout << "Select an option (1-4): ";
            cin >> choice;

            switch(choice) {
                case 1:{
                    cout << "You selected Doctor.\n";
                    doctor();
                    // Add Doctor functionality here
                    break;}
                case 2:{
                    cout << "You selected Patient.\n";
                    tayyab_patient();
                    // Add Patient functionality here
                    break;}
                case 3:{
                    cout << "You selected Chief.\n";
                        chief_selector();
                    // Add Chief functionality here
                    break;}
                case 4:{
                    cout << "You selected applicant page.\n";
                    applicant();
                    // Add Job seeker functionality here
                    break;}
                default:{
                    cout << "Invalid choice. Please select a valid option.\n";
            }
            }
            main();
            break;

        } // tayyab
    case 3:
    {
        cout << "Select System:\n";
    cout << "1. Car Parking System\n";
    cout << "2. Medicine Inventory and Sales System\n";
    cout << "3. Finance System\n";
    cout << "Enter choice: ";

    int systemType;
    cin >> systemType;

    if (systemType == 1) {
       carParking();

        }
    else if (systemType == 2) {
        Pharmacy();
    }
    else if (systemType == 3) {
        executeEmployeeManagementSystem();
    }
     else {
        cout << "Invalid system type. Exiting the program.\n";
        return 1;
    }
main();
     break;
    } // tehreem
    case 4:
    {
        int x;
        cout<<"enter (1) to run patient feedback program and (2) to run patient report program"<<endl;
        cin>>x;
        if(x==1) {
            patientFeedback();
            break;
        }
        else if (x==2){
            patientReport();
            cout<<"you can take your test reports after 24 hours"<<endl;
            break;
        }
        else{
            cout<<"some error has occurred"<<endl;
            break;
        }
        main();
        break;
    } // abdullah
    case 5:
    {
    } // umer ahmed
    case 6:
    { string ip, k;
        saram arr[100];
        cout << "Do you have an insurance plan? (yes or no): " << endl;
        cin >> ip;
        if (ip == "yes") {
            int i;
            login(arr, i);
        } else if (ip == "no") {
            cout << "Are you interested in an insurance plan?(yes or no): " << endl;
            cin >> k;
            if (k == "yes") {

                insuranceReg(arr);
            } else if (k == "no") {
                cout << "Then we can not help you with anything else in this function" << endl;
            } else {
                cout << "Invalid input :( " << endl;
            }
        } else {
            cout << "Invalid input :(" << endl;
        }
        break;
    }
 // saram
    case 7: {
        int choice;
        cout << "enter 1 for discount\n";
        cout << "enter 2 for ambulance\n";
        cout << "enter 3 for menu for staff\n";
        switch (choice) {
            case 1: {
                applydiscount();
                break;
            }
            case 2: {
                ambulance();
                break;
            }
            case 3: {
                menuOfStaff();
                break;
            }
            default: {
                cout << "invalid input" << endl;
            }

        }
 break;   }

        // fatima
        case 8: {
            menu();
            main();
            break;
        }
        // daniyal
        default: {
            cout << "invalid input" << endl;
        }
    }
return 0;}
    
