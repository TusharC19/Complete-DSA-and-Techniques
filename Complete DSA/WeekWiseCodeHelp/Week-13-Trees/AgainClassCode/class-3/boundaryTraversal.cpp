# include<bits/stdc++.h>
using namespace std; 

class Node {
    public:
      int data;
      Node* left;
      Node* right;
  
      // Constructor to initialize a new node
      Node(int val) {
          data = val;
          left = NULL;
          right = NULL;
      }
  };

class Solution {
    public:
    
      void leftboundary(vector<int>&ans,Node* root){
          if((root==NULL)||(root->left==NULL && root->right==NULL)) return;
          
          
          ans.push_back(root->data);
          // then process further 
          
          // if agar left not exist toh right me jao
          if(root->left == NULL){
              leftboundary(ans,root->right);
          }
          // warna left me jate jao
          else{
              leftboundary(ans,root->left);
          }
          
          return;
      }
      
      void leafboundary(vector<int>&ans,Node* root){
          // use preorder traversal
          if(root==NULL){
              return;
          }
          if(root->left == NULL && root->right == NULL){
              ans.push_back(root->data);
              return;
          }
          
          leafboundary(ans,root->left);
          leafboundary(ans,root->right);
          
          return;
      }
      
      void rightboundary(vector<int>&ans,Node* root){
          if((root==NULL)||(root->left==NULL && root->right==NULL)) return;
          
          if(root->right == NULL){
              rightboundary(ans,root->left);
          }
          // warna left me jate jao
          else{
              rightboundary(ans,root->right);
          }
          // now yha pe store ans
          // ate samay store kra rhe since reverse right boundary
          ans.push_back(root->data);
          
          return;
          
      }
    
    
      vector<int> boundaryTraversal(Node *root) {
          
          
          vector<int>ans;
          // root node store
          ans.push_back(root->data);
          
          // left boundary store
          leftboundary(ans,root->left);
          
          // left-> leaf boundary store
          leafboundary(ans,root->left);
          
          // right-> leaf boundary store
          leafboundary(ans,root->right);
          
          // right-> reverse right boundary store
          rightboundary(ans,root->right);
          
          // for(int i: ans) cout<<i<<" ";
          // cout<<endl;
          
          return ans;
          
          
          
          
       
          
      }
  };


int main(){
    
 return 0;
}