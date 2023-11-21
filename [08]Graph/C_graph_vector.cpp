#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    vector<vector<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u]
    }
};

int main()
{
    int m, n;
    cout << "Enter the no. of edges : ";
    cin >> m;

    cout << "Enter the no. of nodes : ";
    cin >> n;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
}