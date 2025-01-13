#include <iostream>
#include <vector>
#include <memory>
#include "Student.hpp"
#include "MergeSort.hpp"

using namespace std;

int main()
{
    // Use smart pointers for automatic memory management
    unique_ptr<Student> Jean = make_unique<Student>("Jean PATRICK", 18, 1, 13.65); // Add Alexis as a Student
    unique_ptr<Student> Gregoire = make_unique<Student>("Grégoire THOMAS", 21, 3, 14.43); // Add Grégory as a Student
    unique_ptr<Student> Ulysse = make_unique<Student>("Ulysse BAGANTIN", 23, 5, 16.89); // Add Laurent as a Student
    unique_ptr<Student> Laurenne = make_unique<Student>("Laurenne GAMINA", 18, 1, 12.5); // Add Léna as a Student
    unique_ptr<Student> Baptiste = make_unique<Student>("Baptiste BOULANGER", 19, 2, 14.2); // Add Matteo as a Student

    // Vector of unique pointers to Student objects
    vector<unique_ptr<Student>> Students;
    Students.push_back(move(Jean));
    Students.push_back(move(Gregoire));
    Students.push_back(move(Ulysse));
    Students.push_back(move(Laurenne));
    Students.push_back(move(Baptiste));

    // Print the list of students
    cout << "------------------------" << endl;
    for (const auto& student : Students) {
        cout << "Student Name: " << student->GetName() << endl;
        cout << "Age: " << student->GetAge() << endl;
        cout << "Years Passed at School: " << student->GetSeniority() << endl;
        cout << "Average Marks: " << student->GetAverage() << endl;
        cout << "------------------------" << endl;
    }

    // Sort the students by their average marks using merge sort
    mergeSort(Students, 0, Students.size() - 1);

    cout << "Merge Students List : " << endl;
    cout << "------------------------" << endl;

    // Print the sorted list of students
    for (const auto& student : Students) {
        cout << "Student Name: " << student->GetName() << endl;
        cout << "Age: " << student->GetAge() << endl;
        cout << "Years Passed at School: " << student->GetSeniority() << endl;
        cout << "Average Marks: " << student->GetAverage() << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}
