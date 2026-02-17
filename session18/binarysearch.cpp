#include<iostream>
using namespace std;

int main()
{
    int key;
    cin>>key;

    int dum[5]={2,3,4,5,6};

    int l=0;
    int r=4;

    int mid=(l+r)/2;
    int flag=0;

    while(l<=r)
    {
        if(dum[mid]==key)
        {
            flag=1;
        }

        else if(dum[mid]>key)
        {
            r=mid-1;
        }

        else
        {
            l=mid+1;
        }
    }

    if(flag)
    {
        cout<<"Element found at: "<<mid<<endl;
    }

    else
    {
        cout<<"element not found";
    }
}