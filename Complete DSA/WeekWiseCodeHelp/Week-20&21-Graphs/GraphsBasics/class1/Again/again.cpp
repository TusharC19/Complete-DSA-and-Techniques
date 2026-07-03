# include<bits/stdc++.h>
using namespace std; 

class Graph{
    public:
        unordered_map<int,list<pair<int,int>>>adjList;

        void addEdge(int u,int v,int w,int direction){
            if(direction==1){
                adjList[u].push_back({v,w});
            }
            else{
                adjList[u].push_back({v,w});
                adjList[v].push_back({u,w});

            }
        }

        void print(int n){
            for(int i=0;i<n;i++){
                cout<<i<<"-> {";
                for(auto&it:adjList[i]){
                    int node = it.first;
                    int w = it.second;
                    cout<<"("<<node<<","<<w<<")";
                }
                cout<<"}"<<endl;

            }
        }


        void bfsHelper(int src,unordered_map<int,bool>&vis){
            
            queue<int>q;
            q.push(src);
            vis[src]=true;

            while(!q.empty()){
                int front = q.front();
                q.pop();
                cout<<front<<" ";
                
                for(auto&it:adjList[front]){
                    int node=it.first;
                    if(!vis[node]){
                        q.push(node);
                        vis[node]=true;
                    }
                        
                }
                    
            }

        }

        void bfs(int n){
            unordered_map<int,bool>vis;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    bfsHelper(i,vis);
                }
            }
        }



        void dfsHelper(int src,unordered_map<int,bool>&vis){
            vis[src] = true;
            cout<<src<<" ";
            
            for(auto&it:adjList[src]){
                int n=it.first;
                if(!vis[n]){
                    dfsHelper(n,vis);
                }
            }
        }

        void dfs(int n,int &cnt){
            unordered_map<int,bool>vis;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    cnt++;
                    dfsHelper(i,vis);
                }
            }
        }

};


int main(){
    Graph g;
    // g.addEdge(0,1,10,0);
    // g.addEdge(0,3,10,0);
    // g.addEdge(1,3,10,0);
    // g.addEdge(1,2,10,0);
    // g.addEdge(3,2,10,0);
    // g.addEdge(2,4,10,0);

    g.addEdge(0,1,10,1);
    g.addEdge(0,3,10,1);
    g.addEdge(1,2,10,1);
    g.addEdge(1,3,10,1);
    g.addEdge(3,2,10,1);
    g.addEdge(2,4,10,1);
    g.addEdge(5,7,10,1);
    g.addEdge(6,8,10,1);
    g.addEdge(6,9,10,1);
    g.addEdge(10,10,10,1);

    
    g.print(11);
    cout<<endl;
    
    int cnt=0;
    g.dfs(11,cnt);
    cout<<endl;
    cout<<cnt<<endl;

 return 0;
}