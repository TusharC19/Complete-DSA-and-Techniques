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

    // code considerring components are present
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

};

int main(){
    Graph g;
    // int n = 7;
    // g.addedge(0, 1, 10,0);
    // g.addedge(1, 2, 10,0);
    // g.addedge(2, 5, 10,0);
    // g.addedge(5, 4, 10,0);
    // g.addedge(5, 6, 10,0);
    // g.addedge(4, 3, 10,0);
    // g.addedge(4, 6, 10,0);


    // int n = 6;
    // g.addedge(0, 1, 10,0);
    // g.addedge(1, 2, 10,0);
    // g.addedge(2, 3, 10,0);
    // g.addedge(2, 5, 10,0);
    // g.addedge(3, 4, 10,0);


    
    int n = 6;
    g.addedge(0, 1, 10,0);
    g.addedge(1, 2, 10,0);
    g.addedge(1, 5, 10,0);
    g.addedge(2, 3, 10,0);
    g.addedge(2, 5, 10,0);
    g.addedge(3, 4, 10,0);

    // UN-Directed Graph
    // g.printGp(n);
    bool ans = false;
    // check each node as a src
    // int parent = -1; // for dfs since parent is changing each time so need of map
    // unordered_map<int,bool>vis;
    // for(int i=0;i<n;i++){
    //     if(!vis[i]){
    //         ans = g.cycleDetectiondfs(i,vis,parent);
    //     }
    //     if(ans == true){
    //         break;
    //     }
    // }

    // if(ans) cout<<"present"<<endl;
    // else cout<<"not present"<<endl;


    // making adjList from vector<vector<int>>matrix; i.e matrix representation
    //Input: 
    int Vertices = 4;
    vector<vector<int>>edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};
    int n = edges.size();
        unordered_map<int,list<int>>adjList;
        for(auto&it:edges){
            int node = it[0];
            int ngh = it[1];
            adjList[node].push_back(ngh);
        }


        
    
    return 0;
}