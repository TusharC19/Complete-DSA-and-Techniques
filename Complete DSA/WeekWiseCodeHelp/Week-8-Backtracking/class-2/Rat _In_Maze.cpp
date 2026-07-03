# include<bits/stdc++.h>
using namespace std; 


bool isSafe(int nsx,int nsy,int r,int c,vector<vector<bool>>&visited,vector<vector<int>> &mat){
        
        if((nsx>=r && nsy>=c) || (nsx<0 && nsy<0) ){
            return false;
        }
        // block
        if(visited[nsx][nsy] == true){
            return false;
        }
        // empty state
        if(mat[nsx][nsy] == 0){
            return false;
        }
        
        return true;
    }
    
    void solve(vector<vector<int>> &mat,vector<vector<bool>>&visited,int r,int c, vector<string>&ans,string out,int sx,int sy,int dx,int dy){
        
        if(sx == dx && sy == dy){
            ans.push_back(out);
            return ;
        }
        
        // up
        int nsx = sx-1,nsy = sy;
        if(isSafe(nsx,nsy,r,c,visited,mat)){
            visited[nsx][nsy] = true;
            solve(mat,visited,r,c,ans,out+"U",nsx,nsy,dx,dy);
            visited[nsx][nsy] = false;
        }
        
        // down
        nsx = sx+1,nsy = sy;
        if(isSafe(nsx,nsy,r,c,visited,mat)){
            visited[nsx][nsy] = true;
            solve(mat,visited,r,c,ans,out+"D",nsx,nsy,dx,dy);
            visited[nsx][nsy] = false;
        }
        
        // left
        nsx = sx,nsy = sy+1;
        if(isSafe(nsx,nsy,r,c,visited,mat)){
            visited[nsx][nsy] = true;
            solve(mat,visited,r,c,ans,out+"L",nsx,nsy,dx,dy);
            visited[nsx][nsy] = false;
        }
        
        // right
        nsx = sx,nsy = sy-1;
        if(isSafe(nsx,nsy,r,c,visited,mat)){
            visited[nsx][nsy] = true;
            solve(mat,visited,r,c,ans,out+"R",nsx,nsy,dx,dy);
            visited[nsx][nsy] = false;
        }
    }
  
  
  
    vector<string> findPath(vector<vector<int>> &mat) {
        
        int r = mat.size();
        int c = mat[0].size();
        int sx = 0,sy=0,dx=r-1,dy=c-1;
        
        vector<vector<bool>>visited(r,vector<bool>(c,0));
        visited[sx][sy] = true;
        vector<string>ans;
        string out="";
        
        // brute case
        if(mat[0][0]==0) return ans;
        
        solve(mat,visited,r,c,ans,out,sx,sy,dx,dy);
        
        return ans;
    }

int main(){

    vector<vector<int>>mat = {{0,1,1},{1,0,0},{1,0,1}};
    auto ans = findPath(mat);
    for(auto i: ans){
        cout<<i<<endl;
    }


    
 return 0;
}