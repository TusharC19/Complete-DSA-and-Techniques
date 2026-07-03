#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insertNode()
{
    int n;
    cin >> n;
    if (n == -1)
        return nullptr;
    TreeNode *root = new TreeNode(n);

    root->left = insertNode();
    root->right = insertNode();

    return root;
}

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
        
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(TreeNode *root)
{
    if (root == NULL)
        return;

    
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}


void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
    
}

void levelOrder(TreeNode* root){
    deque<TreeNode*>q;
    q.push_back(root);
    q.push_back(NULL);


    while(!q.empty()){
        auto front = q.front();
        q.pop_front();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push_back(NULL);
            }
        }

        else{
            cout<<front->val<<" ";
            if(front->left) q.push_back(front->left);
            if(front->right) q.push_back(front->right);
        }
    }

}



int main()
{
    TreeNode *root = insertNode();
    // preorder(root);
    // postorder(root);
    // inorder(root);
    levelOrder(root);
    

    return 0;
}