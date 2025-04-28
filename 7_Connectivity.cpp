#include<iostream>
#include<vector>
using namespace std;

void AddEdge(int u, int v, vector<vector<int>> &adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<vector<int>> &adj, vector<bool> &visited, int start)
{
    visited[start] = true;
    for(auto i:adj[start])
    {
        if(visited[i] == false)
        {
            DFS(adj, visited, i);
        }
    }
}

void PrintAdj(vector<vector<int>> adj)
{
    int k = 0;
    for(auto i:adj)
    {
        cout<<k++<<" -> ";
        for(auto j:i)
        {
            cout<<j<<", ";
        }
        cout<<endl;
    }
}

int main()
{
    int v = 4;
    vector<vector<int>> adj(v);
    vector<bool> visited(v, false);
    AddEdge(0, 1, adj);
    AddEdge(1, 2, adj);
    AddEdge(2, 0, adj);
    DFS(adj, visited, 0);

    // PrintAdj(adj);

    for(auto i:visited)
    {
        if(i == false)
        {
            cout<<i<<endl;
            cout<<"Graph is not connected"<<endl;
            return 0;
        }
    }
    cout<<"Graph is connected"<<endl;
    return 0;
}