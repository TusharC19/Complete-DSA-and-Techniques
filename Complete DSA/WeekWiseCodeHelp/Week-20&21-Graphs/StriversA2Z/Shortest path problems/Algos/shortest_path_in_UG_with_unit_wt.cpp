# include<bits/stdc++.h>
using namespace std; 

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<vector<int>>adj(N);
        for(int i=0;i<M;i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>dist(N,1e9);
        dist[0]=0;
        queue<pair<int,int>>q;
        q.push({0,0});

        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();

            for(auto&it:adj[node]){
                if(dist[node]<=1e9 && dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push({it,dist[it]});
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }

        return dist;
    }
};


int main(){ 
    int N=3,M=1;
    vector<vector<int>>edges = {{1,2}};
    Solution s;
    auto ans = s.shortestPath(edges,N,M);

    for(int i:ans) cout<<i<<" ";cout<<endl;
    
 return 0;
}