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

Node* createTree(){
    cout<<"enter value: ";
    int val;
    cin>>val;
    Node* root = NULL;

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




void inorder(Node* root,vector<int>&ans){
    if(root == NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

int minVal(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;

}

bool searchBST1(Node* root,int t){
    while(root != NULL){
        if(root->data==t) return true;
        if(root->data>t){
            root = root->left;
        }
        else
            root = root->right;
    }
    return false;
    
}

bool searchBST(Node* root,int t){
    if(root==NULL) return false;
    if(root->data == t) return true;

    if(t>root->data){
        bool r = searchBST(root->right,t);
        if(r==true) return true;
    }
    else{
        bool l = searchBST(root->left,t);
        if(l==true) return true;
    }
}


void deleteBST(){
    
}


int main(){

    Node* root = createTree();
    vector<int>a;
    inorder(root,a);
    for(int i:a) cout<<i<<" ";
    cout<<endl;
    // int minEle = minVal(root);
    // cout<<minEle<<endl;

    string ans = (searchBST(root,45)) ? "present" : "absent";
    cout<<ans<<endl;
   


 return 0;
}