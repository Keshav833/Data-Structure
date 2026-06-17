#include <iostream>
using namespace std;

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

    int findMaxFork(Node* root, int k) {

        int ans = -1;

        while(root) {

            if(root->data <= k) {
                ans = root->data;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        return ans;
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

    cout << obj.findMaxFork(root, 18) << endl; // 15
    cout << obj.findMaxFork(root, 26) << endl; // 25
    cout << obj.findMaxFork(root, 4) << endl;  // -1

    return 0;
}