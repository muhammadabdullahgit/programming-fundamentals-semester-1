#ifndef TEHREEM_H
#define TEHREEM_H

#include <string>
#include <chrono>

#define MAX_MEDICINE_NAME_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_MEDICINES 100
#define MAX_SALES 100

using namespace std;

struct ParkingSpace {
    bool occupied;
    string licensePlate;
    chrono::time_point<chrono::system_clock> arrivalTime;
    chrono::time_point<chrono::system_clock> departureTime; // New field
};

struct Medicine {
    char name[MAX_MEDICINE_NAME_LENGTH];
    int quantity;
    float price;
};
struct Employee {
    int id;
    char name[50];
    char qualifications[50];
    double salary;
};

struct Transaction {
    char date[20];
    double amount;
    int employeeId;
};
void carParking();
int Pharmacy();
void initializeParkingSpaces(ParkingSpace parkingLot[], int numSpaces);
void parkCar(ParkingSpace parkingLot[], int numSpaces, string licensePlate);
void removeCar(ParkingSpace parkingLot[], int numSpaces, string licensePlate);
double calculateParkingCharge(double hours);
void saveParkingData(ParkingSpace parkingLot[], int numSpaces);
void loadParkingData(ParkingSpace parkingLot[], int numSpaces);
void displayParkingLot(ParkingSpace parkingLot[], int numSpaces);
void displayTotalCarsArrived(ParkingSpace parkingLot[], int numSpaces);
void displayTotalParkingCharges(ParkingSpace parkingLot[], int numSpaces);
void displayTotalSlots(int numSpaces);
void displayAvailableSlots(ParkingSpace parkingLot[], int numSpaces);

void displaySalesDetails(const Medicine sales[], int numSales);
void updateMedicineDetails(Medicine inventory[], int numMedicines);
void addNewMedicine(Medicine inventory[], int& numMedicines);
void saveMedicineToFile(const Medicine inventory[], int numMedicines);
void loadMedicineFromFile(Medicine inventory[], int& numMedicines);
void saveSalesToFile(const Medicine sales[], int numSales);
void displayInventory(const Medicine inventory[], int numMedicines);
void purchaseMedicine(Medicine* inventory, int& numMedicines, Medicine sales[], int& numSales);

bool checkAdminCredentials(const char* enteredUsername, const char* enteredPassword);

void adminMenu(Medicine inventory[], int& numMedicines, Medicine sales[], int& numSales);
void customerMenu(Medicine inventory[], int numMedicines, Medicine sales[], int& numSales);

void writeEmployeeDataToFile(const Employee employees[], int numEmployees, const char* filename);
int readEmployeeDataFromFile(Employee employees[], const char* filename);

void writeTransactionsToFile(const Transaction transactions[], int numTransactions, const char* filename);
int readTransactionsFromFile(Transaction transactions[], const char* filename);

void adminViewData(const Employee employees[], int numEmployees);
void employeeWithdrawSalary(Transaction transactions[], int& numTransactions, Employee& employee);

void executeEmployeeManagementSystem();

#endif

 
