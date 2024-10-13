#include <iostream>
#include <string>
using namespace std;

class Bank {
public:
    float deposit;
    string name;
    int account;  
    float withdrawal;

    void depositMoney() {
        float depositAmount;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;
        deposit += depositAmount;
        cout << "\n";
    }

    void accept() {
        cout << "\nEnter the name of Account Holder: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the Account number: ";
        cin >> account;
        cout << "Enter Your Current Balance: ";
        cin >> deposit;
        cout << "\n";
    }

    void display() {
        cout << "\nAccount Holder: " << name;
        cout << "\nAccount Number: " << account;
        cout << "\nCurrent Balance: " << deposit << "\n\n";
    }

    void withdraw() {
        if (deposit <= 0) {
            cout << "You have currently a Null Account\nCan't withdraw Money...\n";
            return;
        }
        cout << "Enter the amount to withdraw: ";
        cin >> withdrawal;
        if (withdrawal > deposit) {
            cout << "You don't have that much money in your Account to withdraw...\n";
        } else {
            deposit -= withdrawal;
        }
    }
};

int main() {
    int choice;
    Bank b1;

    do {
        cout << "Enter Your Choice:\n"
             << "1. Accept New Account Holder\n"
             << "2. Withdraw an amount\n"
             << "3. Display information\n"
             << "4. Deposit money\n"
             << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                b1.accept();
                break;
            case 2:
                b1.withdraw();
                break;
            case 3:
                b1.display();
                break;
            case 4:
                b1.depositMoney();
                break;
            case 5:
                cout <<"\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

 return 0;
}
