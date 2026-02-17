#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int dum1[] = {5,4,1,2,0};
    int dum2[] = {1,1,2,3,7};

    int count = 0;

    for(int i = 0; i < 5; i++)
    {
        int key = 7 - dum1[i];

        int* lower = lower_bound(dum2, dum2 + 5, key);
        int* upper = upper_bound(dum2, dum2 + 5, key);

        if(lower != dum2 + 5 && *lower == key)
            count += (upper - lower);
    }

    cout << "count: " << count;
}
