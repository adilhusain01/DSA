#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    // For adjescency list
    unordered_map<int, list<int>> adj;

    // Making an edge
    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        adj[u].push_back(v);

        // if the graph is undirected
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m;
    cout << "Enter the no of edges : ";
    cin >> m;

    int n;
    cout << "Enter the no of nodes : ";
    cin >> n;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // making undirected graph
        g.addEdge(u, v, 0);
    }

    g.printGraph();

    return 0;
}