# include<bits/stdc++.h>
using namespace std; 

class Graph{
public:
    // unordered_map<int,list<int>>adjList;

    // void print(int src,int nodes){
    //     for(int i=src;i<nodes;i++){
    //         cout<<i<<"->"<<"{ ";
    //         for(auto&it:adjList[i]){
    //             cout<<it<<" ";
    //         }
    //         cout<<"}"<<endl;
    //     }
    // }

    // void addEdge(int u,int v,int direction){
    //     if(direction==0){
    //         adjList[u].push_back(v);
    //         adjList[v].push_back(u);

    //     }
    //     else{
    //         adjList[u].push_back(v);
    //     }
    // }

    unordered_map<int,list<pair<int,int>>>adjList;

    void print(int src,int nodes){
        for(int i=src;i<nodes;i++){
            cout<<i<<"->"<<"{ ";
            for(auto&it:adjList[i]){
                cout<<"("<<it.first<<","<<it.second<<")"<<" ";
            }
            cout<<"}"<<endl;
        }
    }

    void addEdge(int u,int v,int w,int direction){
        if(direction==0){
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});

        }
        else{
            adjList[u].push_back({v,w});
        }
    }





};


int main(){
    Graph g;
    // g.addEdge(0,1,10,0);
    // g.addEdge(1,2,10,0);
    // g.addEdge(1,3,10,0);
    // g.addEdge(2,4,10,0);
    // g.addEdge(3,4,10,0);
    // g.addEdge(4,5,10,0);
    // g.addEdge(4,6,10,0);
    // g.print(1,6);

    g.addEdge(0,1,10,1);
    g.addEdge(0,2,10,1);
    g.addEdge(1,4,10,1);
    g.addEdge(2,3,10,1);
    g.addEdge(3,5,10,1);
    
    g.print(0,6);


    


    
 return 0;
}