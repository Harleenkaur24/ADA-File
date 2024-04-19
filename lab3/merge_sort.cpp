#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void merge(int * a, int low, int mid, int high)
{
    int r[100];
    int count = low;
    int store = low;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (a[left] < a[right])
        {
            r[count] = a[left];
            left++;
        }
        else
        {
            r[count] = a[right];
            right++;
        }
        count++;
    }

    while (left <= mid)
    {
        r[count] = a[left];
        left++;
        count++;
    }

    while (right <= high)
    {
        r[count] = a[right];
        right++;
        count++;
    }

    for (int i = store; i <= high; i++)
    {
        a[i] = r[i];
    }
}


void mergesort(int * a,int low,int high)
{
    if(low<high)
    {
        int mid=(high+low)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    //Sample case for example
    // int a[6]={6,5,4,3,2,1};
    // mergesort(a,0,5);
    // for(int i=0;i<6;i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    for(int j=0;j<=100;j++)
    {
        cout<<j*log(j)<<",";
    }

    float A;
    for(int j=1;j<=100;j=j+1)
    {
        int a[j];
        for(int k=0;k<j;k++)
        {
            a[k]=rand();
        }
        clock_t t1=clock();
        for(int l=0;l<10;l++)
        {
            mergesort(a,0,j-1);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }

}
