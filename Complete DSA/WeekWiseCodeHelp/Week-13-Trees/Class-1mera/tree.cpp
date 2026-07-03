# include<bits/stdc++.h>
using namespace std; 

class Node{

    public:
        int val;
        Node* left;
        Node* right;

        Node(int val){
            this->val = val;
            left = NULL;
            right = NULL;
        }

};

Node* createTree(){
    // root element
    int val;
    cin>>val;

    if(val == -1) return NULL;

    else{
        // valid value
        Node* root = new Node(val);

        // baki creation recursion karega
        root->left = createTree();
        root->right = createTree();

        return root;
    }

}

void preorder(Node* root){
    if(root == NULL){
        cout<<"null"<<" ";
        return;
    }

    cout<<root->val<<" ";

    preorder(root->left);

    preorder(root->right);

}

void lvlOrder(Node* root){
    if(root == NULL) return;

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        
        Node* front = q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<front->val<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }

            if(front->right != NULL){
                q.push(front->right);
            }
        }
        
    }
}

void levelOrderTraversing(Node* root){
    if(root == nullptr) return;

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }

        else{
            cout<<front->val<<" ";

            if(front->left != nullptr){
                q.push(front->left);
            }
            if(front->right != nullptr){
                q.push(front->right);
            }
        }

        
    }
}

void levelOrder(Node* root){

    if(root == NULL) return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

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
            cout<<front->val<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }

            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}


int main(){
    Node* root;
    root = createTree();

    // preorder(root);
    levelOrder(root);

 return 0;
}