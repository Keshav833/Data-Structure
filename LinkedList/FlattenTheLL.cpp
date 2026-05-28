#include <iostream>
using namespace std;

/*
    Structure of Node
*/

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {

public:

    // Merge two sorted bottom lists
    Node* merge(Node *list1, Node *list2) {

        Node* dummy = new Node(-1);
        Node* res = dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->data < list2->data) {

                dummy->bottom = list1;
                dummy = list1;

                list1 = list1->bottom;

            } else {

                dummy->bottom = list2;
                dummy = list2;

                list2 = list2->bottom;
            }

            // Remove horizontal links
            dummy->next = NULL;
        }

        // Remaining nodes
        if (list1)
            dummy->bottom = list1;
        else
            dummy->bottom = list2;

        return res->bottom;
    }

    // Flatten linked list
    Node* flatten(Node *root) {

        // Base case
        if (root == NULL || root->next == NULL) {
            return root;
        }

        // Flatten remaining list
        Node* mergeHead = flatten(root->next);

        // Merge current list
        root = merge(root, mergeHead);

        return root;
    }
};

// Print flattened list
void printList(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }

    cout << endl;
}

int main() {

    /*
        Structure:

        5 -> 10 -> 19 -> 28
        |    |     |     |
        7    20    22    35
        |          |     |
        8          50    40
        |                |
        30               45
    */

    Node* head = new Node(5);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Solution obj;

    Node* result = obj.flatten(head);

    cout << "Flattened List:" << endl;

    printList(result);

    return 0;
}