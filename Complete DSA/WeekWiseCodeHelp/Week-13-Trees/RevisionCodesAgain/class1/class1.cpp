# include<bits/stdc++.h>
using namespace std; 

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

void preorder(TreeNode* root){
    if(root==NULL) return;
    
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);

}

void inorder(TreeNode* root){
    if(root==NULL) return;
    
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);

}

TreeNode* insertNode(){
    int val;cin>>val;
    // 10 50 40 -1 -1 -1 20 30 -1 -1 60 -1 -1

    if(val==-1) return NULL;

    TreeNode* root = new TreeNode(val);
    // insert in left
    root->left = insertNode();
    // insert in right
    root->right = insertNode();
    // on return mein return karke attach node pointer
    return root;
}

void levelOrder(TreeNode* root){
    if(root==NULL) return;

    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode* front = q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        
        else{
            
            cout<<front->data<<" ";

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
    

}


TreeNode* deleteNode(){

}



int main(){
    TreeNode* root;
    root = insertNode();


    levelOrder(root);


 return 0;
}