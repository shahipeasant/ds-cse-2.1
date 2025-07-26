#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r) {
    int start = l;
    int end = r;
    int pivot = a[start];

    while(start < end) {
        while(start < r && a[start] <= pivot) start++;
        while(a[end] > pivot) end--;
        if(start < end) {
            swap(a[start], a[end]);
        }
    }
    swap(a[end], a[l]);
    return end;
}

void quickSort(int a[], int l, int r) {
    if(l < r) {
        int q = partition(a, l, r);
        quickSort(a, l, q - 1);
        quickSort(a, q + 1, r);
    }
}

int main() {
    int a[] = {50, 40, 30, 20};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
