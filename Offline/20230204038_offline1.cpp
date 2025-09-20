#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> &v, int n){
    for(int i=1; i<n; i++){
        int temp = v[i];
        int j = i-1;
        while(v[j]>temp&&j>=0){
            v[j+1]=v[j];
            j--;
        }
        v[j+1] = temp;
    }
}

void Bseacrh(vector<int> &v, int n, int key){
    int flag = 0;
    int m = 0;
    int lo=0;
    int hi=n-1;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(v[mid]==key){
            flag = 1;
            m = mid;
            break;
        }
        if(v[mid]<key){
            lo=mid+1;
        }
        if(v[mid]>key){
            hi=mid-1;
        }
    }
    cout << "sorted vector: ";
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    if(flag == 1){
        cout << "value " << key << " found at position " << m << endl;
    }
    else{
        cout << "value " << key << " can be inserted at position " << lo+1 << " to maintain sorted order"<< endl;
    }
}

int main(){
    vector<int> v;
    cout << "Enter the vector: ";
    int t = 0;
    while(t!=EOF){
        cin >> t;
        v.push_back(t);
    }
    
    int key;
    cout << "Enter the value to search: ";
    cin >> key;
    sort(v, v.size());
    Bseacrh(v, v.size(), key);
    return 0;
}