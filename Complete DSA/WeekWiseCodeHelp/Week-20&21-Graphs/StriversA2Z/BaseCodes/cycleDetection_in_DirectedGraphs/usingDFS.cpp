# include<bits/stdc++.h>
using namespace std; 


class Solution{
public:


    bool dfs(int src,vector<int> adj[],vector<int>&vis,vector<int>&pathvis){
        // if(vis[it] && pathvis[it]) return true;
        vis[src]=1;
        pathvis[src]=1;

        for(auto&it:adj[src]){
            if(vis[it] && pathvis[it]) return true;
                
            else if(!vis[it]){
                bool ans=dfs(it,adj,vis,pathvis);
                if(ans) return true;
            }
        }

        // on return make sure pahtvis in undone
        pathvis[src]=0;
        return false;
        
    }
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int>vis(n+1,0),pathvis(n+1,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)) return true;
            }
        }

        return false;
    }

    // Submission Verdict: Accepted
    // T.C = O(V+E)
};


int main(){
    
 return 0;
}