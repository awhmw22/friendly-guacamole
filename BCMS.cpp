#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <sstream>
using namespace std;
// Functions required:
void header();
void subMenuBeforeMainMenu(string submenu);
void mainMenu(string submenu);
void clearScreen();
string getField(string record, int field);
// Functions of Users
string adminMenu();
void adminInterface();
string userMenu();
void userInterface();
// Functions of Admin
void addACustomer();
void removeACustomer();
void viewList();
void viewComplaints();
void updateRecords();
void Notify();
void checkTransactions();
void checkLoans();
void addLoans();
// Functions of Customer
void createProfile();
void viewProfile();
void seeNotify();
void addAComplaint();
void transactions();
void generateReceipt();
void changePassword();
void applyForHI();
void charity();
// Login Functions
string loginMenu();
string signIn(string name, string password);
bool signUp(string name, string password, string role);
// Validations functions
bool customerNameValidation(string x);
bool validateInteger(string x);
bool validateAge(int x);
bool validateAmount(int x);
bool validateCNIC(string x);
// Functions for file
void storeUsers(string name, string password, string role);
void storeCustomersData(string name, string city, string district, string CNIC);
void loadCustomersData();
void loadUserData();
void storeUpdateData();
void storeTransData();
void loadTransData();
void removeACustomerFromFile(int index);

int usersCount = 0;
const int a = 100; //Maximum array size
string users[a];
string names[a];
string customs[a];
string passwords[a];
string roles[a];
string cities[a];
string districts[a];
string CNICs[a];
string trans[a];
string comps[a];
int ages[a];
int money[a];

