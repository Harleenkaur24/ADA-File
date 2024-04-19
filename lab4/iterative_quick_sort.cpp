#include<iostream>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cmath>
using namespace std;
int partition(int * arr,int p,int r)
{
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(arr[j]<x)
        {
            i++;
            int t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }
    i++;
    int t=arr[r];
    arr[r]=arr[i];
    arr[i]=t;
    return i;
}

void iterative(stack<int>&s ,int * arr, int p,int r)
{
    if(p<r)
    {
        int j=partition(arr,p,r);
        if(p+j<r-j)
        {
            s.push(r);
            s.push(j+1);
        }
        else
        {
            s.push(j-1);
            s.push(p);
        }
        if(s.empty())
        {
            return;
        }
        else
        {
            int p=s.top();
            s.pop();
            int r=s.top();
            s.pop();
            iterative(s,arr,p,r);
        }
    }
}
int main()
{
    stack<int>s;
    // int arr[10]={9,5,1,4,2,6,3,7,8,10};
    // iterative(s,arr,0,9);
    // for(int i=0;i<10;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // for(int j=1000;j<=100000;j=j+1000)
    // {
    //     cout<<j*log(j)/1000<<",";
    // }
    
    float A;
    for(int j=1000;j<=100000;j=j+1000)
    {
        int a[j];
        for(int k=0;k<j;k++)
        {
            a[k]=rand();
        }
        clock_t t1=clock();
        for(int l=0;l<10;l++)
        {
            iterative(s,a,0,j-1);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }

}
