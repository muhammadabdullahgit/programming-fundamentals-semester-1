#include "tehreem.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
const string PARKING_DATA_FILE = "parking_data.txt";
const string ARRIVAL_TIME_FILE = "arrival_time.txt";

void carParking()
{
    // Car Parking System
    const int numSpaces = 5;
    ParkingSpace parkingLot[numSpaces];


    int choice;
    string licensePlate;

    do
    {
        cout << "Car Parking System Menu:" << endl;
        cout << "1. Park a Car" << endl;
        cout << "2. Remove a Car" << endl;
        cout << "3. Display Parking Lot Status" << endl;
        cout << "4. Display Total Cars Arrived" << endl;
        cout << "5. Display Total Parking Charges" << endl;
        cout << "6. Display Total Slots" << endl;
        cout << "7. Display Available Slots" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter license plate of the car: ";
            cin >> licensePlate;
            parkCar(parkingLot, numSpaces, licensePlate);
            break;
        case 2:
            cout << "Enter license plate of the car to remove: ";
            cin >> licensePlate;
            removeCar(parkingLot, numSpaces, licensePlate);
            break;
        case 3:
            displayParkingLot(parkingLot, numSpaces);
            break;
        case 4:
            displayTotalCarsArrived(parkingLot, numSpaces);
            break;
        case 5:
            displayTotalParkingCharges(parkingLot, numSpaces);
            break;
        case 6:
            displayTotalSlots(numSpaces);
            break;
        case 7:
            displayAvailableSlots(parkingLot, numSpaces);
            break;
        case 0:
            cout << "Exiting the Car Parking System. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }while (choice != 0);
}

int Pharmacy()
{
    // Medicine Inventory and Sales System
    Medicine inventory[MAX_MEDICINES];
    Medicine sales[MAX_SALES];

    int numMedicines = 0; // Initial number of medicines in the inventory
    int numSales = 0;     // Initial number of sales

    // Main menu
    int userType;
    cout << "Select user type:\n";
    cout << "1. Admin\n";
    cout << "2. Customer\n";
    cout << "Enter choice: ";
    cin >> userType;

    if (userType == 1)
    {
        // Get admin credentials
        char enteredUsername[MAX_USERNAME_LENGTH];
        char enteredPassword[MAX_PASSWORD_LENGTH];

        cout << "Enter admin username: ";
        if (!(cin >> enteredUsername) || strlen(enteredUsername) >= MAX_USERNAME_LENGTH)
        {
            cout << "Invalid username. Exiting the program.\n";
            return 1;
        }

        cout << "Enter admin password: ";
        if (!(cin >> enteredPassword) || strlen(enteredPassword) >= MAX_PASSWORD_LENGTH)
        {
            cout << "Invalid password. Exiting the program.\n";
            return 1;
        }

        // Check admin credentials
        if (!checkAdminCredentials(enteredUsername, enteredPassword))
        {
            cout << "Invalid admin credentials. Exiting the program.\n";
            return 1;
        }

        // Continue with the program for a valid admin
        adminMenu(inventory, numMedicines, sales, numSales);
    }
    else if (userType == 2)
    {
        customerMenu(inventory, numMedicines, sales, numSales);
    }
    else
    {
        cout << "Invalid user type. Exiting the program.\n";
        return 1;
    }
    return 0;
}

void initializeParkingSpaces(ParkingSpace parkingLot[], int numSpaces)
{
    for (int i = 0; i < numSpaces; ++i)
    {
        parkingLot[i].occupied = false;
    }
}

void parkCar(ParkingSpace parkingLot[], int numSpaces, string licensePlate)
{
    for (int i = 0; i < numSpaces; ++i)
    {
        if (!parkingLot[i].occupied)
        {
            parkingLot[i].occupied = true;
            parkingLot[i].licensePlate = licensePlate;
            parkingLot[i].arrivalTime = chrono::system_clock::now();
            saveParkingData(parkingLot, numSpaces);
            cout << "Car with license plate " << licensePlate << " parked successfully in space " << i + 1 << endl;
            return;
        }
    }
    cout << "Sorry, parking lot is full. Cannot park the car." << endl;
}

void removeCar(ParkingSpace parkingLot[], int numSpaces, string licensePlate)
{
    for (int i = 0; i < numSpaces; ++i)
    {
        if (parkingLot[i].occupied && parkingLot[i].licensePlate == licensePlate)
        {
            parkingLot[i].departureTime = chrono::system_clock::now(); // Record departure time
            auto duration = parkingLot[i].departureTime - parkingLot[i].arrivalTime;
            double hoursParked = chrono::duration_cast<chrono::hours>(duration).count();
            double parkingCharge = calculateParkingCharge(hoursParked);

            cout << "Receipt for car with license plate " << licensePlate << endl;
            cout << "------------------------------------" << endl;
            cout << fixed << setprecision(2);
            cout << "Hours parked: " << hoursParked << endl;
            cout << "Parking charge: $" << parkingCharge << endl;
            cout << "Arrival time: " << chrono::system_clock::to_time_t(parkingLot[i].arrivalTime) << endl;
            cout << "Departure time: " << chrono::system_clock::to_time_t(parkingLot[i].departureTime) << endl;
            cout << "------------------------------------" << endl;

            parkingLot[i].occupied = false;
            saveParkingData(parkingLot, numSpaces);

            cout << "Car with license plate " << licensePlate << " removed from space " << i + 1 << endl;
            cout << "Have a nice day!" << endl;
            return;
        }
    }
    cout << "Car with license plate " << licensePlate << " not found in the parking lot." << endl;
}

double calculateParkingCharge(double hours)
{
    const double hourlyRate = 2.5;
    // Round up to the nearest hour
    int roundedHours = static_cast<int>(ceil(hours));
    return roundedHours * hourlyRate;
}

void saveParkingData(ParkingSpace parkingLot[], int numSpaces)
{
    ofstream parkingDataFile(PARKING_DATA_FILE);
    ofstream arrivalTimeFile(ARRIVAL_TIME_FILE);

    if (parkingDataFile.is_open() && arrivalTimeFile.is_open())
    {
        for (int i = 0; i < numSpaces; ++i)
        {
            if (parkingLot[i].occupied)
            {
                parkingDataFile << parkingLot[i].licensePlate << endl;
                arrivalTimeFile << chrono::system_clock::to_time_t(parkingLot[i].arrivalTime) << endl;
            }
            else
            {
                parkingDataFile << "EMPTY" << endl;
                arrivalTimeFile << "0" << endl; // Use 0 for EMPTY
            }
        }

        parkingDataFile.close();
        arrivalTimeFile.close();
    }
    else
    {
        cerr << "Unable to open files for writing." << endl;
    }
}

void loadParkingData(ParkingSpace parkingLot[], int numSpaces)
{
    ifstream parkingDataFile(PARKING_DATA_FILE);
    ifstream arrivalTimeFile(ARRIVAL_TIME_FILE);

    if (parkingDataFile.is_open() && arrivalTimeFile.is_open())
    {
        for (int i = 0; i < numSpaces; ++i)
        {
            parkingDataFile >> parkingLot[i].licensePlate;

            time_t arrivalTime;
            arrivalTimeFile >> arrivalTime;
            parkingLot[i].arrivalTime = chrono::system_clock::from_time_t(arrivalTime);

            if (parkingLot[i].licensePlate != "EMPTY")
            {
                parkingLot[i].occupied = true;
            }
            else
            {
                parkingLot[i].occupied = false;
            }
        }

        parkingDataFile.close();
        arrivalTimeFile.close();
    }
    else
    {
        cout << "Unable to open files for reading. Starting with an empty parking lot." << endl;
        initializeParkingSpaces(parkingLot, numSpaces);
    }
}

void displayParkingLot(ParkingSpace parkingLot[], int numSpaces)
{
    cout << "Parking Lot Status:" << endl;
    for (int i = 0; i < numSpaces; ++i)
    {
        cout << "Space " << i + 1 << ": ";
        if (parkingLot[i].occupied)
        {
            cout << "Occupied" << endl;
        }
        else
        {
            cout << "Empty" << endl;
        }
    }
}

void displayTotalCarsArrived(ParkingSpace parkingLot[], int numSpaces)
{
    int totalCarsArrived = 0;
    for (int i = 0; i < numSpaces; ++i)
    {
        if (parkingLot[i].occupied)
        {
            totalCarsArrived++;
        }
    }
    cout << "Total number of cars arrived: " << totalCarsArrived << endl;
}

void displayTotalParkingCharges(ParkingSpace parkingLot[], int numSpaces)
{
    double totalParkingCharges = 0;
    for (int i = 0; i < numSpaces; ++i)
    {
        if (!parkingLot[i].occupied)
        {
            continue; // Skip empty spaces
        }

        auto currentTime = chrono::system_clock::now();
        auto duration = currentTime - parkingLot[i].arrivalTime;
        double hoursParked = chrono::duration_cast<chrono::hours>(duration).count();
        double parkingCharge = calculateParkingCharge(hoursParked);
        totalParkingCharges += parkingCharge;
    }
    cout << "Total parking charges: $" << totalParkingCharges << endl;
}

void displayTotalSlots(int numSpaces)
{
    cout << "Total number of slots: " << numSpaces << endl;
}

void displayAvailableSlots(ParkingSpace parkingLot[], int numSpaces)
{
    int availableSlots = 0;
    for (int i = 0; i < numSpaces; ++i)
    {
        if (!parkingLot[i].occupied)
        {
            availableSlots++;
        }
    }
    cout << "Available slots: " << availableSlots << endl;
}
bool checkAdminCredentials(const char *enteredUsername, const char *enteredPassword)
{
    ifstream file("admin_credentials.txt");
    if (file.is_open())
    {
        char storedUsername[MAX_USERNAME_LENGTH];
        char storedPassword[MAX_PASSWORD_LENGTH];

        // Read admin credentials from file
        file >> storedUsername >> storedPassword;

        file.close();

        // Compare entered credentials with stored credentials
        return (strcmp(enteredUsername, storedUsername) == 0 && strcmp(enteredPassword, storedPassword) == 0);
    }
    else
    {
        cout << "Unable to open the admin credentials file.\n";
        return false;
    }
}

// Function to display sales details
void displaySalesDetails(const Medicine sales[], int numSales)
{
    cout << "Sales Details:\n";
    for (int i = 0; i < numSales; ++i)
    {
        cout << "Medicine: " << sales[i].name << ", Quantity: " << sales[i].quantity << ", Price: $" << sales[i].price << "\n";
    }
}

// Function to update medicine details
void updateMedicineDetails(Medicine inventory[], int numMedicines)
{
    cout << "Enter the name of the medicine to update: ";
    char searchName[MAX_MEDICINE_NAME_LENGTH];
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < numMedicines; ++i)
    {
        if (strcmp(inventory[i].name, searchName) == 0)
        {
            found = true;
            cout << "Enter the new quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter the new price: ";
            cin >> inventory[i].price;
            cout << "Medicine details updated.\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Medicine not found.\n";
    }
}

// Function to add a new medicine
void addNewMedicine(Medicine inventory[], int &numMedicines)
{
    if (numMedicines < MAX_MEDICINES)
    {
        cout << "Enter the name of the new medicine: ";
        cin >> inventory[numMedicines].name;
        cout << "Enter the quantity: ";
        cin >> inventory[numMedicines].quantity;
        cout << "Enter the price: ";
        cin >> inventory[numMedicines].price;

        ++numMedicines;

        cout << "New medicine added.\n";
    }
    else
    {
        cout << "Maximum number of medicines reached.\n";
    }
}

// Function to save medicine to a file
void saveMedicineToFile(const Medicine inventory[], int numMedicines)
{
    ofstream file("medicine.txt");
    if (file.is_open())
    {
        for (int i = 0; i < numMedicines; ++i)
        {
            file << inventory[i].name << " " << inventory[i].quantity << " " << inventory[i].price << "\n";
        }
        file.close();
        cout << "Medicine data saved to file.\n";
    }
    else
    {
        cout << "Unable to open the file.\n";
    }
}

// Function to load medicine from a file
void loadMedicineFromFile(Medicine inventory[], int &numMedicines)
{
    ifstream file("medicine.txt");
    if (file.is_open())
    {
        numMedicines = 0; // Reset numMedicines before loading from the file
        while (file >> inventory[numMedicines].name >> inventory[numMedicines].quantity >> inventory[numMedicines].price)
        {
            ++numMedicines;
            if (numMedicines >= MAX_MEDICINES)
            {
                break;
            }
        }
        file.close();
        cout << "Medicine data loaded from file.\n";
    }
    else
    {
        cout << "Unable to open the file. Starting with an empty inventory.\n";
    }
}

// Function to save sales to a file
void saveSalesToFile(const Medicine sales[], int numSales)
{
    ofstream file("sales.txt");
    if (file.is_open())
    {
        for (int i = 0; i < numSales; ++i)
        {
            file << sales[i].name << " " << sales[i].quantity << " " << sales[i].price << "\n";
        }
        file.close();
        cout << "Sales data saved to file.\n";
    }
    else
    {
        cout << "Unable to open the file.\n";
    }
}

// Function to display medicine inventory
void displayInventory(const Medicine inventory[], int numMedicines)
{
    // Load medicine data from file
    Medicine tempInventory[MAX_MEDICINES];
    int tempNumMedicines = 0;
    loadMedicineFromFile(tempInventory, tempNumMedicines);

    cout << "Medicine Inventory:\n";
    for (int i = 0; i < tempNumMedicines; ++i)
    {
        cout << "Medicine: " << tempInventory[i].name << ", Quantity: " << tempInventory[i].quantity << ", Price: $" << tempInventory[i].price << "\n";
    }
}

// Function to allow the customer to purchase medicine
void purchaseMedicine(Medicine inventory[], int &numMedicines, Medicine sales[], int &numSales)
{
    // Load medicine data from file
    loadMedicineFromFile(inventory, numMedicines);

    cout << "Enter the name of the medicine to purchase: ";
    char purchaseName[MAX_MEDICINE_NAME_LENGTH];
    cin >> purchaseName;

    bool found = false;
    for (int i = 0; i < numMedicines; ++i)
    {
        if (strcmp(inventory[i].name, purchaseName) == 0 && inventory[i].quantity > 0)
        {
            found = true;

            int purchaseQuantity;
            cout << "Enter the quantity to purchase: ";
            cin >> purchaseQuantity;

            if (purchaseQuantity <= inventory[i].quantity)
            {
                // Record the sale
                strcpy(sales[numSales].name, inventory[i].name);
                sales[numSales].quantity = purchaseQuantity;
                sales[numSales].price = inventory[i].price * purchaseQuantity;

                // Update inventory
                inventory[i].quantity -= purchaseQuantity;

                ++numSales;

                cout << "Purchase successful. Total cost: $" << sales[numSales - 1].price << "\n";

                // Save sales to file immediately after each purchase
                saveSalesToFile(sales, numSales);
                // Save updated inventory to file after each purchase
                saveMedicineToFile(inventory, numMedicines);
            }
            else
            {
                cout << "Not enough quantity available.\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "Medicine not found or not available.\n";
    }
}
void loadSalesFromFile(Medicine sales[], int &numSales)
{
    ifstream file("sales.txt");
    if (file.is_open())
    {
        while (file >> sales[numSales].name >> sales[numSales].quantity >> sales[numSales].price)
        {
            ++numSales;
            if (numSales >= MAX_SALES)
            {
                break;
            }
        }
        file.close();
        cout << "Sales data loaded from file.\n";
    }
    else
    {
        cout << "Unable to open the file. Starting with an empty sales record.\n";
    }
}
// Admin menu
void adminMenu(Medicine inventory[], int &numMedicines, Medicine sales[], int &numSales)
{
    loadMedicineFromFile(inventory, numMedicines);
    loadSalesFromFile(sales, numSales);

    cout << "Admin login successful.\n";

    // Display admin menu options
    int choice;
    do
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Display Sales Details\n";
        cout << "2. Update Medicine Details\n";
        cout << "3. Add New Medicine\n";
        cout << "4. Display Medicine Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displaySalesDetails(sales, numSales);
            break;
        case 2:
            updateMedicineDetails(inventory, numMedicines);
            break;
        case 3:
            addNewMedicine(inventory, numMedicines);
            break;
        case 4:
            displayInventory(inventory, numMedicines);
            break;
        case 5:
            saveMedicineToFile(inventory, numMedicines);
            saveSalesToFile(sales, numSales);
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);
}

// Customer menu
void customerMenu(Medicine inventory[], int numMedicines, Medicine sales[], int &numSales)
{
    cout << "Customer login successful.\n";

    // Display customer menu options
    int choice;
    do
    {
        cout << "\nCustomer Menu:\n";
        cout << "1. Display Medicine Inventory\n";
        cout << "2. Purchase Medicine\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayInventory(inventory, numMedicines);
            break;
        case 2:
            purchaseMedicine(inventory, numMedicines, sales, numSales);
            break;
        case 3:
            saveSalesToFile(sales, numSales);
            saveMedicineToFile(inventory, numMedicines);
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 3);
}

void writeEmployeeDataToFile(const Employee employees[], int numEmployees, const char* filename) {
    ofstream outFile(filename, ios::app);  // Open the file in append mode

    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (int i = 0; i < numEmployees; ++i) {
        outFile << employees[i].id << ','
                << employees[i].name << ','
                << employees[i].qualifications << ','
                << employees[i].salary << '\n';
    }

    outFile.close();
}

int readEmployeeDataFromFile(Employee employees[], const char* filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return 0;
    }

    int numEmployees = 0;
    while (inFile >> employees[numEmployees].id) {
        inFile.ignore(); // Ignore the comma
        inFile.getline(employees[numEmployees].name, 50, ',');
        inFile.getline(employees[numEmployees].qualifications, 50, ',');
        inFile >> employees[numEmployees].salary;

        ++numEmployees;
        if (numEmployees >= 100) {
            cerr << "Exceeded maximum number of employees." << endl;
            break;
        }
    }

    inFile.close();
    return numEmployees;
}

void writeTransactionsToFile(const Transaction transactions[], int numTransactions, const char* filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (int i = 0; i < numTransactions; ++i) {
        outFile << transactions[i].date << ','
                << transactions[i].amount << ','
                << transactions[i].employeeId << '\n';
    }

    outFile.close();
}

int readTransactionsFromFile(Transaction transactions[], const char* filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return 0;
    }

    int numTransactions = 0;
    while (inFile >> transactions[numTransactions].date
                  >> transactions[numTransactions].amount
                  >> transactions[numTransactions].employeeId) {
        ++numTransactions;
        if (numTransactions >= 100) {
            cerr << "Exceeded maximum number of transactions." << endl;
            break;
        }
    }

    inFile.close();
    return numTransactions;
}

