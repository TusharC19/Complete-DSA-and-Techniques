# include<bits/stdc++.h>
using namespace std; 


class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<int>adj[N];
        for(auto&it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;
        q.push(0);
        vector<int>dist(N,1e9);
        dist[0]=0;

        while(!q.empty()){
            int n=q.front();
            q.pop();

            for(auto&it:adj[n]){
                if(dist[n]+1<dist[it]){
                    dist[it]=dist[n]+1;
                    q.push(it);
                }
            }
        }

        for(int i=0;i<N;i++)
            if(dist[i]==1e9) dist[i]=-1;


        return dist;
    }
};



int main(){
    
 return 0;
}