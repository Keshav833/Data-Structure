#include <iostream>
using namespace std;

/* BST Node */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int key) {

        // Create new node if position found
        if (root == NULL)
            return new Node(key);

        if (key < root->data) {
            root->left = insert(root->left, key);
        }
        else {
            root->right = insert(root->right, key);
        }

        return root;
    }
};

// Inorder Traversal
void inorder(Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    /*
            10
           /  \
          5   20
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    Solution obj;

    root = obj.insert(root, 15);
    root = obj.insert(root, 25);
    root = obj.insert(root, 3);

    cout << "Inorder Traversal After Insertions:" << endl;

    inorder(root);

    return 0;
}