#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

// Node* createBSTbyPass(){};
// complete function

Node *buildBST(int val, Node *&root)
{

    if (root == nullptr)
    {
        // create new node
        // first Node
        root = new Node(val);
        return root;
    }

    else
    {
        // root is not empty
        if (val < root->data)
        {
            // put it leftSubtree
            // root ke left ko update krdo
            // root ke left me laga do
            root->left = buildBST(val, root->left);
        }
        else
        {
            // val>root->val
            // put it rightSubtree
            root->right = buildBST(val, root->right);
        }
    }

    return root;
}

Node *createBST()
{
    cout << "Enter the value of mainroot node: ";
    int val;
    cin >> val;
    Node *root = NULL;

    while (val != -1)
    {
        root = buildBST(val, root);
        cout << "enter new node: ";
        cin >> val;
    }

    return root;
}

// print BST

void printpreorder(Node *mainroot)
{
    if (mainroot == nullptr)
        return;

    cout << mainroot->data << " ";
    printpreorder(mainroot->left);
    printpreorder(mainroot->right);
}

void printinorder(Node *mainroot)
{
    if (mainroot == nullptr)
        return;

    printinorder(mainroot->left);
    cout << mainroot->data << " ";
    printinorder(mainroot->right);
}

void printBST(Node *mainroot)
{
    queue<Node *> q;
    q.push(mainroot);
    q.push(NULL);

    while (!q.empty())
    {
        // front check
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            // ek level complete
            cout << endl; // go to net level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);

            if (front->right != nullptr)
                q.push(front->right);
        }
    }
}
/* -------------------------------------------- All basics functions ---------------------------------------*/

int minElement(Node* root){
    if(root == NULL) return -1;
    
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int maxElement(Node* root){
    if(root == NULL) return -1;
    
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

// Implement it using loop how to do that
bool searchBST(Node* root,int val){
    if(!root) return false;
    // iska matlab nhi mila and we reaches to the null node

    if(root->data == val) return true;

    else if(val<root->data){
        bool leftAns = searchBST(root->left,val);
        if(leftAns) return true;
    }

    else if(val>root->data){
        bool rightAns = searchBST(root->right,val);
        if(rightAns) return true;
    }

	//agar leftAns / rightAns is false;
    return false;
}

/* ------------------------------- Deletion from BST -----------------------------*/

Node* deleteNode(Node* root,int key){

    if(!root) return nullptr;

    if(root->data == key){
        // deletion
        // no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // right child is null
        else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // left child is null
        else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }
        
        // two childs hai - toh immediate predecessor or succesor find karenge
        else{
            // let immediate successor find krenge
            int successor = maxElement(root->right);
            root->data = successor;
            // root ke right ko update
            // root ke left me call chli gyi to delete node
            root->right = deleteNode(root->right,successor);
            return root;
        }
    } 

    else{
        // not match
        if(key<root->data){
            root->left = deleteNode(root->left,key);
        } 
        else{
            root->right = deleteNode(root->right,key);
        }
    }
}


int main()
{
    // static memory allocation
    // Node n(10);
    // Node* mainroot = NULL; // can pass node also
    Node *mainroot = createBST();

    // deletion
    printinorder(mainroot);
    cout<<endl;
    deleteNode(mainroot,60);
    printinorder(mainroot);
    cout<<endl;











    // printinorder(mainroot);
    // cout<<"\n";
    // minElement(mainroot);
    // maxElement(mainroot);

    // if(searchBST(mainroot,34)) cout<<"found\n";
    // else cout<<"not found\n";
    // // string ans = searchBST(mainroot,45) ? "found" : "not found";
    // cout<<ans<<"\n";


    return 0;
}