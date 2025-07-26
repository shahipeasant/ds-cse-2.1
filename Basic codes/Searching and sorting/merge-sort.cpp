#include<bits/stdc++.h>
using namespace std;

//merge sort

//merge sort is a divide and conquer algortihm for sorting an array
//Divide: it recursively divides the array into smaller ones, goes on until it
//becomes an one-element array
//Conquer: it recursively merges the (sorted) arrays in a way such that
//elements of merged array is in sorted order
//starting with merging 2 one-element arrays so that merged array has the elements sorted
//goes on with merging them until we get the whole array sorted

//pseudocode for merge
//0.  Merge(low, mid, high)
//1.  m = (mid-low)+1
//2.  n = (high-mid)
//3.  Let L[0, 1, ...., m] and R[0, 1, ...., n] be two arrays
//4.  For i = 0 to m-1
//5.     L[i] = A[low+i]
//6.  For j = 0 to n-1
//7.     R[j] = A[mid+1+j]
//8.  L[m] = infinity, R[n] = infinity
//9.  i = j = 0
//10. For k = low to high
//11.    If L[i]<=R[j]
//12.       A[k] = L[i]
//13.       i = i + 1
//14.    Else
//15.       A[k] = R[j]
//16.       j = j + 1

void merge(vector<int>& A, int low, int mid, int high) {
    int m = mid - low + 1;
    int n = high - mid;

    vector<int> L(m + 1), R(n + 1);

    for (int i = 0; i < m; ++i)
        L[i] = A[low + i];

    for (int j = 0; j < n; ++j)
        R[j] = A[mid + 1 + j];

    L[m] = INT_MAX;  // Sentinel value
    R[n] = INT_MAX;

    int i = 0, j = 0;
    for (int k = low; k <= high; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
}

//pseudocode for mergesort
//0.  MergeSort(low, high)
//1.  mid = (high-low)+1
//2.  If low < high
//3.     MergeSort(low, mid)
//4.     MergeSort(mid+1, high)
//4.     Merge(low, mid, high)

void mergeSort(vector<int>& A, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
