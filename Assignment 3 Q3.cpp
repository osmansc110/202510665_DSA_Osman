#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "   STUDENT MANAGEMENT SYSTEM   " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Update Student Info" << endl;
        cout << "5. Delete a Student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            cout << "\nExiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "\n[Invalid Choice] Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    return 0;
}