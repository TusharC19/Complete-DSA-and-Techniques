#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Function to print a single root-to-leaf path
void printPath(vector<int>& path) {
    for (int val : path)
        cout << val << " ";
    cout << endl;
}

// Recursive function to print all root-to-leaf branches
void printBranches(node* root, vector<int>& path) {
    if (root == NULL)
        return;

    path.push_back(root->data);

    // Leaf node reached
    if (root->left == NULL && root->right == NULL)
        printPath(path);
    else {
        printBranches(root->left, path);
        printBranches(root->right, path);
    }

    // Backtrack
    path.pop_back();
}

void printAllBranches(node* root) {
    vector<int> path;
    cout << "\nDifferent branches (Root-to-Leaf Paths):\n";
    printBranches(root, path);
}

int main() {
 
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    cout << "Root of the tree is: " << root->data << endl;

    printAllBranches(root);

    return 0;
}
