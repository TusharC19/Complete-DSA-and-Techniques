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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            TreeNode* node=front.first;
            int lvl=front.second;

            mp[lvl]=node->val;

            if(node->left) q.push({node->left,lvl+1});
            if(node->right) q.push({node->right,lvl+1});

        }

        vector<int>ans;
        for(auto&it:mp) ans.push_back(it.second);
        return ans;

    }
};



int main(){
    
 return 0;
}