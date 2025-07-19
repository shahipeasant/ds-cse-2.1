#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> v, int n){
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(v[j]<v[i]){
                swap(v[j+1], v[i]);
            }
        }
    }
}

void Bseacrh(vector<int> v, int n, int key){
    int lo=0;
    int hi=n-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(mid==key){
            hi=mid-1;
        }
        if(mid<key){
            lo=mid+1;
        }
        if(mid>key){
            hi=mid-1;
        }
    }
    cout << "sorted vector: ";
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    if(lo==key){
        cout << "value " << key << " found at position " << lo-1 << endl;
    }
    else{
        cout << "value " << key << " can be inserted at position " << lo-2 << " to maintain sorted order"<< endl;
    }
}

int main(){
    int n;
    cout << "Enter length of vector: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the vector: ";
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int key;
    cout << "Enter the value to search: ";
    cin >> key;
    sort(v, n);
    Bseacrh(v, n, key);
    return 0;
}