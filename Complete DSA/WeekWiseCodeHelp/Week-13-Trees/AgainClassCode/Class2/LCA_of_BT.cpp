
class Solution {
    public:
    
        int findIndex(vector<int>&inorder,int element){
            for(int i=0;i<inorder.size();i++){
                if(inorder[i] == element) return i;
            }
            return -1;
        }
    
        TreeNode* createTree(vector<int>&preorder,vector<int>&inorder,int &preorderIndex,int inorderStart,int inorderEnd,int size){
            if(preorderIndex >= size) return NULL;
    
            if(inorderStart >= inorderEnd) return NULL;
    
            // warna element nikalo then proces karo
            int element = preorder[preorderIndex++];
            // then create node
            TreeNode* root = new TreeNode(element);
    
            // then element index find in inorder array
            int currElementIndex = findIndex(inorder,element);
            // Now process the left and right part of current Element
            root->left = createTree(preorder,inorder,preorderIndex,inorderStart,currElementIndex-1,size);
            root->right = createTree(preorder,inorder,preorderIndex,currElementIndex+1,inorderEnd,size);
    
            return root;
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int preorderIndex = 0;
            int inorderStart = 0;
            int inorderEnd = inorder.size()-1;
            int size = preorder.size();
            TreeNode* ans = createTree(preorder,inorder,preorderIndex,inorderStart,inorderEnd,size);
            return ans;
        }
    };