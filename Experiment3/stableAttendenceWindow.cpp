//Aditya Dubey
//24BCS10457

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int N;
    cin>>N;

    char a[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }

    unordered_map<int,int> at;
    int csum=0;
    int mx=0;

    at[0]=-1;

    for(int i=0;i<N;i++)
    {
        if(a[i]=='P')
        {
            csum+=1;
        }

        else
        {
            csum-=1;
        }

        if(at.find(csum)!=at.end())
        {
            mx=max(mx,i-at[csum]);
        }

        else
        {
            at[csum]=i;
        }
    }
    cout<<mx;
    return 0;
}