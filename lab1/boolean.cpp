#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;
void str(char * x, int n,int m)
{
    if(n==m)
    {
        // for(int i=0;i<m;i++)
        // {
        //     cout<<x[i];
        // }
        // cout<<endl;
        // cout<<"Done"<<endl;
    }
    else
    {
        x[n]='T';
        str(x,n+1,m);
        x[n]='F';
        str(x,n+1,m);
    }
}

int main(){
    float A;
    for(int j=1;j<=100;j++){
        char x[j];
        clock_t t1=clock();
        for(int o=1;o<=10;o++){
            str(x,0,j);
        }
        clock_t t2=clock();
        A=(float)(t2-t1)/10;
        cout<<A<<",";
    }
}
