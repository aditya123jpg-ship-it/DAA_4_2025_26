#include<iostream>
using namespace std;

void heapifydown(int arr[],int index,int n)
{
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }

    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }

    if(largest!=index)
    {
        swap(arr[largest],arr[index]);
        heapifydown(arr,largest,n);
    }
}

void heapifyup(int arr[],int i)
{
    int p=(i-1)/2;
    if(p>=0 && arr[i]>arr[p])
    {
        swap(arr[i],arr[p]);
        heapifyup(arr,p);
    }
}

void build(int arr[],int n)
{
    for(int i=(n-1)/2;i>=0;i++)
    {
        heapifydown(arr,i,n);
    }
}

int find(int arr[],int key,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

void del(int arr[],int key,int &n)
{

    int index=find(arr,key,n);

    if(index == -1)
    {
        cout << "Element not found\n";
        return;
    }

    arr[index]=arr[n-1];
    n--;

    if(index<n)
    {
    int parent=(index-1)/2;
    
    if(index>0 && arr[parent]<arr[index])
    {
        heapifyup(arr,index);
    }
    else
    {
        heapifydown(arr,index,n);
    }
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int arr[10]={55,6,7,0,1,2,3,44,709,100};
    int n=10;
    build(arr,n);
    print(arr,n);
    del(arr,44,n);
    print(arr,n);
}