int main()
{
    loadUserData();
    loadCustomersData();
    system("cls");
    string MenuOption = "\0";
    while (MenuOption != "3")
    {
        system("Color 0D");
        header();
        subMenuBeforeMainMenu("Login");
        MenuOption = loginMenu();
        if (MenuOption == "1")
        {
            system("cls");
            string name;
            string password;
            string role;
            header();
            subMenuBeforeMainMenu("SignIn");
            cout << "Enter your username :" << endl;
            cin >> name;
            cout << "Enter your password :" << endl;
            cin >> password;
            cout << "Enter your Role (Admin,User or Employee): " << endl;
            cin >> role;
            role = signIn(name, password);
            if (role == "Admin" || role == "admin")
            {
                system("Color 0A");
                cout << "ACCESS GRANTED!!!" << endl;
                system("cls");
                adminInterface();
            }
            else if (role == "User" || role == "Customer")
            {
                system("Color 0A");
                cout << "ACCESS GRANTED!!!" << endl;
                system("cls");
                userInterface();
            }
            else if (role == "undefined")
            {
                system("Color 04");
                cout << "ACCESS DENIED!!!" << endl;
                cout << "You Entered wrong Credentials" << endl;
            }
            clearScreen();
        }
        else if (MenuOption == "2")
        {
            system("cls");
            string name;
            string password;
            string role;
            cout << "Enter your username :" << endl;
            cin >> name;
            cout << "Enter your password :" << endl;
            cin >> password;
            cout << "Enter your role :" << endl;
            cin >> role;
            bool isValid = signUp(name, password, role);
            if (isValid == true)
            {
                cout << "You are signed up successfully" << endl;
                cout << endl;
                storeUsers(name, password, role);
            }
            else
            {
                cout << "User already present" << endl;
            }
            clearScreen();
        }
    }
}
void header()
{
    cout << "         @@@@@@     @@@@@@   @@@      @@@     @@@@@@@@@@        " << endl;
    cout << "         @     @   @         @@ @@  @@ @@     @        @        " << endl;
    cout << "         @@@@@@    @         @@   @@   @@       @               " << endl;
    cout << "         @     @   @         @@        @@  @      @             " << endl;
    cout << "         @@@@@@     @@@@@@   @@        @@  @@@@@@@              " << endl;
    cout << "      ********************************************************  " << endl;
    cout << "      ************BANK CUSTOMERS MANAGEMENT SYSTEM************  " << endl;
    cout << "      ********************************************************  " << endl;
    cout << "             WELCOME TO BANK CUSTOMERS MANAGEMENT SYSTEM        " << endl;
    cout << "  Experience Inspired living with our Innovative Banking System " << endl;
}
void subMenuBeforeMainMenu(string submenu)
{
    string message = submenu + "Menu";
    cout << message;
    cout << "--------------------------" << endl;
}
void mainMenu(string submenu)
{
    string message = "Main Menu > " + submenu;
    cout << message << endl;
    cout << "-----------------------------" << endl;
}
void clearScreen()
{
    cout << "Press any key to continue :" << endl;
    getch();
    system("cls");
}
// Login Functions
string loginMenu()
{
    string option;
    cout << "1.Sign in with your credentials (Admin,User or Employee) " << endl;
    cout << "2.Sign up with your credentials (Admin,User or Employee) " << endl;
    cout << "3.Exit Application" << endl;
    cout << endl;
    cout << "Select your option number : " << endl;
    cin >> option;
    return option;
}
string signIn(string name, string password)
{
    for (int idx = 0; idx < usersCount; idx++)
    {
        if (users[idx] == name && passwords[idx] == password)
        {
            return roles[idx];
        }
    }
    return "un-defined";
}
bool signUp(string name, string password, string role)
{
    if (a == usersCount)
    {
        cout << "Maximum capacity reached" << endl;
        return false;
    }

    for (int idx = 0; idx < usersCount; idx++)
    {
        if (users[idx] == name && passwords[idx] == password)
        {
            return false;
        }
    }

    users[usersCount] = name;
    passwords[usersCount] = password;
    roles[usersCount] = role;

    usersCount++;

    return true;
}
// Functions list of Admin
string adminMenu()
{
    system("Color 0C");
    header();
    string option;
    cout << "Login > Admin" << endl;
    cout << endl;   
    cout << "1.Add a Customer" << endl;
    cout << "2.Remove a Customer" << endl;
    cout << "3.Update Records" << endl;
    cout << "4.Add notifications" << endl;
    cout << "5.View list of Customers" << endl;
    cout << "6.View transaction records" << endl;
    cout << "7.View complaints" << endl;
    cout << "8.Add loans" << endl;
    cout << "9.Check loan Applicants" << endl;
    cout << "10.Exit the Application" << endl;
    cout << endl;
    cout << "Enter your option :" << endl;
    cin >> option;
    return option;
}
// Interface of Admin
void adminInterface()
{
    string adminOption = "\0";
    while (adminOption != "10")
    {
        header();
        mainMenu("Admin");
        adminOption = adminMenu();
        if (adminOption == "1")
        {
            system("cls");
            system("Color 01");
            header();
            addACustomer();
        }
        clearScreen();
        if (adminOption == "2")
        {
            system("cls");
            system("Color 02");
            header();
            removeACustomer();
        }
        clearScreen();
        if (adminOption == "3")
        {
            system("cls");
            system("Color 03");
            header();
            updateRecords();
        }
        clearScreen();
        if (adminOption == "4")
        {
            system("cls");
            system("Color 0D");
            header();
            Notify();
        }
        clearScreen();
        if (adminOption == "5")
        {
            system("cls");
            system("Color 05");
            header();
            viewList();
        }
        clearScreen();
        if (adminOption == "6")
        {
            system("cls");
            system("Color 06");
            header();
            checkTransactions();
        }
        clearScreen();
        if (adminOption == "7")
        {
            system("cls");
            system("Color 08");
            header();
            viewComplaints();
        }
        clearScreen();
        if (adminOption == "8")
        {
            system("cls");
            system("Color 09");
            header();
            addLoans();
        }
        clearScreen();
        if (adminOption == "9")
        {
            system("cls");
            system("Color 0B");
            header();
            checkLoans();
        }
        clearScreen();
    }
}
// Functions of Admin
void addACustomer()
{
    int num;
    cout << "Login As: > Admin > Add a Customer" << endl;
    cout << endl;
    string name = users[usersCount], city = cities[usersCount], district = districts[usersCount], CNIC = CNICs[usersCount];
    cout << "How many customers do you want to add:" << endl;
    cin >> num;
    int age = 0;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter the name of the customer:" << endl;
        cin.ignore();
        getline(cin, name);
        while (!customerNameValidation(name))
        {
            cout << "Name only contains alphabets:" << endl;
            cout << "Invalid name. Please enter a valid name:" << endl;
            getline(cin, name);
        }

        cout << "Enter the city of the customer:" << endl;
        cin >> city;
        while (!customerNameValidation(city))
        {
            cout << "City only contains alphabets:" << endl;
            cout << "Invalid city. Please enter a valid city:" << endl;
            cin >> city;
        }

        cout << "Enter the district of the customer:" << endl;
        cin >> district;
        while (!customerNameValidation(district))
        {
            cout << "District only contains alphabets:" << endl;
            cout << "Invalid district. Please enter a valid district:" << endl;
            cin >> district;
        }

        cout << "Enter the age of the customer:" << endl;
        cin >> age;
        while (!validateAge(age))
        {
            cout << "Age must be an integer between 18 and 120" << endl;
            cout << "Invalid age. Please enter a valid age:" << endl;
            cin >> age;
        }

        if (age >= 18)
        {
            cout << "Enter the CNIC of the customer without dashes:" << endl;
            cin >> CNIC;
            while (!validateCNIC(CNIC))
            {
                cout << "CNIC should be a 13 digit integer without dashes" << endl;
                cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
                cin >> CNIC;
            }
        }

        storeCustomersData(name, city, district, CNIC);
    }
    cout << num << " customers have been added successfully!!!" << endl;
}

void removeACustomerFromFile(int index)
{
    fstream file;
    file.open("Customer.txt", ios::out);
    for (int i = 0; i < usersCount; i++)
    {
        if (i != index)
        {
            file << customs[i] << ",";
            file << cities[i] << ",";
            file << districts[i] << ",";
            file << CNICs[i] << endl;
        }
    }
    file.close();
    for (int i = 0; i < usersCount - 1; i++)
    {
        customs[i] = customs[i + 1];
        cities[i] = cities[i + 1];
        districts[i] = districts[i + 1];
        CNICs[i] = CNICs[i + 1];
    }
    usersCount--;
}

