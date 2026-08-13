# include<bits/stdc++.h>
using namespace std; 
#define P pair<int,int>

// typedef pair<int,int> P;


class cmp{
    public:
    bool operator()(P&a,P&b){
        if(a.first==b.first) return a.second>b.second;
        return a.first>b.first;
    }
};

vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {
    vector<vector<P>> adj(V);
    for(auto &e : edges){
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected
    }

    vector<int> dist(V, 1e9);
    dist[S] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, S});

    while(!pq.empty()){
        auto top = pq.top();
        int d=top.first,v=top.second;
        pq.pop();

        if(d > dist[v]) continue;

        for(auto &edge : adj[v]){
            int u = edge.first, wt = edge.second;
            if(dist[v] + wt < dist[u]){
                dist[u] = dist[v] + wt;
                pq.push({dist[u], u});
            }
        }
    }

    for(int i = 0; i < V; i++)
        if(dist[i] == 1e9) dist[i] = -1;

    return dist;
}

int main(){
    
 return 0;
}