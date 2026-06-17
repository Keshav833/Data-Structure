#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:

    int inOrderSuccessor(Node *root, Node *k) {

        Node* succ = NULL;

        while(root) {

            if(root->data > k->data) {

                succ = root;
                root = root->left;

            } else {

                root = root->right;
            }
        }

        return succ ? succ->data : -1;
    }
};

int main() {

    /*
              20
             /  \
           10    30
          / \    /
         5  15 25

    */

    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right->left = new Node(25);

    Solution obj;

    cout << "Successor of 15 = "
         << obj.inOrderSuccessor(root, root->left->right)
         << endl;

    cout << "Successor of 25 = "
         << obj.inOrderSuccessor(root, root->right->left)
         << endl;

    return 0;
}