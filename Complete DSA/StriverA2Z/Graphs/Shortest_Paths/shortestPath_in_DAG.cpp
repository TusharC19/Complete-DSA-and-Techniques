# include<bits/stdc++.h>
using namespace std; 


class Solution {
    public:
    void dfs(int src,vector<vector<pair<int,int>>>&adj,stack<int>&s,vector<int>&vis){
        vis[src]=1;

        for(auto&it:adj[src]){
            int nbr=it.first,wt=it.second;
            if(!vis[nbr]){
                dfs(nbr,adj,s,vis);
            }
           
        }

        s.push(src);


    }
    stack<int> toposort(int N,int M,vector<vector<pair<int,int>>>&adj){

        stack<int>s;
        vector<int>vis(N,0);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,adj,s,vis);
            }
        }

        return s;
    }

    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<vector<pair<int,int>>>adj(N);
        for(auto&it:edges){
            int u=it[0],v=it[1],wt=it[2];
            adj[u].push_back({v,wt});
        }

        
        stack<int>s = toposort(N,M,adj);



        vector<int>dist(N,1e9);
        dist[0]=0;

        while(!s.empty()){
            int n=s.top();
            s.pop();

            int d=dist[n];

            for(auto&it:adj[n]){
                int v=it.first;
                int wt=it.second;

                if(d+wt<dist[v]){
                    dist[v]=d+wt;
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