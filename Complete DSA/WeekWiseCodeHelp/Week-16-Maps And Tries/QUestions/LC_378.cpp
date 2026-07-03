// 378: Kth Smallest Element in a Sorted Matrix

class Solution {
    public:
        int checkCount(vector<vector<int>>& matrix,int mid){
            int n = matrix.size();
            int count = 0;
            for(int i=0;i<n;i++){
                int r = matrix[i].size();
            }
            return count;
        }
    
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int n = matrix.size();
           
            int left = matrix[0][0], right = matrix[n-1][n-1],mid;
            int ans = -1;
            while(left<=right){
                mid = left + (right-left)/2; // avoid overflow
    
                int count = checkCount(matrix,mid);
                if(count>=k){
                    ans = mid; // ans mid ho sakta hai
                    // dec right pointer
                    right = mid -1;
                }
                else{
                    // count>=k
                    left = mid+1;
                }
            
            }
    
            return ans;
        }
    };