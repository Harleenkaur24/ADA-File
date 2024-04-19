#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph,vector<int>&color, int c){
    for(int i=0; i< graph.size(); ++i){
        if (graph[v][i] && c==color[i])
        return false;
    }
    return true;

}
bool mColoringUtil(vector<vector<int>>&graph, int m, vector<int>& color,int v){
    if (v==graph.size())  //Base Case
    return true;
for(int c=1; c<=m; ++c){
    if (isSafe(v,graph,color,c)){
        color[v]=c;
        if (mColoringUtil(graph,m,color,v+1))
        return true;
       color[v] =0;
    }
}
return false;
}

bool mColoring(vector<vector<int>>&graph, int m){
    int v=graph.size();
    vector<int> color(v,0);

    if(!mColoringUtil(graph,m,color,0)){
        cout<<"Solution does not exist"<<endl;
        return false;
    }
    cout<<"Solution exists.The coloring of vertices is:";
    for(int i=0; i<v; ++i)
    cout<<"Vertex"<<i<<":Color"<<color[i]<<endl;
    return true;
}

int main()
{
    vector<vector<int>> graph={
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int m =3;
    mColoring(graph,m);
    return 0;
}
