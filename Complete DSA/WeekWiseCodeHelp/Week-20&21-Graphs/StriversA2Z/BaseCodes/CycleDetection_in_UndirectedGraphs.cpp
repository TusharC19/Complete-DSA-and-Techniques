#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfsHelper(int src, vector<int> &vis, vector<int> adj[])
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int parent = front.second;

            for (auto &it : adj[node])
            {
                if (vis[it] == 1)
                {
                    if (parent == it)
                        continue;
                    else
                        return true;
                }
                else
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
            }
        }

        return false;
    }

    bool bfs(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                // for first subgraph compoent if any covered in this
                bool ans = bfsHelper(i, vis, adj);

                if (ans == true)
                    return true;
            }
        }

        return false;
    }

    bool dfsHelper(int src, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[src] = 1;

        // bool ans=false;

        for (auto &it : adj[src])
        {
            if (vis[it] == 1)
            {
                if (it == parent)
                    continue;
                else
                    return true;
            }
            else
            {
                bool ans = dfsHelper(it, src, vis, adj);
                // agar ek bhi branch me cycle mila return true;
                if (ans == true)
                    return true;
            }
        }

        return false;
    }

    bool dfs(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        int parent = -1;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                // for first subgraph compoent if any covered in this
                bool ans = dfsHelper(i, parent, vis, adj);

                if (ans == true)
                    return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        auto usingbfs = bfs(V, adj);
        auto usingdfs = dfs(V, adj);

        return usingbfs;
    }
};

int main()
{

    return 0;
}