#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;


void iterative_min_max(int *a,int n)
{
    int min=a[0];
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    // cout<<"Minimum = "<<min<<endl;
    // cout<<"Maximum = "<<max<<endl;
}

pair<int,int> min_max(int * a,int low,int high)
{
    if(low==high)
    {
        return make_pair(a[low],a[high]);
    }
    else
    {
        int mid=(low+high)/2;
        pair<int,int> p1 = min_max(a,low,mid);
        pair<int,int> p2 = min_max(a,mid+1,high);
        int mi=p1.first;
        int ma=p1.second;

        if(p1.first>p2.first)
        {
            mi=p2.first;
        }
        if(p1.second<p2.second)
        {
            ma=p2.second;
        }
        return make_pair(mi,ma);
    }
}

int main()
{
    // int a[6]={1,5,5,2,6,3};
    // pair<int,int>p=min_max(a,0,5);
    // cout<<"MINIMUM = "<<p.first<<"\n"<<"MAXIMUM = "<<p.second<<"\n";


    // Recursive calls
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
            pair<int,int>p=min_max(a,0,j-1);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }

    cout<<"Done"<<endl;

    //Iterative calss
    float A1;
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
            iterative_min_max(a,j);
        }
        clock_t t2=clock();
        A1=(float)(t2-t1)/10;
        cout<<A1<<",";
    }
}