void removeACustomer()
{
    cout << "Login As: > Admin > Remove a Customer" << endl;
    string name, city, district, CNIC;
    int age = 0;
    cout << "Enter the name of the customer you want to remove :" << endl;
    cin.ignore();
    getline(cin, name);
    while (!customerNameValidation(name))
    {
        cout << "Name only contains alphabets:" << endl;
        cout << "Invalid name. Please enter a valid name:" << endl;
        getline(cin, name);
    }

    cout << "Enter the city of the customer:" << endl;
    cin >> city;
    while (!customerNameValidation(city))
    {
        cout << "City only contains alphabets:" << endl;
        cout << "Invalid city. Please enter a valid city:" << endl;
        cin >> city;
    }

    cout << "Enter the district of the customer:" << endl;
    cin >> district;
    while (!customerNameValidation(district))
    {
        cout << "District only contains alphabets:" << endl;
        cout << "Invalid district. Please enter a valid district:" << endl;
        cin >> district;
    }

    cout << "Enter the age of the customer:" << endl;
    cin >> age;
    while (!validateAge(age))
    {
        cout << "Age must be an integer between 18 and 120" << endl;
        cout << "Invalid age. Please enter a valid age:" << endl;
        cin >> age;
    }

    if (age >= 18)
    {
        cout << "Enter the CNIC of the customer without dashes:" << endl;
        cin >> CNIC;
        while (!validateCNIC(CNIC))
        {
            cout << "CNIC should be a 13 digit integer without dashes" << endl;
            cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
            cin >> CNIC;
        }
    }
    int index = -1;
    for (int i = 0; i < usersCount; i++)
    {
        if (customs[i] == name && cities[i] == city && districts[i] == district && CNICs[i] == CNIC)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Customer not found" << endl;
    }
    else
    {
        removeACustomerFromFile(index);
        for (int i = 0; i < usersCount - 1; i++)
        {
            customs[i] = customs[i + 1];
            cities[i] = cities[i + 1];
            districts[i] = districts[i + 1];
            CNICs[i] = CNICs[i + 1];
        }
        cout << "Customer has been removed successfully" << endl;
    }
}
void viewList()
{
    cout << "Login As: > Admin > View List of Customers" << endl;
    cout << endl;
    cout << "Here is the list of all Customers :" << endl;
    cout << endl;

    // loops to swap arrays in alphabetical order
    for (int i = 0; i < usersCount - 1; i++)
    {
        for (int j = 0; j < usersCount - i - 1; j++)
        {
            if (customs[j] > customs[j + 1])
            {
                // swapping names in alphabetical order
                string tempName = customs[j];
                customs[j] = customs[j + 1];
                customs[j + 1] = tempName;
                // swapping cities wrt that name
                string tempCity = cities[j];
                cities[j] = cities[j + 1];
                cities[j + 1] = tempCity;
                // swapping districts wrt that name
                string tempDistrict = districts[j];
                districts[j] = districts[j + 1];
                districts[j + 1] = tempDistrict;
                // swapping CNICs wrt that name
                string tempCNIC = CNICs[j];
                CNICs[j] = CNICs[j + 1];
                CNICs[j + 1] = tempCNIC;    
            }
        }
    }

    for (int idx = 0; idx < usersCount; idx++)
    {
        cout << customs[idx] << endl;
        cout << cities[idx] << endl;
        cout << districts[idx] << endl;
        cout << CNICs[idx] << endl;
    }
}
void updateRecords()
{
    cout << "Login As: > Admin > Update Records" << endl;
    cout << endl;

    // Updation of the record of a certain Customer
    string name, city, district, CNIC;
    int num;
    int age = 0;
    cout << "How many updates you want to make :" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "Enter the name of Customer :" << endl;
        cin.ignore();
        getline(cin, name);
        while (!customerNameValidation(name))
        {
            cout << "Name only contains alphabets:" << endl;
            cout << "Invalid name. Please enter a valid name:" << endl;
            getline(cin, name);
        }

        cout << "Enter the city of the customer:" << endl;
        cin >> city;
        while (!customerNameValidation(city))
        {
            cout << "City only contains alphabets:" << endl;
            cout << "Invalid city. Please enter a valid city:" << endl;
            cin >> city;
        }

        cout << "Enter the district of the customer:" << endl;
        cin >> district;
        while (!customerNameValidation(district))
        {
            cout << "District only contains alphabets:" << endl;
            cout << "Invalid district. Please enter a valid district:" << endl;
            cin >> district;
        }

        cout << "Enter the age of the customer:" << endl;
        cin >> age;
        while (!validateAge(age))
        {
            cout << "Age must be an integer between 18 and 120" << endl;
            cout << "Invalid age. Please enter a valid age:" << endl;
            cin >> age;
        }

        if (age >= 18)
        {
            cout << "Enter the CNIC of the customer without dashes:" << endl;
            cin >> CNIC;
            while (!validateCNIC(CNIC))
            {
                cout << "CNIC should be a 13 digit integer without dashes" << endl;
                cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
                cin >> CNIC;
            }
        }

        // Find the index of the customer in the arrays
        int index = -1;
        for (int j = 0; j < usersCount; j++)
        {
            if (customs[j] == name && cities[j] == city && districts[j] == district && CNICs[j] == CNIC)
            {
                index = j;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Customer not found" << endl;
        }
        else
        {
            // Update the customer's record
            cout << "Enter the updated City of Customer :" << endl;
            cin >> cities[index];
            cout << "Enter the updated District of Customer :" << endl;
            cin >> districts[index];
            cout << "Enter the updated CNIC of Customer :" << endl;
            cin >> CNICs[index];
            cout << endl;
            cout << "Record updated successfully" << endl;
            storeUpdateData();
        }
    }
}

