#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
	
void TOH(int n,char source,char auxillary,char destination)
{
If (n==1)  //Base case
{
Cout<<"Move disk"<<n<<" from rod "<< source << "to rod" << destination;
}
 if(n>1)
  {
      TOH(n-1,source,destination,auxillary);
      cout << "move disk " << n<<"from rod " <<source << "-> " << destination; << endl;
      TOH(n-1,auxillary,source,destination);
  }
}

int main()
{
    int *arr = new int[1000000];
    for(int i=15;i<= 30;i=i+1)
    {

    auto start = high_resolution_clock::now();
    for(int m =1;m<=10;m++)
    {
        TOH(i,'start','auxillary','destination');
    }
    auto stop = high_resolution_clock::now();
    auto duration = (duration_cast<nanoseconds>(stop-start))/10;
    cout << "inputs \t" << i    << "\t Time taken: " << duration.count() << "nanoseconds" << endl ;
   
    }

    return 0;
}

