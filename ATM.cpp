#include <iostream>
#include <string>

using namespace std;

// Global Variables
int balance = 0;
string transactionList[50];
int transactionCounter = 0;

// Function Prototypes
bool loginSystem();
void displayMenu();
void checkBalance();
void depositMoney();
void withdrawMoney();
void showTransactions();

int main()
{
    int option;

    cout << "===================================" << endl;
    cout << "         GLOBAL TRUST ATM          " << endl;
    cout << "===================================" << endl;

    // Login System
    if (!loginSystem())
    {
        cout << "\nATM BLOCKED!" << endl;
        return 0;
    }

    // Main Menu
    do
    {
        displayMenu();
        cin >> option;

        switch (option)
        {
        case 1:
            checkBalance();
            break;

        case 2:
            depositMoney();
            break;

        case 3:
            withdrawMoney();
            break;

        case 4:
            showTransactions();
            break;

        case 5:
            cout << "\nThank You For Using GLOBAL TRUST ATM." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (option != 5);

    return 0;
}

// Login Function
bool loginSystem()
{
    int correctPin = 1993;
    int enteredPin;
    int attempts = 3;

    while (attempts > 0)
    {
        cout << "\nEnter Your PIN: ";
        cin >> enteredPin;

        if (enteredPin == correctPin)
        {
            cout << "\nLogin Successful!" << endl;
            return true;
        }
        else
        {
            attempts--;

            cout << "Wrong PIN!" << endl;

            if (attempts > 0)
            {
                cout << "Remaining Attempts: "
                     << attempts << endl;
            }
        }
    }

    return false;
}

// Display Menu
void displayMenu()
{
    cout << "\n========== MAIN MENU ==========" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Transaction History" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose Option: ";
}

// Check Balance
void checkBalance()
{
    cout << "\nCurrent Balance: $" << balance << endl;
}

// Deposit Money
void depositMoney()
{
    int amount;

    cout << "\nEnter Deposit Amount: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid Amount!" << endl;
        return;
    }

    balance += amount;

    transactionList[transactionCounter] =
        "Deposit : +$" + to_string(amount);

    transactionCounter++;

    cout << "Deposit Successful!" << endl;
}

// Withdraw Money
void withdrawMoney()
{
    int amount;

    cout << "\nEnter Withdraw Amount: ";
    cin >> amount;

    if (amount > balance)
    {
        cout << "Insufficient Balance!" << endl;
    }
    else if (amount <= 0)
    {
        cout << "Invalid Amount!" << endl;
    }
    else
    {
        balance -= amount;

        transactionList[transactionCounter] =
            "Withdraw : -$" + to_string(amount);

        transactionCounter++;

        cout << "Withdrawal Successful!" << endl;
    }
}

// Transaction History
void showTransactions()
{
    cout << "\n====== TRANSACTION HISTORY ======" << endl;

    if (transactionCounter == 0)
    {
        cout << "No Transactions Found." << endl;
    }
    else
    {
        for (int i = 0; i < transactionCounter; i++)
        {
            cout << i + 1 << ". "
                 << transactionList[i] << endl;
        }
    }
}
