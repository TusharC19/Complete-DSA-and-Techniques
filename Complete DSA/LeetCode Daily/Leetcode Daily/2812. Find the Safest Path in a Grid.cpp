#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. Multi-source BFS
    // Instead of running BFS from each thief separately, run one BFS from all thief cells at once:
    void bfs(vector<vector<int>> &g, vector<vector<int>> &dist)
    {
        int n = g.size(), m = g[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto front = q.front();
            int r = front.first, c = front.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    if (dist[nr][nc] >= dist[r][c])
                    {
                        dist[nr][nc] = dist[nr][nc] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    bool dfs(int r, int c, int d, vector<vector<int>> &g, vector<vector<int>> &vis, vector<vector<int>> &dist)
    {
        int n = g.size(), m = g[0].size();

        vis[r][c] = 1;

        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if (!vis[nr][nc] && dfs(nr, nc, d, g, vis, dist))
                    return true;
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>> &g)
    {
        int n = g.size(), m = g[0].size();
        if (g[0][0] == 1 || g[n - 1][m - 1] == 1)
            return 0;

        // create dist arr
        vector<vector<int>> dist(n, vector<int>(m, 1000));

        bfs(g, dist);

        int maxdist = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxdist = max(maxdist, dist[i][j]);
            }
        }

        int s = 0, e = maxdist, ans = 0;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            if (dist[0][0] >= mid && dfs(0, 0, mid, g, dist, vis))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}