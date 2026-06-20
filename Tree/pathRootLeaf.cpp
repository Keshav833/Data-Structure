#include <iostream>
#include <vector>
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

    void solve(Node* root,
               vector<int>& path,
               vector<vector<int>>& ans) {

        if(root == NULL)
            return;

        path.push_back(root->data);

        if(root->left == NULL &&
           root->right == NULL) {

            ans.push_back(path);
        }

        solve(root->left, path, ans);
        solve(root->right, path, ans);

        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(root, path, ans);

        return ans;
    }
};

int main() {

    /*
            1
           / \
          2   3
         /
        4

    Paths:
    1 2 4
    1 3
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    Solution obj;

    vector<vector<int>> ans = obj.Paths(root);

    for(auto &path : ans) {

        for(int x : path) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}