void adminViewData(const Employee employees[], int numEmployees) {
    cout << "\nAll Employee Data:\n";
    for (int i = 0; i < numEmployees; ++i) {
        cout << "ID: " << employees[i].id
             << " Name: " << employees[i].name
             << " Qualifications: " << employees[i].qualifications
             << " Salary: " << employees[i].salary << '\n';
    }
}

void employeeWithdrawSalary(Transaction transactions[], int& numTransactions, Employee& employee) {
    for (int i = 0; i < numTransactions; ++i) {
        if (transactions[i].employeeId == employee.id) {
            cout << "Salary has already been withdrawn for this month.\n";
            return;
        }
    }

    cout << "Salary withdrawn: " << employee.salary << '\n';

    strcpy(transactions[numTransactions].date, "2023-11-15");
    transactions[numTransactions].amount = employee.salary;
    transactions[numTransactions].employeeId = employee.id;
    ++numTransactions;
}

void executeEmployeeManagementSystem() {
    Employee employees[100];
    Transaction transactions[100];

    int numEmployees = readEmployeeDataFromFile(employees, "employees.txt");
    int numTransactions = readTransactionsFromFile(transactions, "transactions.txt");

    int choice;
    int employeeIndex = -1;  // Move the declaration outside the switch statement

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Admin: View All Data\n";
        cout << "2. Employee: Withdraw Salary\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                adminViewData(employees, numEmployees);
                break;
            case 2:
                int employeeId;
                cout << "Enter your Employee ID: ";
                cin >> employeeId;

                employeeIndex = -1;  // Reset the employeeIndex
                for (int i = 0; i < numEmployees; ++i) {
                    if (employees[i].id == employeeId) {
                        employeeIndex = i;
                        break;
                    }
                }

                if (employeeIndex != -1) {
                    employeeWithdrawSalary(transactions, numTransactions, employees[employeeIndex]);
                } else {
                    cout << "Employee not found.\n";
                }
                break;
            case 3:
                writeEmployeeDataToFile(employees, numEmployees, "employees.txt");
                writeTransactionsToFile(transactions, numTransactions, "transactions.txt");
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }


