#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int * generate_input(int arr[],int k)
{
    for(int j=1;j<=k;j++)
    {
        arr[j]=rand();
    }
    return arr;
}

int sum (int arr[],int n)
{
    if(n==1) //Base case if array contains only 1 element
    {
        return arr[0];
    }

    return(sum(arr,n-1)+arr[n-1]);
}

int main()
{
    int *arr = new int(100000);
    for(int i=1000;i<=100000 ;i=i*5)
    {
    arr = generate_input(arr,i);

    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        int s = sum(arr,i);
        cout << s << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken: " << duration.count() << "nanoseconds" << endl ;
    }

    return 0;
}

