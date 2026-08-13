# include<bits/stdc++.h>
using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};


class Solution{
    public:

    vector<int> topView1(TreeNode *root) {
       map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int value = node->data, ind = front.second.first,
                lvl = front.second.second;
            mp[ind][lvl].insert(value);

            if (node->left) {
                q.push({node->left, {ind - 1, lvl + 1}});
            }
            if (node->right) {
                q.push({node->right, {ind + 1, lvl + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto& i : mp) {
            vector<int> a;
            for (auto& j : i.second) {
                // multiset
                auto b = j.second;
                int lvl = j.first;
                a.insert(a.end(), b.begin(), b.end());
            }
            ans.push_back(a);
        }

        vector<int>v;
        for(auto&it:ans){
            v.push_back(it[0]);
        }

        return v;
    }

    vector<int>topView(TreeNode* root){
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();

            TreeNode* node=front.first;
            int ind=front.second;

            if(mp.find(ind)==mp.end()) mp[ind]=node->data;

            if(node->left) q.push({node->left,ind-1});
            if(node->right) q.push({node->right,ind+1});

        }


        vector<int>ans;
        for(auto&it:mp){
            ans.push_back(it.second);
        }

        return ans;

    }

    vector<int>bottomView(TreeNode* root){
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();

            TreeNode* node=front.first;
            int ind=front.second;

            mp[ind]=node->data;

            if(node->left) q.push({node->left,ind-1});
            if(node->right) q.push({node->right,ind+1});

        }


        vector<int>ans;
        for(auto&it:mp){
            ans.push_back(it.second);
        }

        return ans;

    }


};


int main(){
    map<int,int>mp;
    mp[0]=1,mp[8]=5,mp[-2]=3,mp[-4]=19;

    // for(auto&it:mp) cout<<it.first<<"->"<<it.second<<endl;

    multiset<int>s;
    s.insert(3);
    s.insert(-1);
    s.insert(-5);
    s.insert(0);
    s.insert(8);
    s.insert(19);

    for(int i:s) cout<<i<<" ";




    
 return 0;
}