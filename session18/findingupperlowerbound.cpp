#include<iostream>
using namespace std;

int main()
{
    int numbers[] = {1,1,2,3,7};
    int size = 5;
    int target = 1;

    int start = 0, end = size - 1;
    int lowerIndex = size;

    while(start <= end)
    {
        int middle = (start + end) / 2;
        if(numbers[middle] >= target)
        {
            lowerIndex = middle;
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    start = 0;
    end = size - 1;
    int upperIndex = size;

    while(start <= end)
    {
        int middle = (start + end) / 2;

        if(numbers[middle] > target)
        {
            upperIndex = middle;
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    cout << lowerIndex << endl;
    cout << upperIndex << endl;

    if(lowerIndex < size && numbers[lowerIndex] == target)
        cout << upperIndex - lowerIndex;
    else
        cout << 0;
}
