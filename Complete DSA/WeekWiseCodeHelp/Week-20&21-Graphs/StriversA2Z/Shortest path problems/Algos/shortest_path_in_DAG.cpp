# include<bits/stdc++.h>
using namespace std; 

class Solution {
    public:

    void toposort( int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&s){
        int n=vis.size();
        vis[node]=1;

        for(auto&it:adj[node]){
            int v=it.first;
            if(!vis[v]) toposort(v,adj,vis,s);
        }

        // during backtrack
        s.push(node);
    }

    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<vector<pair<int,int>>>adj(N);
        
        // run for no of edges only
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        

        // step1: toposort
        stack<int>s;
        vector<int>vis(N,0);

        for(int i=0;i<N;i++){
            if(!vis[i]){
                toposort(i,adj,vis,s);
            }
        }
        


        //step2: relaxation of edges
        vector<int>dist(N,1e9);
        dist[0]=0;

        while(!s.empty()){
            int node=s.top();
            s.pop();

            for(auto&it:adj[node]){
                int v=it.first;
                int wt=it.second;

                if(dist[node]!=1e9 && dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
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

    int N=4,M=2;
    vector<vector<int>>edges = {{0,1,2},{0,2,1}};
    Solution s;
    auto ans = s.shortestPath(N,M,edges);

    for(int i:ans) cout<<i<<" ";cout<<endl;
    
 return 0;
}