#include <iostream>
#include <vector>
#include <memory>
#include "Student.hpp"
#include "MergeSort.hpp"

using namespace std;

int main()
{
    // Use smart pointers for automatic memory management
    unique_ptr<Student> Alexis = make_unique<Student>("Alexis SANTOS", 18, 1, 13.65); // Add Alexis as a Student
    unique_ptr<Student> Gregory = make_unique<Student>("Grégory PAGNOUX", 21, 3, 14.43); // Add Grégory as a Student
    unique_ptr<Student> Laurent = make_unique<Student>("Laurent BOUQUIN", 23, 5, 16.89); // Add Laurent as a Student
    unique_ptr<Student> Lena = make_unique<Student>("Léna DE GERMAIN", 18, 1, 12.5); // Add Léna as a Student
    unique_ptr<Student> Matteo = make_unique<Student>("Mattéo LEFIN", 19, 2, 14.2); // Add Matteo as a Student

    // Vector of unique pointers to Student objects
    vector<unique_ptr<Student>> Students = {move(Alexis), move(Matteo), move(Lena), move(Laurent), move(Gregory)};

    // Print the list of students
    for (const auto& student : Students) {
        cout << "Student Name: " << student->GetName() << endl;
        cout << "Age: " << student->GetAge() << endl;
        cout << "Years Passed at School: " << student->GetSeniority() << endl;
        cout << "Average Marks: " << student->GetAverage() << endl;
        cout << "------------------------" << endl;
    }

    // Sort the students by their average marks using merge sort
    mergeSort(Students, 0, Students.size() - 1);

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
