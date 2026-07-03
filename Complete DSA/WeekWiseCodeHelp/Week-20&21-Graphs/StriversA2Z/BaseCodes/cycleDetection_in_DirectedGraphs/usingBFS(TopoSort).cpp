# include<bits/stdc++.h>
using namespace std; 

class Solution{
    public:
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
                // if(InDegree[it]==-1) return true; // i.e cycle presenthence not a DAG
                if(InDegree[it]==0) q.push(it);
            }
        }

        // return false;

    }

    bool topoSort(int V, vector<int> adj[]){
        vector<int>InDegree(V,0);

        for(int i=0;i<V;i++){
            for(auto&it:adj[i]){
                InDegree[it]++;
            }
        }

        vector<int>ans;
        bfs(V,adj,InDegree,ans);

        int cnt=0;
        if(ans.size()==V) return false;
        return true;
    
    
    }
};

int main(){
    
 return 0;
}