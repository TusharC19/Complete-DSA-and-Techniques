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

int main(){
    node* root;
    root = createTree();

    cout<<"printing root "<<root->data<<endl;





 return 0;
}