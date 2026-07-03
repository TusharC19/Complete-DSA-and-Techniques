# include<bits/stdc++.h>
using namespace std; 

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int result = 0;
        
        //Trying All possible start points (x, y)
        for(int start_row = 0; start_row < m; start_row++) {
            for(int start_col = 0; start_col < n; start_col++) {
                
 
                //Trying All possible ending points (x', y')
                for(int end_row = start_row; end_row < m; end_row++) {
                    for(int end_col = start_col; end_col < n; end_col++) {

                        //Now iterating the start points and end points
                        int sum = 0;
                        for(int i = start_row; i <= end_row; i++) {
                            for(int j = start_col; j <= end_col; j++) {
                                sum += matrix[i][j];
                            }
                        }
                        
                        if(sum == target) {
                            result++;
                        }
                        
                    }
                    
                }
            }
        }
        
        return result;
    }

int main(){
    vector<vector<int>>matrix = {{0,1,0},{1,1,1},{0,1,0}};
    int t = 2;
    int ans = numSubmatrixSumTarget(matrix,t);
    cout<<ans<<endl;

 return 0;
}