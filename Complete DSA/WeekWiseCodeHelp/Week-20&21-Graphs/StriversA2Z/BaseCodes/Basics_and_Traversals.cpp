#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int N, E;
    // unordered_map<int,list<int>>mp;
    // vector<int>adjList[]; wrong
    vector<vector<int>> adjList;

    Graph(int N, int E)
    {
        this->N = N;
        this->E = E;
        adjList.resize(N);
    }

    void insertNode(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print(Graph &g, int spt)
    {
        for (int i = spt; i < N; i++)
        {
            cout << i << "->" << "(" << " ";
            for (auto &it : adjList[i])
            {
                cout << it << ",";
            }
            cout << ")" << endl;
        }
    }
};

void dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans, int src)
{
    if (vis[src] == 1)
        return;

    vis[src] = 1;
    ans.push_back(src);

    for (auto &it : adj[src])
    {
        dfs(adj, vis, ans, it);
    }

    return;
}
vector<int> dfsOfGraph(int V, vector<vector<int>> edges)
{
    vector<vector<int>> adj(V + 1);
    for (auto &it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V + 1, 0), ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, ans, i);
        }
    }

    return ans;
}

void bfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans, int src)
{
    deque<int> q;
    q.push_back(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop_front();
        ans.push_back(front);

        for (auto &it : adj[front])
        {
            if (!vis[it])
            {
                q.push_back(it);
                vis[it] = 1;
            }
        }
    }
}

vector<int> bfsOfGraph(int V, vector<vector<int>> edges)
{
    vector<vector<int>> adj(V + 1);
    for (auto &it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V + 1, 0), ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            bfs(adj, vis, ans, i);
        }
    }

    return ans;
}

int main()
{

    return 0;
}