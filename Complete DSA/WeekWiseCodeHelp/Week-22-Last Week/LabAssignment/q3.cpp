#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

void printAnyPath(Node* root) {
    cout << "Any path from root to leaf: ";
    while (root) {
        cout << root->data << " ";
        if (root->left) 
            root = root->left;  
        else 
            root = root->right;  
    }
    cout << endl;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    printAnyPath(root);

    return 0;
}
