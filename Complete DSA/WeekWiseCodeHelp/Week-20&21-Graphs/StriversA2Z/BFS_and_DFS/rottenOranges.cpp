# include<bits/stdc++.h>
using namespace std; 


    int bfs(vector<vector<int>>& grid,queue<tuple<int,int,int>>&q){
        int tmax=0;
        vector<pair<int,int>>v = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto[row,col,time] = q.front();
            q.pop();
            tmax = max(time,tmax);

            for(auto[r,c]:v){
                int nr=row+r,nc=col+c;
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                    q.push({nr,nc,time+1});
                    grid[nr][nc]=2;
                }
            
            }
        }

        return tmax;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                
                }
            }
        }
        // BFS algo
        int ans = bfs(grid,q);

        // check if fresh orange still in grid or not
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                
                }
            }
        }


        return ans;   
    }


int main(){
    
 return 0;
}