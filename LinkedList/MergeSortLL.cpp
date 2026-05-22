#include <iostream>
using namespace std;

/*
    Node structure
*/

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {

public:

    // Find middle node
    Node* findMiddle(Node* head) {

        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted linked lists
    Node* merge(Node* list1, Node* list2) {

        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->data < list2->data) {

                temp->next = list1;
                temp = list1;
                list1 = list1->next;

            } else {

                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        // Remaining nodes
        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy->next;
    }

    // Merge Sort
    Node* mergeSort(Node* head) {

        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find middle
        Node* middle = findMiddle(head);

        Node* right = middle->next;
        middle->next = NULL;

        Node* left = head;

        // Recursive sort
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge sorted lists
        return merge(left, right);
    }
};

// Print linked list
void printList(Node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    /*
        Test Case

        Input:
        4 -> 2 -> 1 -> 5 -> 3

        Output:
        1 -> 2 -> 3 -> 4 -> 5
    */

    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(3);

    cout << "Original List:" << endl;
    printList(head);

    Solution obj;

    head = obj.mergeSort(head);

    cout << "\nSorted List:" << endl;
    printList(head);

    return 0;
}