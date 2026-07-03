#include <bits/stdc++.h>

using namespace std;

class Graph {
    public: unordered_map < int,
    list < pair < int,
    int >> > adjList;

    void addEdge(int u, int v, int weight, bool direction) {
        //direction = 0 -> undirected graph
        //direction = 1 => directed graph
        if (direction == 0) {
            adjList[u].push_back({
                v,
                weight
            }); // pair insert
            adjList[v].push_back({
                u,
                weight
            });
        }
        else {
            //directed edge
            adjList[u].push_back({
                v,
                weight
            });
        }
    }

    void printAdjList(int n) {

        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            cout << "{ ";
            list < pair < int, int >> temp = adjList[i];
            for (auto & j: temp) {
                cout << "(" << j.first << "," << j.second << " )";
            }
            cout << "}" << endl;
        }
        // not include 3 as null vertex
        //   for(auto i: adjList) {
        //     cout << i.first << ": ";
        //     cout << " {";
        //     for(auto j: i.second) {
        //       cout << j <<", ";
        //     }
        //     cout << "}" << endl;
        //   }

    }

    void bfsTraversal(int src) {
        queue < int > q;
        unordered_map < int, bool > visited;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int front = q.front();
            cout << front << " ";
            q.pop();

            // now go to its neighbour
            for (auto & neighbour: adjList[front]) {
                int node = neighbour.first;
                if (visited[node] != true) {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }

    }
    
    
    void dfsTraversal(int src){
        
    }

};

int main() {
    Graph g;
    // g.addEdge(0, 1, 3,1);
    // g.addEdge(0, 2, 4,1);
    // g.addEdge(1, 2, 8,1);
    // g.addEdge(2, 3, 16,1);

    g.addEdge(0, 3, 1, 1);
    g.addEdge(0, 5, 1, 1);
    g.addEdge(0, 2, 1, 1);
    g.addEdge(3, 5, 1, 1);
    g.addEdge(2, 5, 1, 1);
    g.addEdge(5, 4, 1, 1);
    g.addEdge(5, 6, 1, 1);
    g.addEdge(4, 1, 1, 1);
    g.addEdge(6, 1, 1, 1);


    int n = 4;

    g.printAdjList(n);
    g.bfsTraversal(0);

    return 0;
}