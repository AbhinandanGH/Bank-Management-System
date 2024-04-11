#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, string accName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = accName;
        balance = initialBalance;
    }

    // Function to deposit amount
    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully." << endl;
    }

    // Function to withdraw amount
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Amount withdrawn successfully." << endl;
        }
    }

    // Function to check balance
    void balanceEnquiry() {
        cout << "Balance: " << balance << endl;
    }

    // Function to show account details
    void showDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Function to close account
    void closeAccount() {
        accountNumber = "";
        accountHolderName = "";
        balance = 0;
        cout << "Account closed successfully." << endl;
    }

    // Function to update account holder name
    void updateAccountHolderName(string newName) {
        accountHolderName = newName;
        cout << "Account holder name updated successfully." << endl;
    }
};

int main() {
    string accNum, accName;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter account holder name: ";
    cin.ignore(); // Ignore newline character left in buffer
    getline(cin, accName);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Create a bank account
    BankAccount account(accNum, accName, initialBalance);

    int choice;
    double amount;
    string newName;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Balance Enquiry\n";
        cout << "4. Show Account Details\n";
        cout << "5. Update Account Holder Name\n";
        cout << "6. Close Account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.balanceEnquiry();
                break;
            case 4:
                account.showDetails();
                break;
            case 5:
                cout << "Enter new account holder name: ";
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, newName);
                account.updateAccountHolderName(newName);
                break;
            case 6:
                account.closeAccount();
                break;
            case 7:
                cout << "Exiting program...";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }

    } while(choice != 7);

    return 0;
}
