#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <memory>
#include "Student.h"

using namespace std;

// Function to merge two halves
void merge(vector<unique_ptr<Student>>& students, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<unique_ptr<Student>> L(n1);
    vector<unique_ptr<Student>> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = move(students[left + i]);
    for (int j = 0; j < n2; j++)
        R[j] = move(students[mid + 1 + j]);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i]->GetName() <= R[j]->GetName()) {
            students[k] = move(L[i]);
            i++;
        } else {
            students[k] = move(R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        students[k] = move(L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        students[k] = move(R[j]);
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<unique_ptr<Student>>& students, int left, int right) {
    if (left >= right) {
        return; // Returns recursively
    }
    int mid = left + (right - left) / 2;
    mergeSort(students, left, mid);
    mergeSort(students, mid + 1, right);
    merge(students, left, mid, right);
}

#endif