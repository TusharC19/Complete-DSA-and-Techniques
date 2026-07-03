# include<bits/stdc++.h>
using namespace std; 

class Graph{
public:
    unordered_map<int,list<int>>adjList;
    void print(int src,int nodes){
        for(int i=src;i<nodes;i++){
            cout<<i<<"->"<<"{ ";
            for(auto&it:adjList[i]){
                cout<<it<<" ";
            }
            cout<<"}"<<endl;
        }
    }

    void addEdge(int u,int v,int direction){
        if(direction==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);

        }
        else{
            adjList[u].push_back(v);
        }
    }

    void dfs(int src){
        
    }

};



int main(){
    Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(2,4,0);
    // g.addEdge(3,4,0);
    // g.addEdge(4,5,0);
    // g.addEdge(4,6,0);
    // g.addEdge(7,8,0);
    // g.addEdge(7,9,0);
    // g.addEdge(8,10,0);

    // g.print(0,11);

    // g.bfs(11);

    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);

    // g.print(0,7);

   

    

    
 return 0;
}