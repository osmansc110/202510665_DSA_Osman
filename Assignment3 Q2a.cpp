#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string course;
};
[span_6](start_span) //[span_6](end_span)

    void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
[span_7](start_span)[span_8](start_span) //[span_7](end_span)[span_8](end_span)

#endif