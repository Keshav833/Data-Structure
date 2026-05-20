#include <iostream>
using namespace std;

/* Structure of linked list Node */
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:

    void removeLoop(Node* head) {

        Node* slow = head;
        Node* fast = head;

        // Detect loop
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            // Loop found
            if (slow == fast) {

                slow = head;

                // Special case:
                // loop starts from head
                if (slow == fast) {

                    while (fast->next != slow) {
                        fast = fast->next;
                    }

                } else {

                    // Move both one step
                    while (slow->next != fast->next) {
                        slow = slow->next;
                        fast = fast->next;
                    }
                }

                // Break loop
                fast->next = NULL;
                return;
            }
        }
    }
};

// Print linked list
void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    /*
        Test Case 1

        1 -> 2 -> 3 -> 4 -> 5
                  ^         |
                  |_________|

        Loop starts at 3
    */

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Create loop
    head1->next->next->next->next->next = head1->next->next;

    Solution obj;

    obj.removeLoop(head1);

    cout << "After removing loop (Test Case 1):" << endl;
    printList(head1);


    /*
        Test Case 2

        Loop starting from head

        10 -> 20 -> 30
         ^            |
         |____________|
    */

    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    // Loop to head
    head2->next->next->next = head2;

    obj.removeLoop(head2);

    cout << "\nAfter removing loop (Test Case 2):" << endl;
    printList(head2);


    /*
        Test Case 3

        No loop
    */

    Node* head3 = new Node(100);
    head3->next = new Node(200);
    head3->next->next = new Node(300);

    obj.removeLoop(head3);

    cout << "\nAfter removing loop (Test Case 3):" << endl;
    printList(head3);

    return 0;
}