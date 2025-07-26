#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    char name[10];
    double cgpa;
};

int partition(vector<Student> &a, int l, int r) {
    int start = l;
    int end = r;
    double pivot = a[start].cgpa;

    while(start < end) {
        while(start < r && a[start].cgpa <= pivot) start++;
        while(a[end].cgpa > pivot) end--;
        if(start < end) {
            swap(a[start], a[end]);
        }
    }
    swap(a[end], a[l]);
    return end;
}

void quickSort(vector<Student> &a, int l, int r) {
    if(l < r) {
        int q = partition(a, l, r);
        quickSort(a, l, q - 1);
        quickSort(a, q + 1, r);
    }
}

int main()
{
    vector<Student> students;
    Student s;
    while(cin >> s.name >> s.id >> s.cgpa){
        students.push_back(s);
    }
    quickSort(students, 0, students.size()-1);
    for(const Student &stu: students){
        cout << stu.name << " "<< stu.id << " " << stu.cgpa << endl;
    }

    return 0;
}