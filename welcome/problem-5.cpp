#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    int k;
    cout << "K: ";
    cin >> k;
    cout << endl;
    while (k--)
    {
        for (int i = 1; i < size; i++)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}