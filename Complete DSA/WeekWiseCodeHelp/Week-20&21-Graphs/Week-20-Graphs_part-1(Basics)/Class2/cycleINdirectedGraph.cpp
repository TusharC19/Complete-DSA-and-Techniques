# include<bits/stdc++.h>
using namespace std; 

class Graph
{
public:
    unordered_map<int,list<pair<int,int>>>adjList;
    void addedge(int u,int v,int w,bool direction){
        if(direction == 0){
            // un-directed graph
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w}); 
        }
        else{
            adjList[u].push_back({v,w});
        }
    }
    
    
    void printGp(int&n){
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<"{ ";
            list<pair<int,int>>p = adjList[i];
            for(auto&it:p){
                cout<<"("<<it.first<<","<<it.second<<") ";
            }
            cout<<" }";
            cout<<endl;
        }

    }

    // for un-directed graph
    // code considerring dis-connected components are present using bfs
    bool cycleDetectionbfs(int src,unordered_map<int,bool>&vis){
        queue<int>q;
        
        unordered_map<int,int>parent;

        q.push(src);
        vis[src] = true;
        parent[src] = -1;


        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto&it:adjList[front]){
                int node = it.first;
                int w = it.second;

                if(!vis[node]){
                    q.push(node);
                    vis[node] = true; /// else if since yha pe visited true mark kar diya
                    parent[node] = front;
                    
                }
                else if(vis[node]==true && node != parent[front]){
                    return true;
                }
            }
        }
        return false;
        
    }

    // Cycle detection in UN-DIRECTED Graph using dfs
    bool cycleDetectiondfs(int src,unordered_map<int,bool>&vis,int parent){
        vis[src] = true;
        for(auto&it:adjList[src]){
            int node = it.first;
            if(!vis[node]){
                bool ans = cycleDetectiondfs(node,vis,src);
                if(ans==true){
                    return true;
                }
            }
            else if(vis[node]==true && parent != node){
                return true;
            }
            
        }
        return false;
    }


    // for directed graph using dfs
    bool checkCycleDFS(){
        
    }

};

int main(){
    Graph g;
    
    int n = 6;
    g.addedge(0, 1, 10,0);
    g.addedge(1, 2, 10,0);
    g.addedge(1, 5, 10,0);
    g.addedge(2, 3, 10,0);
    g.addedge(2, 5, 10,0);
    g.addedge(3, 4, 10,0);

    bool ans = false;
    
    
    return 0;
}