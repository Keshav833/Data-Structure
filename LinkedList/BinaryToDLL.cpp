/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
//mY code is not optimal as it uses extra space to store the inorder traversal of the tree.
// We can optimize it by using a pointer to keep track of the previous node in the DLL 
// and modify the tree nodes in place to create the DLL without using extra space.
// class Solution {
//   public:
//     void inorder(Node* root,vector<int>& ans){
        
//         if(root==NULL) return;
        
//         inorder( root->left,ans);
//         ans.push_back(root->data);
//         inorder(root->right,ans);
        
//     };
//     Node* bToDLL(Node* root) {
//         // code here
//         // Node* dummy = new Node(-1);
//         // Node* res = dummy;
//         if(root==NULL || (root->left==NULL && root->right==NULL) ){
//             return root;
//         }
//         vector<int> ans;
//         inorder(root,ans);
//         Node*  prev = NULL ;
//         Node* curr = new Node(ans[0]);
//         root = curr;
//         for(int i =1;i<ans.size();i++){
//             Node* newNode = new Node(ans[i]);
//             curr->right= newNode;
//             curr->left = prev;
//             // newNode->left = prev;
//             prev = curr;
//             curr = newNode;
            
//         }
//         curr->right = NULL;
        
//         return root;
        
//     }
// };

//optimal solution without using extra space

/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
#include <iostream>
using namespace std;

/* Structure for tree and linked list */
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {

public:

    Node* head = NULL;
    Node* prev = NULL;

    // Inorder traversal
    void inOrder(Node* root) {

        if (root == NULL)
            return;

        // Left subtree
        inOrder(root->left);

        // First node
        if (prev == NULL) {

            head = root;

        } else {

            // Connect nodes
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        // Right subtree
        inOrder(root->right);
    }

    // Convert Binary Tree to DLL
    Node* bToDLL(Node* root) {

        inOrder(root);

        return head;
    }
};

// Print DLL
void printDLL(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    cout << endl;
}

int main() {

    /*
            10
           /  \
          5   20
         / \   \
        2   8   30

        Inorder:
        2 5 8 10 20 30
    */

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(20);

    root->left->left = new Node(2);
    root->left->right = new Node(8);

    root->right->right = new Node(30);

    Solution obj;

    Node* head = obj.bToDLL(root);

    cout << "Doubly Linked List:" << endl;

    printDLL(head);

    return 0;
}