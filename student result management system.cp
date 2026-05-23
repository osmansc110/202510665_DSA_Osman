#include <iostream>

using namespace std;

// Function to display pass or fail
void checkResult(float average)
{
    if (average >= 50)
    {
        cout << "\t\tResult: PASSED" << endl;
    }
    else
    {
        cout << "\t\tResult: FAILED" << endl;
    }
}

int main()
{
    char name[50];
    float mark1, mark2, mark3;
    float total, average;
    char choice;

    do
    {
        cout << "\n\t\t============================" << endl;
        cout << "\t\tStudent Result Management System" << endl;
        cout << "\t\t============================" << endl;

        // Input student name
        cout << "Enter student name: ";
        cin >> name;

        // Input marks
        cout << "Enter marks for Subject 1: ";
        cin >> mark1;

        cout << "Enter marks for Subject 2: ";
        cin >> mark2;

        cout << "Enter marks for Subject 3: ";
        cin >> mark3;

        // Calculate total and average
        total = mark1 + mark2 + mark3;
        average = total / 3;

        // Display results
        cout << "\n\t\t----- Student Result -----" << endl;
        cout << "\t\tStudent Name: " << name << endl;
        cout << "\t\tTotal Marks: " << total << endl;
        cout << "\t\tAverage Marks: " << average << endl;

        // Function call
        checkResult(average);

        // Continue or stop
        cout << "\nDo you want to enter another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nProgram Ended Successfully." << endl;

    return 0;
}