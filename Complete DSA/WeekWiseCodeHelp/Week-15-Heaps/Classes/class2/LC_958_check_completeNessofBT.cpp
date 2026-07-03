# include<bits/stdc++.h>
using namespace std; 

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    public:
        bool solve(TreeNode* root){
            queue<TreeNode*>q;
            q.push(root);
            bool flagofNull = false;
    
            while(!q.empty()){
                TreeNode* front = q.front();
                q.pop();
    
    
                if(front==NULL) flagofNull = true;
    
                // if front is not null
                else{
                    // null ke baad ek number mil rha hai
                    // if after null we get flag = true and front != NULL 
                    // then it is not cbt 
                    if(flagofNull == true) return false;
    
                    else{
                        // push kra do node childs
                        // if(front->left) q.push(front->left);
                        // if(front->right) q.push(front->right);
                        q.push(front->left);
                        q.push(front->right);
    
                    }
                }
    
            }
            // yha tak pura aa gya
            return true;
        }
    
        bool isCompleteTree(TreeNode* root) {
            if(root== NULL) return true;
            return solve(root);
        }
    };


int main(){
    
    
    
    return 0;
}