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
    int maxdia = 0;

    int getHeight(TreeNode* root) {
        if(root == NULL ) {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
       
        // har ek node pe jake check kar rha hu
        int currD = left + right;
        maxdia = max(maxdia,currD  );

        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);

        return maxdia;
    }
};




int main(){
    
 return 0;
}