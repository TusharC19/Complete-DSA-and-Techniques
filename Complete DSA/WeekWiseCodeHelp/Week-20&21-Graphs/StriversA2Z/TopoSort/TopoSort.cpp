# include<bits/stdc++.h>
using namespace std; 

class Solution{
public:

    void dfs(int src, vector<int> adj[],vector<int>&vis,stack<int>&s){
        vis[src]=1;

        for(auto&it:adj[src]){
            if(!vis[it]){
                dfs(it,adj,vis,s);
            }
        }

        // on backtrck push into stack
        s.push(src);
    }
    vector<int> topoSort1(int V, vector<int> adj[]){
        stack<int>s;

        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,s);
            }
        }

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }


        return ans;
    }


    void bfs(int V,vector<int> adj[],vector<int>&InDegree,vector<int>&ans){

        queue<int>q;
        
        for(int i=0;i<V;i++){
            if(InDegree[i]==0) q.push(i);
        }


        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);

            for(auto&it:adj[front]){
                InDegree[it]--;
                if(InDegree[it]==0) q.push(it);
            }
        }

    }

    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int>InDegree(V,0);

        for(int i=0;i<V;i++){
            for(auto&it:adj[i]){
                InDegree[it]++;
            }
        }

        vector<int>ans;
        bfs(V,adj,InDegree,ans);

        return ans;
    
    
    }






};


int main(){
    
 return 0;
}