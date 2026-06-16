#include <iostream>
using namespace std;

/* Definition for Node */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:

    bool search(Node* root, int key) {

        if (root == NULL)
            return false;

        if (key < root->data) {
            return search(root->left, key);
        }

        if (key > root->data) {
            return search(root->right, key);
        }

        return true;
    }
};

int main() {

    /*
              10
             /  \
            5    20
           / \   / \
          3   7 15 25
    */

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(20);

    root->left->left = new Node(3);
    root->left->right = new Node(7);

    root->right->left = new Node(15);
    root->right->right = new Node(25);

    Solution obj;

    cout << "Searching 15: ";

    if (obj.search(root, 15))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Searching 8: ";

    if (obj.search(root, 8))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}