#include <iostream>
using namespace std;

/*
    Binary Tree Node
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {

public:

    bool isMirror(Node* r1, Node* r2) {

        // Both NULL
        if (r1 == NULL && r2 == NULL) {
            return true;
        }

        // One NULL
        if (r1 == NULL || r2 == NULL) {
            return false;
        }

        return (r1->data == r2->data) &&
               isMirror(r1->left, r2->right) &&
               isMirror(r1->right, r2->left);
    }

    bool isSymmetric(Node* root) {

        if (root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};

// Helper function
void checkSymmetry(Node* root) {

    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Symmetric Tree" << endl;
    else
        cout << "Not Symmetric Tree" << endl;
}

int main() {

    /*
            1
          /   \
         2     2
        / \   / \
       3  4  4   3

       Symmetric
    */

    Node* root1 = new Node(1);

    root1->left = new Node(2);
    root1->right = new Node(2);

    root1->left->left = new Node(3);
    root1->left->right = new Node(4);

    root1->right->left = new Node(4);
    root1->right->right = new Node(3);

    cout << "Test Case 1: ";
    checkSymmetry(root1);


    /*
            1
          /   \
         2     2
          \      \
           3      3

       Not Symmetric
    */

    Node* root2 = new Node(1);

    root2->left = new Node(2);
    root2->right = new Node(2);

    root2->left->right = new Node(3);
    root2->right->right = new Node(3);

    cout << "Test Case 2: ";
    checkSymmetry(root2);

    return 0;
}