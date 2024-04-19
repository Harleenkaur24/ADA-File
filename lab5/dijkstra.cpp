#include<iostream>
#include<map>
#include<list>
#include<stack>
using namespace std;
class graph
{
    public:
    map<int,list<int>>adj;
    map<int,list<int>>result;
    int arr[6][6]={0};


    void addedge(int u,int v)
    {
        adj[u].push_back(v);
        int w;
        cin>>w;
        arr[u][v]=w;
    }

    void printadjlist()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void printresultlist()
    {
        for(auto i:result)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void printweightmatrix()
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void dijkstraalgo(int source)
    {
        map<int,bool>visited;
        for(auto i:adj)
        {
            visited[i.first]=false;
        }
        visited[source]=true;
        result[source].push_back(0);


        
        map<int,int>dist;

        for(auto i:adj)
        {
            dist[i.first]=1000;
        }

        for(auto i:adj)
        {
            if(i.first==source)
            {
                for(auto j:i.second)
                {
                    if(visited[j]==false)
                    {
                        dist[j]=arr[i.first][j];
                    }
                }
            }
        }


        while(true)
        {

            int count=0;
            for(auto j:visited)
            {
                if(visited[j.first]==false)
                {
                    count++;
                }
            }
            if(count==0)
            {
                return;
            }

            int mini=100;
            int j;
            for(auto k:dist)
            {
                if(visited[k.first]==false)
                {
                    if(mini>dist[k.first])
                    {
                        mini=dist[k.first];
                        j=k.first;
                    }
                }
            }

            visited[j]=true;
            result[j].push_back(dist[j]);
            source=j;

            for(auto i:adj)
            {
                if(i.first==source)
                {
                    for(auto j:i.second)
                    {
                        if(j==-1)
                        {
                            continue;
                        }
                        if(dist[j]>dist[i.first]+arr[i.first][j])
                        {
                            dist[j]=dist[i.first]+arr[i.first][j];
                        }
                    }
                }
            }

        }

    }

};
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;

    graph g;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.printadjlist();
    g.printweightmatrix();
    g.dijkstraalgo(0);
    cout<<"Result matrix is:\n";
    g.printresultlist();
}

// 4
// 5
// 0
// 1
// 10
// 1
// 3
// 7
// 0
// 2
// 3
// 0
// 3
// 2
// 2
// 3
// 6
// 0->1,2,3,
// 1->3,
// 2->3,
