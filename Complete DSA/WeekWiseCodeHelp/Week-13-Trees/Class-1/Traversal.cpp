# include<bits/stdc++.h>
using namespace std; 

class node{
    public:
        int data;
        node* left;
        node* right;
    
        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
        ~node(){};    

       
};
 node* createTree(){
            int val;
            cout<<"enter the value of node"<<endl;
            cin>>val;

            if(val==-1){
                return NULL;
            }
            // agar -1 nhi hua toh tree bante hi rhega - stack overflow
            // valid value
            else{
                // ek case mera
                node* root = new node(val);
                // baki recursion krega
                cout<<"adding left child for "<<val<<endl;
                root->left = createTree();
                cout<<"adding right child for "<<val<<endl;
                root->right = createTree();
                return root; 
            }

}

void preorder(node* root){
    // base case 
    if(root == NULL) return ;

    cout<<root->data<<endl;

    // recursion karkega
    // left pointer
    preorder(root->left);   
    // here we are not trying to acces nullptr , we just pass null for base check
    // right pointer diya
    preorder(root->right);

}

void inorder(node* root){
    // base case 
    if(root == NULL) return ;

    // recursion karkega
    // left pointer
    inorder(root->left);
    // printing root element
    cout<<root->data<<endl;
    // right pointer diya
    inorder(root->right);

}

void postorder(node* root){
    // base case 
    if(root == NULL) return ;

    // recursion karkega
    // left pointer
    postorder(root->left);
    // right pointer diya
    postorder(root->right);
    // printing root element
    cout<<root->data<<endl;

}

void levelOrder(node* root){
    
}

int main(){
    node* root;
    root = createTree();

    cout<<"root node is "<<root->data<<endl;
    cout<<endl;

    // preorder(root);
    // inorder(root);
    postorder(root);
    





 return 0;
}