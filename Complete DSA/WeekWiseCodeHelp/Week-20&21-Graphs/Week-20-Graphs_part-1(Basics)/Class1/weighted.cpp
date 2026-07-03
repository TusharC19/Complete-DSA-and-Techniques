#include <bits/stdc++.h>
using namespace std;

class Graph {
    public: 
    unordered_map < int,list < pair<int,int>> > adjList;

    void addEdge(int u, int v,int weight, bool direction) {
        //direction = 0 -> undirected graph
        //direction = 1 => directed graph
        if (direction == 0) {
            adjList[u].push_back({v,weight});  // pair insert
            adjList[v].push_back({u,weight});
        }
        else {
            //directed edge
            adjList[u].push_back({v,weight});
        }
    }
    
    void printAdjList(int n) {

        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            cout << "{ ";
            list < pair<int,int >> temp = adjList[i];
            for (auto j: temp) {
                cout << "("<<j.first <<","<<j.second<<" )";
            }
            cout << "}" << endl;
        }
        /*  0: { 1, 2, }
            1: { 2, }
            2: { 3, }
            3: { }
        */

        // not include 3
        //   for(auto i: adjList) {
        //     cout << i.first << ": ";
        //     cout << " {";
        //     for(auto j: i.second) {
        //       cout << j <<", ";
        //     }
        //     cout << "}" << endl;
        //   }

    }

};

int main() {
    Graph g;
    g.addEdge(0, 1, 3,1);
    g.addEdge(0, 2, 4,1);
    g.addEdge(1, 2, 8,1);
    g.addEdge(2, 3, 16,1);
    int n = 4;
    g.printAdjList(n);

    return 0;
}