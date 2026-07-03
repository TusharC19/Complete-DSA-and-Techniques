
# include<bits/stdc++.h>
using namespace std; 
//  Definition for a binary tree node.
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
    bool isbalanced = true;

    int getHeight(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        
        // ise hum har ek node pe height check karne se bachte hai 
        // agar ek bhi node pe aisa ho condittion true
        
        if(isbalanced == true && abs(rh-lh)>1)
        {
            isbalanced = false;
        }

        return max(lh,rh) + 1;
    }


    bool isBalanced(TreeNode* root) {

        getHeight(root);
        return isbalanced;





    }
};

int main(){
    
 return 0;
}