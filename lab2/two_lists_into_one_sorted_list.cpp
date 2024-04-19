#include<iostream>
#include<cstdlib>
#include<ctime>
#include<random>
#include<algorithm>
using namespace std;

void stl(int * list1,int * list2,int n,int m)
{
    int count1=0;
    int count2=0;
    int count3=0;
    int list3[m+n];

    while(count2<m&&count1<n)
    {
        if(list1[count1]<list2[count2])
        {
            list3[count3]=list1[count1];
            count1++;
            count3++;
        }
        else
        {
            list3[count3]=list2[count2];
            count2++;
            count3++;
        }
    }

    while(count1<n)
    {
        list3[count3]=list1[count1];
        count1++;
        count3++;        
    }

    while(count2<m)
    {
        list3[count3]=list2[count2];
        count2++;
        count3++;        
    }

    // If you want to print the resulting list then uncomment the below code
    // for(int i=0;i<n+n;i++)
    // {
    //     cout<<list3[i]<<" ";
    // }

}

int main()
{

    // Just a simple example for checking the code
    // int a[5]={1,5,7,9,12};
    // int b[5]={4,6,8,10,15};
    // stl(a,b,5,5);

    float A;

    random_device rd;
    mt19937 gen(rd());

    for (int j = 10000; j <= 1000000; j += 10000)
    {
        int *a = new int[j];
        int *b = new int[j/10];

        uniform_int_distribution<int> dist(1, 1000000);

        for (int k = 0; k < j; k++)
        {
            a[k] = dist(gen);
        }
        for (int k = 0; k < j/10; k++)
        {
            b[k] = dist(gen);
        }
        sort(a,a+j);
        sort(b,b+j/10);
        clock_t t1 = clock();
        int t = 0;

        for (int x = 1; x <= 10; x++)
        {
            stl(a,b,j,j/10);
        }

        clock_t t2 = clock();
        A = (float)(t2 - t1) / 10;
        cout << A*100<< ",";

        // free up the memory used
        delete[] a;
        delete[] b;
    }
}
