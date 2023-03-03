#include <iostream>
#define max_account 50
using namespace std;

class BankAccount {
private:
   long int accountNumber;
    double credit;
public:
    void input_details();
    void deposit();
    void withdraw();
    double get_credit();
    long int get_accNumber();
    void showAccount_details();
};
    void BankAccount::input_details() {
        int account_limit;
        for(account_limit=0;account_limit<=max_account;account_limit++)
         {
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter initial credit: ";
            cin >> credit;
            break;
        }
        if(account_limit>max_account){
            cout<<"account limit exceeded"<<endl;
        }
}
    double BankAccount::get_credit() {
        return (credit);
    }
    long int BankAccount::get_accNumber() {
        return (accountNumber);
    }
    void BankAccount::showAccount_details() {
        cout << "New credit balance is " << credit << endl;
    }

    void BankAccount::deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        credit += amount;
        cout << "New credit balance is " << credit << endl;
    }

    void BankAccount::withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > credit) {
            cout << "Insufficient credit balance" << endl;
        }
        else {
            credit -= amount;
            cout << "New credit balance is " << credit << endl;
        }
    }

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "Choose an operation:" << endl;
        cout << "1. Open account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout<< "4.show balance"<<endl;
        cout << "5. exit menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.input_details();
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.showAccount_details();
                break;
            case 5:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice, try again" << endl;
                break;
        }
    }
    while (choice != 5);

    return 0;
}