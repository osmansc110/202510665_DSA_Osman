#include <iostream>
#include "student.h"

using namespace std;

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent()
{
    if (studentCount >= MAX_STUDENTS)
    {
        cout << "\n[Error] System is full! Cannot add more students." << endl;
        return;
    }

    Student s;
    cout << "\nEnter Student ID: ";
    cin >> s.id;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == s.id)
        {
            cout << "[Error] Student ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Course: ";
    cin.ignore();
    getline(cin, s.course);

    students[studentCount] = s;
    studentCount++;
    cout << "\n[Success] Student added successfully!" << endl;
}

void displayStudents()
{
    if (studentCount == 0)
    {
        cout << "\nNo student records found." << endl;
        return;
    }

    cout << "\n--- Student Records ---" << endl;
    for (int i = 0; i < studentCount; i++)
    {
        cout << "ID: " << students[i].id
             << " | Name: " << students[i].name
             << " | Age: " << students[i].age
             << " | Course: " << students[i].course << endl;
    }
}

void searchStudent()
{
    if (studentCount == 0)
    {
        cout << "\nNo student records found." << endl;
        return;
    }

    int searchId;
    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == searchId)
        {
            cout << "\n[Student Found]" << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            return;
        }
    }
    cout << "\n[Notice] Student with ID " << searchId << " not found." << endl;
}

void updateStudent()
{
    if (studentCount == 0)
    {
        cout << "\nNo student records found." << endl;
        return;
    }

    int updateId;
    cout << "\nEnter Student ID to update: ";
    cin >> updateId;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == updateId)
        {
            cout << "\nCurrent Data -> Name: " << students[i].name << ", Age: " << students[i].age << ", Course: " << students[i].course << endl;

            cout << "\nEnter New Name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter New Age: ";
            cin >> students[i].age;
            cout << "Enter New Course: ";
            cin.ignore();
            getline(cin, students[i].course);

            cout << "\n[Success] Student information updated successfully!" << endl;
            return;
        }
    }
    cout << "\n[Error] Student ID not found." << endl;
}

void deleteStudent()
{
    if (studentCount == 0)
    {
        cout << "\nNo student records found." << endl;
        return;
    }

    int deleteId;
    cout << "\nEnter Student ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == deleteId)
        {

            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "\n[Success] Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "\n[Error] Student ID not found." << endl;
}