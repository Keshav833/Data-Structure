#include <iostream>
using namespace std;

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
    int lengthOfLoop(Node *head) {

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if (slow == fast) {

                Node* temp = slow->next;
                int count = 1;

                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }

                return count;
            }
        }

        // No loop
        return 0;
    }
};

int main() {

    /*
        Test Case 1

        1 -> 2 -> 3 -> 4 -> 5
                  ^         |
                  |_________|

        Loop length = 3
    */

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Creating loop
    head1->next->next->next->next->next = head1->next->next;

    Solution obj;

    cout << "Loop Length in Test Case 1: "
         << obj.lengthOfLoop(head1) << endl;


    /*
        Test Case 2

        10 -> 20 -> 30 -> NULL

        No loop
    */

    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    cout << "Loop Length in Test Case 2: "
         << obj.lengthOfLoop(head2) << endl;


    /*
        Test Case 3

        Single node with self-loop

        100
         ^|
         ||

        Loop length = 1
    */

    Node* head3 = new Node(100);
    head3->next = head3;

    cout << "Loop Length in Test Case 3: "
         << obj.lengthOfLoop(head3) << endl;

    return 0;
}