#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int encrypt(int n){
    int m= 0;
    int place = 1;
    while(n!=0){
        m += (((n%10)+5)%10)*place;
        place *= 10;
        n /= 10;
    }

    return m;
}

int main()
{
    int n;
    cout << "Employee ID: ";
    cin >> n;
    cout << endl;

    cout << encrypt(n) << endl;
    
    return 0;
}