void viewComplaints()
{
    // Opening the file for reading
    fstream file;
    file.open("Complaints.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    // Displaying the Profile data
    cout << "Login As: > Admin > View Complaints" << endl;
    cout << endl;
    cout << "Here is the list of complaints:" << endl;
    cout << endl;
    string line;
    while (getline(file, line))
    {
        string fields[6];
        int i = 0;
        stringstream ssin(line);
        while (ssin >> fields[i] && i < 6)
        {
            i++;
        }
        cout << "Your Name: " << fields[0] << endl;
        cout << "Your City: " << fields[1] << endl;
        cout << "Your District: " << fields[2] << endl;
        cout << "Your CNIC:" << fields[3] << endl;
        cout << "Your Age:" << fields[4] << endl;
        cout << "Complaint:" << fields[5] << endl;
        cout << "------------------------" << endl;
    }

    // Closing the file
    file.close();
}
void Notify()
{
    cout << "                     ADVERTISEMENT                   " << endl;
    cout << "Our Bank is launching a new scheme to buy mobile phones on loan." << endl;
    cout << "So get ready and avail this offer as it is for a limited time." << endl;
}
void checkTransactions()
{
    storeTransData();
    // Opening the file for reading
    fstream file;
    file.open("Transactions.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    // Displaying the Receipt
    cout << "Login As: > Admin > Checking Transactions of Customers" << endl;
    cout << endl;
    cout << "Here are all Transactions:" << endl;
    cout << endl;
    string line;
    while (getline(file, line))
    {
        string fields[5];
        int i = 0;
        stringstream ssin(line);
        while (ssin >> fields[i] && i < 5)
        {
            i++;
        }
        cout << "Customer Name: " << fields[0] << endl;
        cout << "Customer's City: " << fields[1] << endl;
        cout << "Customer's District: " << fields[2] << endl;
        cout << "Customer's CNIC:" << fields[3] << endl;
        cout << "Your Amount:" << fields[4] << endl;
        cout << "------------------------" << endl;
    }

    // Closing the file
    file.close();
}

void addLoans()
{
    // Opening the file for appending data
    ofstream file;
    file.open("Loans.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    // Getting loans data from the user
    string name;
    double amount, rate;
    cout << "Enter customer name: " << endl;
    cin.ignore();
    getline(cin, name);
    // Validation for user inputs
    while (name.empty()) // Checks if name is empty
    {
        cout << "Name cannot be empty" << endl;
        cout << "Please enter a valid name :" << endl;
        getline(cin, name);
    }

    cout << "Enter loan amount: " << endl;
    cin >> amount;
    while (amount <= 0) // Checks if amount is positive
    {
        cout << "Amount should be a positive number" << endl;
        cout << "Please enter a valid amount :" << endl;
        cin >> amount;
    }

    cout << "Enter interest rate: " << endl;
    cin >> rate;
    if (rate <= 0) // Checks if rate is positive
    {
        cout << "Interest rate should be a positive number" << endl;
        cout << "Please enter a valid interest rate :" << endl;
        cin >> rate;
    }

    // Writing loan data to file
    file << name << " " << amount << " " << rate << endl;

    // Closing the file
    file.close();

    cout << "Loan added successfully!" << endl;
}

void checkLoans()
{
    // Opening the file for reading
    fstream file;
    file.open("Loans.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    // Displaying the loans data
    cout << "Login As: > Admin > Check Loans" << endl;
    cout << endl;
    cout << "Here is the list of all Loans:" << endl;
    cout << endl;
    string line;
    while (getline(file, line))
    {
        string fields[3];
        int i = 0;
        stringstream ssin(line);
        while (ssin >> fields[i] && i < 3)
        {
            i++;
        }
        cout << "Customer Name: " << fields[0] << endl;
        cout << "Loan Amount: " << fields[1] << endl;
        cout << "Interest Rate: " << fields[2] << "%" << endl;
        cout << "------------------------" << endl;
    }

    // Closing the file
    file.close();
}

// Functions list of User
string userMenu()
{
    system("Color 09");
    header();
    string option;
    cout << "Login > User" << endl;
    cout << endl;
    cout << "1.Create your profile" << endl;
    cout << "2.View your profile" << endl;
    cout << "3.See important notifications" << endl;
    cout << "4.Add a Complaint" << endl;
    cout << "5.Deposit or withdraw money" << endl;
    cout << "6.Generate receipt" << endl;
    cout << "7.Apply for Health Insurance" << endl;
    cout << "8.Change Password" << endl;
    cout << "9.Send amount as Charity" << endl;
    cout << "10.Exit the Application" << endl;
    cout << endl;
    cout << "Please select your option :" << endl;
    cin >> option;
    return option;
}

// Interface of Customer
void userInterface()
{
    // loadCustomerData();
    string userOption = "0";
    while (userOption != "10")
    {
        header();
        mainMenu("User");
        userOption = userMenu();
        if (userOption == "1")
        {
            system("cls");
            system("Color 0B");
            header();
            createProfile();
        }
        clearScreen();
        if (userOption == "2")
        {
            system("cls");
            system("Color 08");
            header();
            viewProfile();
        }
        clearScreen();
        if (userOption == "3")
        {
            system("cls");
            system("Color 06");
            header();
            seeNotify();
        }
        clearScreen();
        if (userOption == "4")
        {
            system("cls");
            system("Color 05");
            header();
            addAComplaint();
        }
        clearScreen();
        if (userOption == "5")
        {
            system("cls");
            system("Color 0D");
            header();
            transactions();
        }
        clearScreen();
        if (userOption == "6")
        {
            system("cls");
            system("Color 03");
            header();
            generateReceipt();
        }
        clearScreen();
        if (userOption == "7")
        {
            system("cls");
            system("Color 02");
            header();
            applyForHI();
        }
        clearScreen();
        if (userOption == "8")
        {
            system("cls");
            system("Color 01");
            header();
            changePassword();
        }
        clearScreen();
        if (userOption == "9")
        {
            system("cls");
            system("Color 0E");
            header();
            charity();
        }
        clearScreen();
    }
}

// Functions of Customer
void createProfile()
{
    cout << "Login > User > Create your Profile" << endl;
    string name, city, district, CNIC;
    int age = 0;
    ofstream file;
    file.open("Profiles.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    cout << "Enter your name :" << endl;
    cin.ignore();
    getline(cin, name);
    while (!customerNameValidation(name))
    {
        cout << "Name only contains alphabets:" << endl;
        cout << "Invalid name. Please enter a valid name:" << endl;
        getline(cin, name);
    }

    cout << "Enter the city of the customer:" << endl;
    cin >> city;
    while (!customerNameValidation(city))
    {
        cout << "City only contains alphabets:" << endl;
        cout << "Invalid city. Please enter a valid city:" << endl;
        cin >> city;
    }

    cout << "Enter the district of the customer:" << endl;
    cin >> district;
    while (!customerNameValidation(district))
    {
        cout << "District only contains alphabets:" << endl;
        cout << "Invalid district. Please enter a valid district:" << endl;
        cin >> district;
    }

    cout << "Enter the age of the customer:" << endl;
    cin >> age;
    while (!validateAge(age))
    {
        cout << "Age must be an integer between 18 and 120" << endl;
        cout << "Invalid age. Please enter a valid age:" << endl;
        cin >> age;
    }

    if (age >= 18)
    {
        cout << "Enter the CNIC of the customer without dashes:" << endl;
        cin >> CNIC;
        while (!validateCNIC(CNIC))
        {
            cout << "CNIC should be a 13 digit integer without dashes" << endl;
            cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
            cin >> CNIC;
        }
    }

    names[usersCount] = name;
    cities[usersCount] = city;
    districts[usersCount] = district;
    CNICs[usersCount] = CNIC;
    ages[usersCount] = age;

    file << name << " " << city << " " << district << " " << CNIC << " " << age << endl;
    cout << "Profile created successfully" << endl;
    file.close();
}

void viewProfile()
{
    // Opening the file for reading
    fstream file;
    file.open("Profiles.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    // Displaying the Profile data
    cout << "Login As: > User > View your Profile" << endl;
    cout << endl;
    cout << "Here is your Profile:" << endl;
    cout << endl;
    string line;
    while (getline(file, line))
    {
        string fields[5];
        int i = 0;
        stringstream ssin(line);
        while (ssin >> fields[i] && i < 5)
        {
            i++;
        }
        cout << "Your Name: " << fields[0] << endl;
        cout << "Your City: " << fields[1] << endl;
        cout << "Your District: " << fields[2] << endl;
        cout << "Your CNIC:" << fields[3] << endl;
        cout << "Your Age:" << fields[4] << endl;
        cout << "------------------------" << endl;
    }

    // Closing the file
    file.close();
}

void seeNotify()
{
    cout << "Login As: > User > See Important Notifications" << endl;
    Notify();
}

void addAComplaint()
{
    cout << "Login As: > User > Add A Complaint" << endl;
    string name, city, district, CNIC, comp;
    int age = 0;
    ofstream file;
    file.open("Complaints.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    cout << "Enter your name :" << endl;
    cin.ignore();
    getline(cin, name);
    while (!customerNameValidation(name))
    {
        cout << "Name only contains alphabets:" << endl;
        cout << "Invalid name. Please enter a valid name:" << endl;
        getline(cin, name);
    }

    cout << "Enter the city of the customer:" << endl;
    cin >> city;
    while (!customerNameValidation(city))
    {
        cout << "City only contains alphabets:" << endl;
        cout << "Invalid city. Please enter a valid city:" << endl;
        cin >> city;
    }

    cout << "Enter the district of the customer:" << endl;
    cin >> district;
    while (!customerNameValidation(district))
    {
        cout << "District only contains alphabets:" << endl;
        cout << "Invalid district. Please enter a valid district:" << endl;
        cin >> district;
    }

    cout << "Enter the age of the customer:" << endl;
    cin >> age;
    while (!validateAge(age))
    {
        cout << "Age must be an integer between 18 and 120" << endl;
        cout << "Invalid age. Please enter a valid age:" << endl;
        cin >> age;
    }

    if (age >= 18)
    {
        cout << "Enter the CNIC of the customer without dashes:" << endl;
        cin >> CNIC;
        while (!validateCNIC(CNIC))
        {
            cout << "CNIC should be a 13 digit integer without dashes" << endl;
            cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
            cin >> CNIC;
        }
    }

    cout << "Type a Complaint :" << endl;
    cin.ignore();
    getline(cin, comp);

    names[usersCount] = name;
    cities[usersCount] = city;
    districts[usersCount] = district;
    CNICs[usersCount] = CNIC;
    ages[usersCount] = age;
    comps[usersCount] = comp;

    file << name << " " << city << " " << district << " " << CNIC << " " << age << " " << comp << endl;
    if (file.fail())
    {
        cout << "Error writing to file!" << endl;
        return;
    }
    else
    {
        cout << "Complaint added successfully" << endl;
    }
    file.close();
}

void transactions()
{
    cout << "Login As: > User > Add or Withdraw money" << endl;
    string name, city, district, CNIC;
    int age = 0;
    ofstream file;
    file.open("Money.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    cout << "Enter your name :" << endl;
    cin.ignore();
    getline(cin, name);

    // Conditions for validation
    while (!customerNameValidation(name))
    {
        cout << "Name only contains alphabets:" << endl;
        cout << "Invalid name. Please enter a valid name:" << endl;
        getline(cin, name);
    }

    cout << "Enter the city of the customer:" << endl;
    cin >> city;
    while (!customerNameValidation(city))
    {
        cout << "City only contains alphabets:" << endl;
        cout << "Invalid city. Please enter a valid city:" << endl;
        cin >> city;
    }

    cout << "Enter the district of the customer:" << endl;
    cin >> district;
    while (!customerNameValidation(district))
    {
        cout << "District only contains alphabets:" << endl;
        cout << "Invalid district. Please enter a valid district:" << endl;
        cin >> district;
    }

    cout << "Enter the age of the customer:" << endl;
    cin >> age;
    while (!validateAge(age))
    {
        cout << "Age must be an integer between 18 and 120" << endl;
        cout << "Invalid age. Please enter a valid age:" << endl;
        cin >> age;
    }

    if (age >= 18)
    {
        cout << "Enter the CNIC of the customer without dashes:" << endl;
        cin >> CNIC;
        while (!validateCNIC(CNIC))
        {
            cout << "CNIC should be a 13 digit integer without dashes" << endl;
            cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
            cin >> CNIC;
        }
    }

    int amount;
    cout << "Enter the amount you want to add or withdraw :" << endl;
    cin >> amount;

    while (!validateAmount(amount))
    {
        cout << "Please enter a valid amount" << endl;
        cin >> amount;
        if (!cin.good())
        {
            break;
        }
    }
    string option;
    cout << "Press 1 to add amount and 2 to withdraw :" << endl;
    cout << "Enter your option :" << endl;
    cin >> option;

    int balance;
    cout << "Enter your previous balance :" << endl;
    cin >> balance;
    int new_amount = 0;

    if (option == "1")
    {
        new_amount = balance + amount;
    }
    else if (option == "2")
    {
        new_amount = abs(balance - amount);
    }

    names[usersCount] = name;
    cities[usersCount] = city;
    districts[usersCount] = district;
    CNICs[usersCount] = CNIC;
    ages[usersCount] = age;
    money[usersCount] = amount;

    file << name << " " << city << " " << district << " " << CNIC << " " << age << " " << amount << endl;
    if (file.fail())
    {
        cout << "Error writing to file!" << endl;
    }
    else
    {
        cout << "Transaction is successful" << endl;
        cout << endl;
        cout << "Your current balance is :" << new_amount << endl;
    }
    file.close();
}

void generateReceipt()
{
    // Opening the file for reading
    fstream file;
    file.open("Money.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    // Displaying the Receipt
    cout << "Login As: > User > Generation of Receipt" << endl;
    cout << endl;
    cout << "Here is your Transaction data:" << endl;
    cout << endl;
    string line;
    while (getline(file, line))
    {
        string fields[6];
        int i = 0;
        stringstream ssin(line);
        while (ssin >> fields[i] && i < 6)
        {
            i++;
        }
        cout << "Your Name: " << fields[0] << endl;
        cout << "Your City: " << fields[1] << endl;
        cout << "Your District: " << fields[2] << endl;
        cout << "Your CNIC:" << fields[3] << endl;
        cout << "Your Age:" << fields[4] << endl;
        cout << "Your entered amount:" << fields[5] << endl;
        cout << "------------------------" << endl;
    }

    // Closing the file
    file.close();
}

void applyForHI()
{
    cout << "Login As: > User > Apply for Health Insurance" << endl;
    string name, city, district, CNIC;
    int age = 0;
    ofstream file;
    file.open("HI.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    cout << "Enter your name :" << endl;
    cin.ignore();
    getline(cin, name);

    // Conditions for validation
    while (!customerNameValidation(name))
    {
        cout << "Name only contains alphabets:" << endl;
        cout << "Invalid name. Please enter a valid name:" << endl;
        getline(cin, name);
    }

    cout << "Enter the city of the customer:" << endl;
    cin >> city;
    while (!customerNameValidation(city))
    {
        cout << "City only contains alphabets:" << endl;
        cout << "Invalid city. Please enter a valid city:" << endl;
        cin >> city;
    }

    cout << "Enter the district of the customer:" << endl;
    cin >> district;
    while (!customerNameValidation(district))
    {
        cout << "District only contains alphabets:" << endl;
        cout << "Invalid district. Please enter a valid district:" << endl;
        cin >> district;
    }

    cout << "Enter the age of the customer:" << endl;
    cin >> age;
    while (!validateAge(age))
    {
        cout << "Age must be an integer between 18 and 120" << endl;
        cout << "Invalid age. Please enter a valid age:" << endl;
        cin >> age;
    }

    if (age >= 18)
    {
        cout << "Enter the CNIC of the customer without dashes:" << endl;
        cin >> CNIC;
        while (!validateCNIC(CNIC))
        {
            cout << "CNIC should be a 13 digit integer without dashes" << endl;
            cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
            cin >> CNIC;
        }
    }

    int amount;
    cout << "Enter the amount you want to save as insurance :" << endl;
    cin >> amount;

    while (!validateAmount(amount))
    {
        cout << "Please enter a valid amount" << endl;
        cin >> amount;
        if (!cin.good())
        {
            break;
        }
    }

    names[usersCount] = name;
    cities[usersCount] = city;
    districts[usersCount] = district;
    CNICs[usersCount] = CNIC;
    ages[usersCount] = age;
    money[usersCount] = amount;

    file << name << " " << city << " " << district << " " << CNIC << " " << age << " " << amount << endl;
    if (file.fail())
    {
        cout << "Error writing to file!" << endl;
    }
    else
    {
        cout << "Amount added successfully" << endl;
    }
    file.close();
}

void changePassword()
{
    string name, currentPassword, newPassword;

    cout << "Login As: > User > Change Password" << endl;
    cout << endl;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your current password: ";
    cin >> currentPassword;

    // Loading user data from the file
    loadUserData();

    string role = signIn(name, currentPassword);

    if (role != "un-defined")
    {
        cout << "Authentication Successful!" << endl;

        cout << "Enter your new password: ";
        cin >> newPassword;

        // Updating the password in the loaded user data
        signUp(name, newPassword, role);

        // Storing the updated user data to the file
        storeUsers(name, newPassword, role);

        cout << "Password changed successfully!" << endl;
    }
    else
    {
        cout << "Invalid name or password. Please try again." << endl;
    }
}

void charity()
{
    cout << "Login As: > User > Add to as Charity" << endl;
    string name, city, district, CNIC;
    int age = 0;
    ofstream file;
    file.open("Charity.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    cout << "Enter your name :" << endl;
    cin.ignore();
    getline(cin, name);

    // Conditions for validation
    while (!customerNameValidation(name))
    {
        cout << "Name only contains alphabets:" << endl;
        cout << "Invalid name. Please enter a valid name:" << endl;
        getline(cin, name);
    }

    cout << "Enter the city of the customer:" << endl;
    cin >> city;
    while (!customerNameValidation(city))
    {
        cout << "City only contains alphabets:" << endl;
        cout << "Invalid city. Please enter a valid city:" << endl;
        cin >> city;
    }

    cout << "Enter the district of the customer:" << endl;
    cin >> district;
    while (!customerNameValidation(district))
    {
        cout << "District only contains alphabets:" << endl;
        cout << "Invalid district. Please enter a valid district:" << endl;
        cin >> district;
    }

    cout << "Enter the age of the customer:" << endl;
    cin >> age;
    while (!validateAge(age))
    {
        cout << "Age must be an integer between 18 and 120" << endl;
        cout << "Invalid age. Please enter a valid age:" << endl;
        cin >> age;
    }

    if (age >= 18)
    {
        cout << "Enter the CNIC of the customer without dashes:" << endl;
        cin >> CNIC;
        while (!validateCNIC(CNIC))
        {
            cout << "CNIC should be a 13 digit integer without dashes" << endl;
            cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
            cin >> CNIC;
        }
    }

    int amount;
    cout << "Enter the amount you want to donate as Charity :" << endl;
    cin >> amount;

    while (!validateAmount(amount))
    {
        cout << "Please enter a valid amount" << endl;
        cin >> amount;
        if (!cin.good())
        {
            break;
        }
    }

    names[usersCount] = name;
    cities[usersCount] = city;
    districts[usersCount] = district;
    CNICs[usersCount] = CNIC;
    ages[usersCount] = age;
    money[usersCount] = amount;

    file << name << " " << city << " " << district << " " << CNIC << " " << age << " " << amount << endl;
    if (file.fail())
    {
        cout << "Error writing to file!" << endl;
    }
    else
    {
        cout << "Amount added successfully" << endl;
    }
    file.close();
}

// FOR STRING VALIDATION
bool customerNameValidation(string x)
{
    bool invalid = false;
    for (int i = 0; i < x.length(); i++)
    {
        if ((x[i] >= 65 && x[i] <= 90) || (x[i] >= 97 && x[i] <= 122))
        {
            invalid = true;
        }
        else
        {
            invalid = false;
            break;
        }
    }
    return invalid;
}

// FOR INTEGER VALIDATION
bool validateInteger(string x)
{
    bool invalid = false;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] >= 48 && x[i] <= 57)
        {
            invalid = true;
        }
        else
        {
            invalid = false;
            break;
        }
    }
    return invalid;
}

bool validateAge(int x)
{
    return  x >= 18 && x <= 120;
}

bool validateAmount(int x)
{
    return  x >= 100 && x <= 120000;
}

bool validateCNIC(string x)
{
    bool invalid = false;
    if (x.length() == 13)
    {
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] >= 48 && x[i] <= 57)
            {
                invalid = true;
                break;
            }
        }
    }
    else
    {
        invalid = false;
    }
    return invalid;
}

string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void storeUsers(string name, string password, string role)
{
    fstream file;
    char comma = ',';
    file.open("UserRecords.txt", ios::app);

    file << name << comma;
    file << password << comma;
    file << role << endl;
    file.close();
}
void loadUserData()
{
    string line;
    fstream file;
    file.open("UserRecords.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
    }
    while (!file.eof())
    {
        getline(file, line);
        users[usersCount] = getField(line, 1);
        passwords[usersCount] = getField(line, 2);
        roles[usersCount] = getField(line, 3);
        usersCount++;
    }
}
void storeCustomersData(string name, string city, string district, string CNIC)
{
    fstream file;
    file.open("Customer.txt", ios::app);
    file << name << "," << city << "," << district << "," << CNIC << endl;
    file.close();
}
void loadCustomersData()
{
    string line;
    fstream file;
    file.open("Customer.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
    }
    while (!file.eof())
    {
        getline(file, line);
        customs[usersCount] = getField(line, 1);
        cities[usersCount] = getField(line, 2);
        districts[usersCount] = getField(line, 3);
        CNICs[usersCount] = getField(line, 4);
        usersCount++;
    }
}

void storeUpdateData()
{
    fstream file;
    file.open("Customer.txt", ios::out);
    for (int i = 0; i < usersCount; i++)
    {
        file << customs[i] << "," << cities[i] << "," << districts[i] << "," << CNICs[i] << endl;
    }
    file.close();
}

void storeTransData()
{
    fstream file;
    string name, city, district, CNIC;
    int age = 0;
    file.open("Transactions.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
        return;
    }

    cout << "Enter your name :" << endl;
    cin.ignore();
    getline(cin, name);

    // Conditions for validation
    while (!customerNameValidation(name))
    {
        cout << "Name only contains alphabets:" << endl;
        cout << "Invalid name. Please enter a valid name:" << endl;
        getline(cin, name);
    }

    cout << "Enter the city of the customer:" << endl;
    cin >> city;
    while (!customerNameValidation(city))
    {
        cout << "City only contains alphabets:" << endl;
        cout << "Invalid city. Please enter a valid city:" << endl;
        cin >> city;
    }

    cout << "Enter the district of the customer:" << endl;
    cin >> district;
    while (!customerNameValidation(district))
    {
        cout << "District only contains alphabets:" << endl;
        cout << "Invalid district. Please enter a valid district:" << endl;
        cin >> district;
    }

    cout << "Enter the age of the customer:" << endl;
    cin >> age;
    while (!validateAge(age))
    {
        cout << "Age must be an integer between 18 and 120" << endl;
        cout << "Invalid age. Please enter a valid age:" << endl;
        cin >> age;
    }

    if (age >= 18)
    {
        cout << "Enter the CNIC of the customer without dashes:" << endl;
        cin >> CNIC;
        while (!validateCNIC(CNIC))
        {
            cout << "CNIC should be a 13 digit integer without dashes" << endl;
            cout << "Invalid CNIC. Please enter a valid CNIC:" << endl;
            cin >> CNIC;
        }
    }
    int amount;
    cout << "Enter your amount:" << endl;
    cin >> amount;

    while (!validateAmount(amount))
    {
        cout<<"Amount must be an integer between 100 and 120000"<<endl;
        cout << "Please enter a valid amount" << endl;
        cin>>amount;
    }

    names[usersCount] = name;
    cities[usersCount] = city;
    districts[usersCount] = district;
    CNICs[usersCount] = CNIC;
    trans[usersCount] = amount;

    file << name << " " << city << " " << district << " " << CNIC << " " << amount << endl;
    if (file.fail())
    {
        cout << "Error writing to file!" << endl;
    }
    else
    {
        cout << "Transaction is successfull" << endl;
    }
    file.close();
}

void loadTransData()
{
    string line;
    fstream file;
    file.open("Transactions.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Failed to open file!" << endl;
    }
    while (!file.eof())
    {
        getline(file, line);
        users[usersCount] = getField(line, 1);
        cities[usersCount] = getField(line, 2);
        districts[usersCount] = getField(line, 3);
        CNICs[usersCount] = getField(line, 4);
        trans[usersCount] = getField(line, 5);
        usersCount++;
    }
}