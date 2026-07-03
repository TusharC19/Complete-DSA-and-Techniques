# include<bits/stdc++.h>
using namespace std; 

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }

};


Node* buildBST(int val,Node* &root){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    else{
        if(val<root->data){
            root->left = buildBST(val,root->left);
        }
        else{
            root->right = buildBST(val,root->right);
        }
    }

    return root;
}

Node* createTree(Node* &root){
    cout<<"enter value: ";
    int val;
    cin>>val;

    while (val != -1)
    {
        root = buildBST(val,root);
        cout<<"enter value: ";
        cin>>val;
    }

    return root;
    
}

void lvlorderTraversal(Node* root){

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{            
            cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }

            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}   


void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int getMin(Node* root){
    if(root == nullptr) return -1;
    
    if(root->left == nullptr && root->right == nullptr){
        return root->data;
    }

    int min = getMin(root->left);

    return min;
}

bool searchBST(Node* root,int val){
    if(root==nullptr) return false;

    if(root->data == val) return true;

    if(val<root->data){
        return searchBST(root->left,val);
    }
    else{
        return searchBST(root->right,val);
    }

}


int main(){

    Node* root = NULL;
    root = createTree(root);
    lvlorderTraversal(root);
    cout<<endl;
    // inorder(root);
    // cout<<endl;

    int min = getMin(root);
    cout<<min<<endl;

    bool present = searchBST(root,7);
    cout<<present<<endl;


 return 0;
}