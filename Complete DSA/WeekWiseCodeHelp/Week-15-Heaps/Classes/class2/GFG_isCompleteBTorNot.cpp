//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++
// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// ANS STARTS FROM HERE
class Solution {
  public:
    bool completeNessCBT(Node* root){
        queue<Node*>q;
        q.push(root);
        bool flagofNull = false;

        while(!q.empty()){
            Node* front = q.front();
            q.pop();


            if(front==NULL) flagofNull = true;

            // if front is not null
            else{
                // null ke baad ek number mil rha hai
                // if after null we get flag = true and front != NULL 
                // then it is not cbt 
                if(flagofNull == true) return false;

                else{
                    // push kra do node childs
                    // niche wrong code hai since if null the
                    // it will not insert the node
                    // if(front->left) q.push(front->left);
                    // if(front->right) q.push(front->right);
                    q.push(front->left);
                    q.push(front->right);

                }
            }

        }
        // yha tak pura aa gya
        return true;
    };
 
    bool checkMaxProperty(Node* root){
            
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        
        // pura left ka ans aa gya 
        bool leftAns = checkMaxProperty(root->left);
        // pura right ka ans aa gya
        bool rightAns = checkMaxProperty(root->right);
        
        // check for current true
        bool option1 = true;
        if(root->left/*left exists*/ && root->data <root->left->data) option1 = false;
        
        bool option2 = true;
        if(root->right/*left exists*/ && root->data <root->right->data) option2 = false;
        
        bool currNodeAns = (option1 && option2);
        
        // now check all 3 ans
        if(currNodeAns && leftAns && rightAns) return true;
        else return false;
        
    }
    
    
    bool isHeap(struct Node* tree) {
        if(tree == nullptr) return true;
        
        bool ans1 = completeNessCBT(tree);
        bool ans2 = checkMaxProperty(tree);
        
        if(ans1 && ans2) return true;
        else return false;
    }
};

// ANS ENDS HERE

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends