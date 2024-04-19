#include <iostream>
#include <chrono>
#include <cstdlib>
	
using namespace std;
using namespace std::chrono;

int *generate_input(int arr[], int k)
{
    for (int j = 0; j < k; j++)
    {
        arr[j] = rand();
    }
    return arr;
}

int HR(int arr[], int m, int n, int x)
{
    if (m == n)
    {
        return arr[m];
    }
    return (HR(arr, m, n + 1, x)) * x + arr[n];
}

int main()
{
    const int maxSize = 10000;
    int arr[maxSize];

    for (int i = 100; i <= maxSize; i += 500)
    {
        int * a = generate_input(arr, i);
        auto start = high_resolution_clock::now();

        for (int m = 1; m <= 10; m++)
        {
            HR(a, i, 0, 10000);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;

        cout << "inputs \t" << i << "\t Time taken: " << duration.count() << " nanoseconds" << endl;
    }

    return 0;
}

