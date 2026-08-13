# include<bits/stdc++.h>
using namespace std; 

//T.C : O(n^2), The maximum number of cells is n^2 and each cell is visited at most once.
//S.C : O(n^2)
class Solution1 {
public:
    int n;
    
    pair<int, int> getCoord(int s) {
        int row = n-1-(s-1)/n;
        
        int col = (s-1)%n;
        
        if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
            col = n-1-col;
        
        return make_pair(row, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        
        int steps = 0;
        queue<int> que;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        
        que.push(1);
        vector<bool> seen(n*n+1,false);
        
        
        while(!que.empty()) {
            
            int N = que.size();
            while(N--) {
            
                int x = que.front();
                que.pop();

                if(x == n*n)
                    return steps;

                for(int k = 1; k<=6; k++) {
                    if(x+k > n*n)
                        break;

                    pair<int, int> coord = getCoord(x+k);
                    int r = coord.first;
                    int c = coord.second;
                    if(visited[r][c] == true)
                        continue;

                    visited[r][c] = true;
                    if(board[r][c] == -1)
                        que.push(k+x);
                    else {
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};


class Solution {
public:

   pair<int,int> coordinates(int num, int n, int m) {
        // How many rows up from the bottom (divide by total columns 'm')
        int rfb = (num - 1) / m;
        
        // Convert to standard matrix row (Row From Top)
        int rft = (n - 1) - rfb;

        // Default column from left to right
        int col = (num - 1) % m;

        // Flip the column based on parity of grid height and current row
        if((n % 2 == 0 && rft % 2 == 0) || (n & 1 && rft & 1)){
            col = (m - 1) - col;
        }

        return {rft, col};
    }

    int snakesAndLadders(vector<vector<int>>& b) {
        int n=b.size(),m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;
        q.push({1,0});
        vis[n-1][0]=1;

        // int steps=0;
        while(!q.empty()){
            auto qfront=q.front();
            int front=qfront.first;
            int steps=qfront.second;
            q.pop();

            if(front==n*m) return steps;

            for(int i=1;i<=6;i++){
                int val=front+i;

                if(val>n*m) break;

                pair<int,int>p=coordinates(val,n,m);
                int r=p.first,c=p.second;
                
                // Already visited
                if(vis[r][c]==1) continue;
                // if not mark visited
                vis[r][c]=1;

                // PUSH val of snake or ladder 
                if(b[r][c]!=-1){
                    q.push({b[r][c],steps+1});
                    // continue;
                    
                }
                // PUSH: normal value
                else{
                    q.push({val,steps+1});
                    // vis[r][c]=1;
                }
            }

        }

        // while ends not return anything
        return -1;
        

    }


};




int main(){
    
 return 0;
}