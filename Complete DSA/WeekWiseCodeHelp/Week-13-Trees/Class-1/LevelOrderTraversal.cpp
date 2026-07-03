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
        ~node(){cout<<"dtor is called"<<endl;};    

       
};
node* createTree(){
            int val;
            // cout<<"enter the value of node"<<endl;
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
                // cout<<"adding left child for "<<val<<endl;
                root->left = createTree();
                // cout<<"adding right child for "<<val<<endl;
                root->right = createTree();
                return root; 
            }

}

void levelOrderTraversalRihtTOleft(node* &root){

    // if root node is null then return
    if(root == NULL) return;
    
    queue<node*>q;
    // initial state maintain
    q.push(root);

    // logic A<B<C
    while (!q.empty())
    {
        node* front = q.front();
        q.pop();

        cout<<front->data<<" ";

        if(front->right != NULL){
            q.push(front->right);
        }

        if(front->left != NULL){
            q.push(front->left);
        }
        
    }
    
}


void levelOrderTraversalleftTOright(node* &root){
    
    // if root node is null then return
    if(root == NULL) return;
    
    queue<node*>q;
    // initial state maintain
    q.push(root);
    // yha pee pka lvl 1 is completed
    q.push(NULL);

    // logic A-B-C
    while (!q.empty())
    {
        vector<int>a;
        
        node* front = q.front();
        q.pop();

        if(front == NULL){
            // iska matlab current lvl complete ho gya hai
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


void zigzagLOT(node* root){
     queue<node*>q;
    // initial state maintain
    q.push(root);

    
}

//////////////////////////////////////////////////////////////////////////

int main(){
    node* root;
    root = createTree();
    cout<<"printing root Node is : "<<root->data<<endl;

    levelOrderTraversalleftTOright(root);
    // 10 
    // 20 30 
    // 40 50 60 


 return 0;
}