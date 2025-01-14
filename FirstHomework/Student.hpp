#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

// Define the class Student
class Student
{
private:
    // Variables of my class
    string Name;
    int Age = 18;
    int YearsPassedAtSchool = 1;
    vector<float> Marks;
    float AvgMarks = 0;

public:
    // Functions of my class
    Student(string name, int age = 18, int years = 1, float avg = 0) { // Constructor of my class
        Name = name;
        Age = age;
        YearsPassedAtSchool = years;
        Marks.push_back(avg);
        NewAvg(); // Initialize the average correctly
    }

    // Base functions to get variable
    string GetName() const { // Function to get the Name.
        return Name;
    }

    int GetAge() const { // Function to get how old are the Student.
        return Age;
    }

    int GetSeniority() const { // Function to get the year of experience of the Student.
        return YearsPassedAtSchool;
    }

    float GetAverage() const { // Function to get the average of the Student.
        return AvgMarks;
    }

    int GetNumberMarks() const {
        return Marks.size();
    }

    float NewAvg() { // Function to average Student's Marks
        float sumMarks = 0;
        for (size_t i = 0; i < GetNumberMarks(); i++)
        {
            sumMarks += Marks[i];
        }
        if (Marks.size() > 0)
        {
            AvgMarks = sumMarks / GetNumberMarks();
        }
        return AvgMarks;
    }

    // Base function to change variables.
    void Birthday() { // Function to increase by 1 the Age of the Student
        Age += 1;
    }

    void NewSchoolYear() { // Function to increase the year of experience
        YearsPassedAtSchool += 1;
    }

    void AddMark(float note) {
        Marks.push_back(note);
        NewAvg();
    }

    void FireStudent() { // Function to fire a Student from the School
        delete this;
    }
};

#endif
