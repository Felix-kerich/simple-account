#include <iostream>
using namespace std;

class Account {
private:
    int accountNumber;
    float credit;

public:
    // Constructor
    Account(int number, float initialCredit) {
        accountNumber = number;
        credit = initialCredit;
    }

    // Getter methods
    int getAccountNumber() {
        return accountNumber;
    }

    float getCredit() {
        return credit;
    }

    // Setter methods
    void setCredit(float newCredit) {
        credit = newCredit;
    }

    // Other methods
    void deposit(float amount) {
        credit += amount;
        cout << "Deposit successful. New credit balance: " << credit << endl;
    }

    void withdraw(float amount) {
        if (credit - amount < 0) {
            cout << "Insufficient credit. Withdrawal unsuccessful." << endl;
        } else {
            credit -= amount;
            cout << "Withdrawal successful. New credit balance: " << credit << endl;
        }
    }
};

int main() {
    int accountNumber;
    float initialCredit;
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter initial credit: ";
    cin >> initialCredit;

    Account account(accountNumber, initialCredit);

    int choice;
    float amount;
    do {
        cout << endl << "Select an operation:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
