#include <algorithm>

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
    int diameter =0;
    int diameterOfBinaryTree(TreeNode* root) {
       maxdepth(root);
        return diameter;
    }

    int maxdepth(TreeNode* root){
        if(root==nullptr) return 0;

        int rightH = maxdepth(root->right);
        int leftH = maxdepth(root->left);

        diameter = max(diameter, (leftH + rightH));

        return 1 + max(rightH,leftH);
    }
};