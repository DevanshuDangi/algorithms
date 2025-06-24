// Implementation of Hierholzer's algorithm in c++
//for directed graph
#include <bits/stdc++.h>
using namespace std;

void printfinalPath(vector< vector<int> > adj)
{
    // creating a map to count and modify
    // the edges which are unused
    map<int,int> edges;

    for (int i=0; i<adj.size(); i++)
    {
        // assigning no. of edges to each node
        edges[i] = adj[i].size();
    }

    if (!adj.size())
        return; //empty graph

    // creating the tempPath and finalPath
    stack<int> tempPath;
    vector<int> finalPath;

    // start from any vertex
    tempPath.push(0);
    int v = 0; // Current vertex

    // we will iterate till we visit all the edges
    while (!tempPath.empty())
    {
        // If there's a remaining edge adjacent to v
        if (edges[v])
        {
            // make nxt any unvisited node adjacent to v 
            // mark it as visited
            tempPath.push(v);
            int nxt = adj[v].back();
            edges[v]--;
            adj[v].pop_back();

            // Move to the next vertex
            v = nxt;
        }

        // back-tracking to find the remaining finalPath
        else{
            finalPath.push_back(v);
            v = tempPath.top();
            tempPath.pop();
        }
    }

    // we will print in reverse the finalPath 
    // vector to get our eulerian path
    for (int i=finalPath.size()-1; i>=0; i--){
        cout << finalPath[i];
        if (i)
        cout<<" -> ";
    }
}

int main()
{
    vector< vector<int> > adj;

    adj.resize(6);
    adj[0].push_back(3);
    adj[3].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(5);
    adj[5].push_back(2);
    printfinalPath(adj);

    return 0;
}