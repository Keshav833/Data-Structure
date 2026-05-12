#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void preorder(TreeNode* root , vector<int>& ans){

        if(root==nullptr){
            return ;
        }
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans ;

        preorder(root,ans);

        return ans;
    }

    // Iterative approach using stack
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            ans.push_back(node->val);
            
            // Push right first so left is processed first (stack is LIFO)
            if (node->right != nullptr) {
                st.push(node->right);
            }
            if (node->left != nullptr) {
                st.push(node->left);
            }
        }
        
        return ans;
    }

    // Morris Preorder Traversal (space optimized - O(1) extra space)
    vector<int> preorderTraversalMorris(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left child, visit current and move right
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor (rightmost node in left subtree)
                TreeNode* predecessor = curr->left;
                while (predecessor->right != nullptr && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                
                if (predecessor->right == nullptr) {
                    // First visit to current
                    ans.push_back(curr->val);
                    predecessor->right = curr;  // Create thread
                    curr = curr->left;
                } else {
                    // Second visit to current, remove thread
                    predecessor->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};

void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1: Tree with 3 nodes
    //       1
    //      / \
    //     2   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    
    cout << "Test Case 1: [1, 2, 3]" << endl;
    cout << "Recursive: ";
    printVector(solution.preorderTraversal(root1));
    
    cout << "Iterative: ";
    printVector(solution.preorderTraversalIterative(root1));
    
    cout << "Morris: ";
    printVector(solution.preorderTraversalMorris(root1));
    
    cout << endl;
    
    // Test Case 2: Single node
    TreeNode* root2 = new TreeNode(1);
    cout << "Test Case 2: [1]" << endl;
    cout << "Recursive: ";
    printVector(solution.preorderTraversal(root2));
    
    cout << "Iterative: ";
    printVector(solution.preorderTraversalIterative(root2));
    
    cout << "Morris: ";
    printVector(solution.preorderTraversalMorris(root2));
    
    cout << endl;
    
    // Test Case 3: Linear tree (left skewed)
    //       1
    //      /
    //     2
    //    /
    //   3
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->left->left = new TreeNode(3);
    
    cout << "Test Case 3: [1, 2, 3] (left skewed)" << endl;
    cout << "Recursive: ";
    printVector(solution.preorderTraversal(root3));
    
    cout << "Iterative: ";
    printVector(solution.preorderTraversalIterative(root3));
    
    cout << "Morris: ";
    printVector(solution.preorderTraversalMorris(root3));
    
    cout << endl;
    
    // Test Case 4: Balanced tree
    //        1
    //       / \
    //      2   5
    //     / \
    //    3   4
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(5);
    root4->left->left = new TreeNode(3);
    root4->left->right = new TreeNode(4);
    
    cout << "Test Case 4: [1, 2, 3, 4, 5] (balanced)" << endl;
    cout << "Recursive: ";
    printVector(solution.preorderTraversal(root4));
    
    cout << "Iterative: ";
    printVector(solution.preorderTraversalIterative(root4));
    
    cout << "Morris: ";
    printVector(solution.preorderTraversalMorris(root4));
    
    return 0;
}