//
//  main.cpp
//  student-information-system
//
//  Created by Ahmet Bora Bakır on 2/18/26.
//

/*
 CENG218 – Labwork 1
 Write a C++ program that implements the following structure:
 <<struct>>
 Student
 + studentNumber: int
 + fullName[]: char
 + marksTotal: float
 + subjectMarks: float*
 After implementing the structure, implement the following functions:
  void inputStudent(Student&, int)  Function that takes a Student instance, and number of
 subjects that the students are responsible from and sets the respective student’s
 studentNumber, fullName, and subjectMarks (be careful that dynamic memory allocation
 is needed here). Then calculates the total marks and assigns it to marksTotal.
  float calculateAverage(const Student&, int)  Function that calculates and returns the
 average of the marks of a student (total marks / number of subjects).
  void displayStudent(const Student&, int)  Function that displays information about the
 respective student in the following format:
 --- Student Details ---
 Student Number: 202123456
 Name: Adam Collins
 Marks: 25 15 30
 Average Marks: 23.3333
 Then in the main function, take the number of students and number of subjects as input from
 the user and create a dynamic array of type Student, input the details and display their
 information by using the above functions. Finally, find and display the most successful
 student’s name and average marks in the following format (Reminder: Don’t forget to free the
 dynamically allocated memories):
 --- Top Student ---
 Name: Phil Tailor
 Average Marks: 36.6667
 */

#include <iostream>
using namespace std;

struct Student
{
    int studentNumber;
    char fullName[99];
    float marksTotal = 0;
    float* subjectMarks;
};

void inputStudent(Student& student, int subjectNumber)
{
    while(true)
    {
        cout << "Input student number: ";
        cin >> student.studentNumber;
        try
        {
            if(student.studentNumber < 0)
                throw "An error occured while setting up student number.\n";
            else break;
        }
        catch(const char* error)
        {
            cout << error;
            continue;
        }
    }
    
    cin.ignore();
    cout << "Input student name: ";
    cin.getline(student.fullName, 99);
    
    student.subjectMarks = new float[subjectNumber];
    
    for(int i = 0 ; i < subjectNumber ; i++)
    {
        cout << "Please input subjectMarks: ";
        cin >> student.subjectMarks[i];
        
        try
        {
           if(student.subjectMarks[i] < 0)
               throw "student.subjectMarks is out of range!\n";
        }
        catch (const char* error)
        {
            cout << error;
            i--;
        }
        student.marksTotal += student.subjectMarks[i];
        
    }
    
}
float calculateAverage(const Student& student, int subjectNumber)
{
    return student.marksTotal / subjectNumber;
}

void displayStudent(const Student& student, int subjectNumber)
{
    cout << "--- Student Details ---" << endl;
    cout << "Student number: " << student.studentNumber << endl;
    cout << "Student name: " << student.fullName << endl;
    cout << "Marks: ";
    for(int i = 0 ; i < subjectNumber ; i++)
    {
        cout << " " << student.subjectMarks[i];
    }
    cout << "Average Marks: " << calculateAverage(student, subjectNumber);
    
}

int main()
{
    int studentSize;
    int subjectNumber;
    while(true)
    {
        cout << "Input student amount: ";
        cin >> studentSize;
        try
        {
            if(studentSize < 0)
                throw "Out of range!\n";
            else break;
        }
        catch(const char* error)
        {
            cout << error;
            continue;
        }
    }
    
    while(true)
    {
        cout << "Input subject number: ";
        cin >> subjectNumber;
        try
        {
            if(subjectNumber < 0)
                throw "Out of range!\n";
            else break;
        }
        catch (const char* error)
        {
            cout << error;
            continue;
        }
    }
    Student *students = new Student[studentSize];
    
    for(int i = 0 ; i < studentSize ; i++)
    {
        inputStudent(students[i], subjectNumber);
        
    }
    for(int i = 0 ; i < studentSize ; i++)
    {
        displayStudent(students[i], subjectNumber);
    }
    
    Student max = students[0];
    int flag;
    for(int i = 0 ; i < studentSize ; i++)
    {
        flag = 0;
        for(int j = 1 ; j < studentSize ; j++)
        {
            if(calculateAverage(students[i], subjectNumber) < calculateAverage(students[j], subjectNumber))
            {
                max = students[j];
                flag = 1;
            }
        }
        if(flag == 0) break;
        
    }
    
    cout << "--Top Student--" << endl;
    cout << "Name: " << max.fullName << endl;
    cout << "Average Marks: " << calculateAverage(max, subjectNumber) << endl;
    
    
    for(int i = 0 ; i < studentSize ; i++)
    {
        delete[] students[i].subjectMarks;
    }
    delete[] students;
}
