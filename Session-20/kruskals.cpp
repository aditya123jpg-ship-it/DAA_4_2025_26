#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> sizee;

int findParent(int node)
{
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void unionBySize(int u, int v)
{
    int pu = findParent(u);
    int pv = findParent(v);

    if(pu == pv)
        return;

    if(sizee[pu] < sizee[pv])
    {
        parent[pu] = pv;
        sizee[pv] += sizee[pu];
    }
    else
    {
        parent[pv] = pu;
        sizee[pu] += sizee[pv];
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    parent.resize(V);
    sizee.resize(V, 1);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0;

    for(int i = 0; i < E; i++)
    {
        int w = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];

        if(findParent(u) != findParent(v))
        {
            cost += w;
            unionBySize(u, v);
        }
    }

    cout << cost;

    return 0;
}