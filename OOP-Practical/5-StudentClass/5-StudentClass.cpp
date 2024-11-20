#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_SUBJECTS = 5;
const int MAX_STUDENTS = 10;
const int MAX_ASSIGNMENTS = 10;
const int MAX_QUESTIONS = 7;

class Student {
protected:
    string name;
    int rollNo;
    string subjects[MAX_SUBJECTS];
    int numSubjects;

public:
    Student() : numSubjects(0), rollNo(0) {}

    virtual void input() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter number of subjects: ";
        cin >> numSubjects;
        for (int i = 0; i < numSubjects; i++) {
            cout << "Enter subject " << i + 1 << ": ";
            cin >> subjects[i];
        }
    }

    virtual void display() {
        cout << setw(15) << name << setw(10) << rollNo << setw(15);
        for (int i = 0; i < numSubjects; i++) {
            cout << subjects[i] << " ";
        }
        cout << endl;
    }

    virtual int getRollNo() {
        return rollNo;
    }

    virtual void edit() {
        input();
    }
};

class DerivedStudent : public Student {
private:
    string subjectCode[MAX_SUBJECTS];
    int internalMarks[MAX_SUBJECTS];
    int externalMarks[MAX_SUBJECTS];
    int finalMarks[MAX_SUBJECTS];

public:
    void input() override {
        Student::input();
        for (int i = 0; i < numSubjects; i++) {
            cout << "Enter subject code for " << subjects[i] << ": ";
            cin >> subjectCode[i];

            // Input assignment marks
            int totalAssignmentMarks = 0;
            cout << "Enter " << MAX_ASSIGNMENTS << " assignment marks (out of 10 each) for " << subjects[i] << ":\n";
            for (int j = 0; j < MAX_ASSIGNMENTS; j++) {
                int mark;
                cout << "Assignment " << (j + 1) << ": ";
                cin >> mark;
                totalAssignmentMarks += mark;
            }
            internalMarks[i] = (totalAssignmentMarks * 30) / 100;

            // Input question marks
            int totalQuestionMarks = 0;
            cout << "Enter marks for " << MAX_QUESTIONS << " questions (out of 10 each) for " << subjects[i] << ":\n";
            for (int j = 0; j < MAX_QUESTIONS; j++) {
                int questionMark;
                cout << "Question " << (j + 1) << ": ";
                cin >> questionMark;
                totalQuestionMarks += questionMark;
            }
            externalMarks[i] = totalQuestionMarks;

            // Calculate final marks
            finalMarks[i] = internalMarks[i] + externalMarks[i];
        }
    }

    void display() override {
        Student::display();
        cout << setw(20) << "Subject Code" << setw(25) << "Internal Marks" << setw(30) << "External Marks" << setw(35) << "Final Marks" << endl;
        for (int i = 0; i < numSubjects; i++) {
            cout << setw(20) << subjectCode[i] << setw(25) << internalMarks[i]
                 << setw(30) << externalMarks[i] << setw(35) << finalMarks[i] << endl;
        }
    }

    void edit() override {
        Student::edit();
        for (int i = 0; i < numSubjects; i++) {
            cout << "Enter new subject code for " << subjects[i] << ": ";
            cin >> subjectCode[i];

            // Recalculate internal marks
            int totalAssignmentMarks = 0;
            cout << "Enter " << MAX_ASSIGNMENTS << " assignment marks (out of 10 each) for " << subjects[i] << ":\n";
            for (int j = 0; j < MAX_ASSIGNMENTS; j++) {
                int mark;
                cout << "Assignment " << (j + 1) << ": ";
                cin >> mark;
                totalAssignmentMarks += mark;
            }
            internalMarks[i] = (totalAssignmentMarks * 30) / 100;

            // Recalculate external marks
            int totalQuestionMarks = 0;
            cout << "Enter marks for " << MAX_QUESTIONS << " questions (out of 10 each) for " << subjects[i] << ":\n";
            for (int j = 0; j < MAX_QUESTIONS; j++) {
                int questionMark;
                cout << "Question " << (j + 1) << ": ";
                cin >> questionMark;
                totalQuestionMarks += questionMark;
            }
            externalMarks[i] = totalQuestionMarks;

            // Recalculate final marks
            finalMarks[i] = internalMarks[i] + externalMarks[i];
        }
    }
};

class Management {
private:
    DerivedStudent students[MAX_STUDENTS];
    int studentCount;

public:
    Management() : studentCount(0) {}

    void buildMasterTable() {
        int num;
        cout << "How many students do you want to enter? ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            cout << "\nEnter details for student " << i + 1 << ":\n";
            students[studentCount].input();
            studentCount++;
        }
    }

    void listTable() {
        cout << "\nMaster Table:\n";
        cout << setw(15) << "Student Name" << setw(10) << "Roll No" << setw(15) << "Subjects" << endl;
        for (int i = 0; i < studentCount; i++) {
            students[i].display();
        }
    }

    void insertEntry() {
        if (studentCount >= MAX_STUDENTS) {
            cout << "Student limit reached, cannot add more students.\n";
            return;
        }
        cout << "\nEnter details for new student:\n";
        students[studentCount].input();
        studentCount++;
    }

    void deleteEntry() {
        int rollNo;
        cout << "\nEnter roll number to delete: ";
        cin >> rollNo;

        int pos = -1;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == rollNo) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "Student not found.\n";
            return;
        }

        for (int i = pos; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "Student record deleted.\n";
    }

    void editEntry() {
        int rollNo;
        cout << "\nEnter roll number to edit: ";
        cin >> rollNo;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == rollNo) {
                students[i].edit();
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void searchRecord() {
        int rollNo;
        cout << "\nEnter roll number to search: ";
        cin >> rollNo;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRollNo() == rollNo) {
                students[i].display();
                return;
            }
        }

        cout << "Student not found.\n";
    }
};

int main() {
    Management manage;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Build Master Table\n";
        cout << "2. List Table\n";
        cout << "3. Insert New Entry\n";
        cout << "4. Delete Old Entry\n";
        cout << "5. Edit an Entry\n";
        cout << "6. Search for a Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manage.buildMasterTable();
                break;
            case 2:
                manage.listTable();
                break;
            case 3:
                manage.insertEntry();
                break;
            case 4:
                manage.deleteEntry();
                break;
            case 5:
                manage.editEntry();
                break;
            case 6:
                manage.searchRecord();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

  return 0;
}
