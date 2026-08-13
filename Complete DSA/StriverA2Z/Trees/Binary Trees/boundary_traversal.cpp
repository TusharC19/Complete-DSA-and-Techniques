#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };
 
class Solution {
   public:
    void leftboundary(TreeNode *root, vector<int> &ans) {
        // since root already taken
       TreeNode* cur=root->left;
       while(cur){
            if(!isleaf(cur)) ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            // if left not eexits
            else cur=cur->right;
       }
    }

    void leafnodes(TreeNode *root, vector<int> &ans) {
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        if(root->left) leafnodes(root->left,ans);
        if(root->right) leafnodes(root->right,ans);
        
    }

    void rightReverseBoundary(TreeNode *root, vector<int> &ans) {
        TreeNode* cur=root->right;
        stack<int>s;
        while(cur){
            if(!isleaf(cur)) s.push(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
       
    }

    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }

    vector <int> boundary(TreeNode* root){
    	//your code goes here
        if (!root) return {};
        vector<int> ans;
        
        // Insert Root First
        if(!isleaf(root)) ans.push_back(root->data);

        // excluding leafs
        leftboundary(root, ans);

        leafnodes(root, ans);

        // excluding leafs
        rightReverseBoundary(root, ans);

        return ans;
    }
};


int main()
{

    return 0;
}