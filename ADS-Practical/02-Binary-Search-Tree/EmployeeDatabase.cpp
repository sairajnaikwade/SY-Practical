#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int employeeId;
    int salary;
    Employee *left, *right;

    Employee(string name, int salary, int employeeId) {
        this->name = name;
        this->salary = salary;
        this->employeeId = employeeId;
        this->left = this->right = nullptr;
    }

    void display() {
        cout << "Employee ID: " << employeeId
             << ", Name: " << name
             << ", Salary: " << salary;
    }
};

class EmployeeDatabase {
public:
    Employee *root;

    EmployeeDatabase() {
        root = nullptr;
    }

    void insertEmployee(Employee *&root, string name, int salary, int employeeId) {
        if (root == nullptr) {
            root = new Employee(name, salary, employeeId);
            return;
        }
        if (salary < root->salary) {
            insertEmployee(root->left, name, salary, employeeId);
        } else {
            insertEmployee(root->right, name, salary, employeeId);
        }
    }

    void createDatabase() {
        cout << "Creating Employee Database...\nEnter Details of CEO:\n";
        string name;
        int salary, employeeId;

        

        int choice;
        do {
            cout << "Do you want to continue inserting?\n[0] Continue \n[1] Exit\n";
            cin >> choice;
            if (choice == 0) {
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Salary: ";
                cin >> salary;
                cout << "Enter ID: ";
                cin >> employeeId;
                insertEmployee(root, name, salary, employeeId);
            }
        } while (choice == 0);
    }

    void displayDatabase(Employee *root) {
        if (root == nullptr)
            return;
        displayDatabase(root->left);
        root->display();
        displayDatabase(root->right);
    }

    void display() {
        if (root == nullptr) {
            cout << "Database is empty.\n";
            return;
        }
        cout << "Employee Database:\n";
        displayDatabase(root);
    }
    
    void findHighestSalary() {
        if (root == nullptr) {
            cout << "No employees in the database.\n";
            return;
        }
        Employee *temp = root;
        while (temp->right != nullptr)
            temp = temp->right;
        cout << "Employee with Highest Salary:\n";
        
        temp->display();
       
    }
    
    void findLowestSalary() {
        if (root == nullptr) {
            cout << "No employees in the database.\n";
            return;
        }
        Employee *temp = root;
        while (temp->left != nullptr)
            temp = temp->left;
        cout << "Employee with Lowest Salary:\n";

        temp->display();
    }
    
    void searchEmployeeById() {
    if (root == nullptr) {
        cout << "Employee database is empty.\n";
        return;
    }

    int employeeId;
    cout << "Enter Employee ID to search: ";
    cin >> employeeId;

    Employee* temp = root;
    while (temp != nullptr) {
        if (temp->employeeId == employeeId) {
            cout << "Employee found:\n";
            temp->display();
            return;
        }
        temp = (employeeId < temp->employeeId) ? temp->left : temp->right;
    }

    cout << "Employee not found.\n";
}



    
};

int main() {
    EmployeeDatabase database;
    int ch,id;

    do {
        cout << "\n1. Insert database \n2. Display Database \n3. Heighest Salary \n4. Lowest Salary \n5. Search Employe \n6. Exit \n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                database.createDatabase();
                break;
            case 2:
                database.display();
                break;
            case 3:
                database.findHighestSalary();
                break;
                
            case 4:
            database.findLowestSalary();
            break;
            
           case 5:
           database.searchEmployeeById(); 
           break;
           
            case 6:
            cout<<"Exit!!";
            break;
            
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 6);

 return 0;
}
