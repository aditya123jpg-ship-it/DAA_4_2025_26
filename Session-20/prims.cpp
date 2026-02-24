#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<bool> inMST(V, false);

    int cost = 0;

    pq.push({0, 0});

    while(!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(inMST[node])
            continue;

        inMST[node] = true;
        cost += wt;

        for(int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i].first;
            int weight = adj[node][i].second;

            if(!inMST[neighbour])
            {
                pq.push({weight, neighbour});
            }
        }
    }

    cout << cost;

    return 0;
}