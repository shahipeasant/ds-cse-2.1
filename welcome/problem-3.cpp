#include<iostream>
#include<iomanip>
#include<string>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int odd_cnt = 0;
    while(n!=0){
        if((n%10)%2!=0){
            odd_cnt++;
        }
        n /= 10;
    }
    
    cout << odd_cnt << endl;
    return 0;
}