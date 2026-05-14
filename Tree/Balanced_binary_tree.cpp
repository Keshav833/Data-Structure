#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool bal = true;

    bool isBalanced(TreeNode* root) {
        bal = true;
        if (root == nullptr) return true;
        maxdepth(root);
        return bal;
    }

    int maxdepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftH = maxdepth(root->left);
        int rightH = maxdepth(root->right);

        if (abs(leftH - rightH) > 1) {
            bal = false;
        }

        return 1 + max(leftH, rightH);
    }
};