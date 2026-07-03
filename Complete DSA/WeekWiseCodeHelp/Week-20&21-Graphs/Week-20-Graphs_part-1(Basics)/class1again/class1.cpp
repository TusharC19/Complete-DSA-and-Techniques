#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList1;
    void addedge1(int u, int v, bool direction)
    {
        if (direction == 0)
        {
            // un-directed graph
            adjList1[u].push_back(v);
            adjList1[v].push_back(u);
        }
        else
        {   
            // di-rected graph
            adjList1[u].push_back(v);
        }
    }

    // void printG1(){
    //     for(auto&it:adjList){
    //         cout<<it.first<<"->"<<"{ ";
    //         for(int&i:it.second){
    //             cout<<i<<",";
    //         }
    //         cout<<" }";
    //         cout<<endl;
    //     }
    // }

    // void printG2(int &n)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << i << "->" << "{ ";
    //         list<int> temp = adjList1[i];
    //         for (int &j : temp)
    //         {
    //             cout << j << ",";
    //         }
    //         cout << " }";
    //         cout << endl;
    //     }
    // }

    unordered_map<int,list<pair<int,int>>>adjList2;
    void addedge2(int u,int v,int w,bool direction){
        if(direction == 0){
            // un-directed graph
            adjList2[u].push_back({v,w});
            adjList2[v].push_back({u,w});
        }
        else{
            adjList2[u].push_back({v,w});
        }
    }

    void printGw(int&n){
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<"{ ";
            list<pair<int,int>>p = adjList2[i];
            for(auto&it:p){
                cout<<"("<<it.first<<","<<it.second<<") ";
            }
            cout<<" }";
            cout<<endl;
        }
    }

    void bfswithoutWeight(int src)
    {
        queue<int> q;
        unordered_map<int,bool>vis;
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            int front = q.front();
            cout<<front<<"->";
            q.pop();
            
                list<int> temp = adjList1[front];
                for(auto&it:temp){
                    if(vis[it]!=true){
                        q.push(it);
                        vis[it] = true;
                    }
                    
                }
            
        }
    }

    
    void bfswHelper(int src,unordered_map<int,bool>&vis){
        queue<int>q;
        q.push(src);
        vis[src] = true;
        
        while(!q.empty()){
            int front = q.front();
            cout<<front<<"->";
            q.pop();

            for(auto&it : adjList2[front]){
                int node = it.first;
                int w = it.second;

                if(!vis[node]){
                    vis[node] = true;
                    q.push(node);
                }
            }
            
                
        }
    }
    void bfsw(int&n){
        // har ek node ko src man liya
        unordered_map<int,bool>vis;
        for(int src=0;src<n;src++){
            if(!vis[src]){
                bfswHelper(src,vis);
            }           
              
        }
    }

    // dfs code
    void dfsHelper(int&node,unordered_map<int,bool>&vis){
        // jaise hi mila node   
        vis[node] = true;
        cout<<node<<"->";
        // base case
        if(adjList2[node].empty()) return;

        for(auto&it:adjList2[node]){
            int node = it.first;
            int weight = it.second;
            if(!vis[node]){
                dfsHelper(node,vis);
            }
            
        }

    }

    void dfs(int&n){
        // har ek node ko src man liya
        unordered_map<int,bool>vis;
        for(int src=0;src<14;src++){
            if(!vis[src]){
                dfsHelper(src,vis);
            }
            
              
        }
    }


};

int main()
{
    Graph g;
    // int n = 7;
    // g.addedge1(0, 3, 1);
    // g.addedge1(0, 5, 1);
    // g.addedge1(0, 2, 1);
    // g.addedge1(3, 5, 1);
    // g.addedge1(2, 5, 1);
    // g.addedge1(5, 4, 1);
    // g.addedge1(5, 6, 1);
    // g.addedge1(4, 1, 1);
    // g.addedge1(6, 1, 1);


    // For bfs
    g.addedge2(0, 3, 10,1);
    g.addedge2(0, 5, 10,1);
    g.addedge2(0, 2, 10,1);
    g.addedge2(3, 5, 10,1);
    g.addedge2(2, 5, 10,1);
    g.addedge2(5, 4, 10,1);
    g.addedge2(5, 6, 10,1);
    g.addedge2(4, 1, 10,1);
    g.addedge2(6, 1, 10,1);
    g.addedge2(9, 7, 10,1);
    g.addedge2(9, 8, 10,1);
    g.addedge2(10, 11, 10,1);


    // Graph3 for dfs
    // g.addedge2(0, 1, 10,1);
    // g.addedge2(0, 2, 10,1);
    // g.addedge2(1, 5, 10,1);
    // g.addedge2(2, 3, 10,1);
    // g.addedge2(3, 4, 10,1);
    // g.addedge2(5, 4, 10,1);
    // g.addedge2(4, 6, 10,1);
    // g.addedge2(4, 8, 10,1);
    // g.addedge2(8, 7, 10,1);
    // g.addedge2(9, 10, 10,1);
    // g.addedge2(10, 11, 10,1);
    // g.addedge2(10, 12, 10,1);
    // g.addedge2(13, 14, 10,1);
    

    // g.printG1();
    // g.printGw(n);
    // g.bfs(0);
    // g.bfs(0);
    int n = 12;
    g.printGw(n);

    // g.dfs(n);
    // cout<<endl;
    g.bfsw(n);



    // Remember this concept that map is empty all the way ago
    // unordered_map<int,bool>mp;
    // for(auto&it:mp){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }

    return 0;
}