#include <bits/stdc++.h>
using namespace std;

// Using Priority Queue
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<pair<int, int>> adj[V];
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int w = i[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({src, 0});

    vector<int> dis(V, 1e9);
    dis[src] = 0;

    while (!pq.empty())
    {
        int node = pq.top().first;
        int dist = pq.top().second;

        pq.pop();

        for (auto i : adj[node])
        {
            int n = i.first;
            int w = i.second;

            if (dis[node] + w < dis[n])
            {
                dis[n] = dis[node] + w;
                pq.push({n, dis[n]});
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dis[i] == 1e9)
            dis[i] = -1;
    }

    // for(int i:dis) cout<<i<<" ";cout<<endl;

    return dis;
}

// Using Set
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<pair<int, int>> adj[V];
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int w = i[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    set<pair<int, int>> s;
    s.insert({src, 0});

    vector<int> dis(V, 1e9);
    dis[src] = 0;

    while (!s.empty())
    {
        int node = s.begin()->first; // since iterator so use arrow pointer
        int wt = s.begin()->second;
        s.erase(s.begin());

        for (auto i : adj[node])
        {
            int n = i.first;
            int w = i.second;

            if (dis[node] + w < dis[n])
            {
                s.erase({node, wt});
                s.insert({n, w});
                dis[n] = dis[node] + w;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dis[i] == 1e9)
            dis[i] = -1;
    }

    // for (int i : dis)
    //     cout << i << " ";
    // cout << endl;

    return dis;
}
int main()
{

    return 0;
}


/*
class cmp {
   public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        // For a min-heap (smallest distance at top), you need:
        return a.first > b.first;
    }
};

class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        vector<vector<pair<int, int>>> adj(V);
        // vector<pair<int,int>>adj[V];

        int n = edges.size();
        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dis + wt < dist[v]) {
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};

*/