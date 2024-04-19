#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void exact_position(int * a,int n,int ele)
{
    int greater=0;
    int smaller=0;
    int indexed_position;
    for(int i=0;i<n;i++)
    {
        if(a[i]<ele)
        {
            smaller++;
        }
        else if(a[i]>ele)
        {
            greater++;
        }
        else
        {
            indexed_position=i;
        }
    }

    //swaping
    int t=a[indexed_position];
    a[indexed_position]=a[smaller];
    a[smaller]=t;

    int first=0;
    int last=n-1;
    int i;
    int j;
    while(first<last)
    {
        for(int i=first;i<smaller;i++)
        {
            if(a[i]>ele)
            {
                first=i;
                break;
            }
        }
        first=i;
        for(int j=n-1;j<smaller;j--)
        {
            if(a[j]<ele)
            {
                last=j;
                break;
            }
        }
        last=j;
        if(first<last)
        {
            int t=a[first];
            a[first]=a[last];
            a[last]=t;
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
}

int main ()
{
    // Simple case for testing function
    // int a[6]={5,1,2,3,6,8};
    // exact_position(a,6,5);

    float A;

    for (int j = 10000; j <= 1000000; j += 10000)
    {
        int a[j];
        for(int k=0;k<j;k++){
            a[k]=rand()%2;
        }
        clock_t t1 = clock();
        long long t = 0;

        for (int x = 1; x <= 10; x++)
        {
            exact_position(a,j,a[10]);
        }

        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A<< ",";
    }
}
