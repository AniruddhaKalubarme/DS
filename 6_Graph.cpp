#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void addEdge(int u, int v, vector<vector<int>> &adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<vector<int>> adj, vector<bool> &visited, int start)
{
    cout<<start<<" -> ";
    visited[start] = true;
    for(auto j:adj[start])
    {
        if(visited[j] == false)
        {
            DFS(adj, visited, j);
        }
    }
}

void BFS(vector<vector<int>> adj, vector<bool> visited, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty())
    {
        int data = q.front();
        q.pop();
        cout<<data<<" -> ";
        
        for(auto i:adj[data])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int vertex = 3;
    vector<vector<int>> adj(vertex);
    vector<bool> visited(vertex, false);
    addEdge(0,1, adj);
    addEdge(0,2, adj);
    addEdge(1,2, adj);
    
    DFS(adj, visited, 0);
    fill(visited.begin(), visited.end(), false); 
    cout<<endl;
    BFS(adj, visited, 0);
    
    
    return 0;
}