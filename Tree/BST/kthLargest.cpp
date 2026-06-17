#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:

    void inorder(Node* root, vector<int>& ans) {

        if(root == NULL)
            return;

        inorder(root->left, ans);

        ans.push_back(root->data);

        inorder(root->right, ans);
    }

    int kthLargest(Node *root, int k) {

        vector<int> ans;

        inorder(root, ans);

        if(k <= ans.size()) {
            return ans[ans.size() - k];
        }

        return -1;
    }
};

int main() {

    /*
            5
          /   \
         3     7
        / \   / \
       2  4  6  8
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution obj;

    cout << "1st Largest = "
         << obj.kthLargest(root, 1) << endl;

    cout << "3rd Largest = "
         << obj.kthLargest(root, 3) << endl;

    cout << "5th Largest = "
         << obj.kthLargest(root, 5) << endl;

    return 0;
}