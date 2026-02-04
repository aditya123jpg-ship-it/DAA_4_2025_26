#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr=new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int index = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            index = i;
            break;
        }
    }

    if(index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element Not found";

    return 0;
}