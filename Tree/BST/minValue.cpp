#include <iostream>
using namespace std;

/* BST Node */
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

    int minValue(Node* root) {

        if(root->left != NULL) {
            return minValue(root->left);
        }

        return root->data;
    }
};

int main() {

    /*
              20
             /  \
           10    30
          / \
         5  15
        /
       2

       Minimum = 2
    */

    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->left->left->left = new Node(2);

    Solution obj;

    cout << "Minimum Value = "
         << obj.minValue(root)
         << endl;

    return 0;
}