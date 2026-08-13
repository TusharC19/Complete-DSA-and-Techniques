# include<bits/stdc++.h>
using namespace std; 


void solve() {
    vector<int> a = {1, 2, 3};

    // Insert single element at beginning
    a.insert(a.begin(), 0);   // {0, 1, 2, 3}

    // Insert multiple copies at position
    a.insert(a.begin() + 2, 2, 99); // {0, 1, 99, 99, 2, 3}

    // Insert range from another vector
    vector<int> b = {7, 8};
    a.insert(a.end(), b.begin(), b.end()); // {0, 1, 99, 99, 2, 3, 7, 8}

    for (int x : a) cout << x << " ";
}



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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            TreeNode* node=front.first;
            int value=node->val,ind=front.second.first,lvl=front.second.second;
            mp[ind][lvl].insert(value);

        
            if(node->left){
                q.push({node->left,{ind-1,lvl+1}});
            }
            if(node->right){
                q.push({node->right,{ind+1,lvl+1}});
            }


        }

        vector<vector<int>>ans;
        for(auto&i:mp){
            vector<int>a;
            for(auto&j:i.second){
                // multiset
                auto b=j.second;
                int lvl=j.first;
                a.insert(a.end(),b.begin(),b.end());
            }
            ans.push_back(a);
        }



        return ans;
    }
};



int main(){
    
 return 0;
}
