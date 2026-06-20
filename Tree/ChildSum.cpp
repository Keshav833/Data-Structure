#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    bool isSumProperty(Node *root) {

        if(root == NULL)
            return true;

        if(root->left == NULL &&
           root->right == NULL)
            return true;

        int left = 0;
        int right = 0;

        if(root->left)
            left = root->left->data;

        if(root->right)
            right = root->right->data;

        return (root->data == left + right)
               && isSumProperty(root->left)
               && isSumProperty(root->right);
    }
};

int main() {

    /*
            10
           /  \
          8    2
         / \
        3   5
    */

    Node* root = new Node(10);

    root->left = new Node(8);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(5);

    Solution obj;

    if(obj.isSumProperty(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}