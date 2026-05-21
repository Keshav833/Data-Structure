#include <iostream>
using namespace std;

/* Node structure */
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:

    Node* segregate(Node* head) {

        Node* temp = head;

        int zero = 0;
        int one = 0;
        int two = 0;

        // Count 0s, 1s, 2s
        while (temp != NULL) {

            if (temp->data == 0) {
                zero++;
            }

            if (temp->data == 1) {
                one++;
            }

            if (temp->data == 2) {
                two++;
            }

            temp = temp->next;
        }

        temp = head;

        // Fill 0s
        while (zero > 0) {
            temp->data = 0;
            temp = temp->next;
            zero--;
        }

        // Fill 1s
        while (one > 0) {
            temp->data = 1;
            temp = temp->next;
            one--;
        }

        // Fill 2s
        while (two > 0) {
            temp->data = 2;
            temp = temp->next;
            two--;
        }

        return head;
    }
};

// Print linked list
void printList(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    /*
        Test Case 1

        Input:
        1 -> 2 -> 0 -> 1 -> 2 -> 0

        Output:
        0 -> 0 -> 1 -> 1 -> 2 -> 2
    */

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(0);
    head1->next->next->next = new Node(1);
    head1->next->next->next->next = new Node(2);
    head1->next->next->next->next->next = new Node(0);

    Solution obj;

    cout << "Before Segregation:" << endl;
    printList(head1);

    obj.segregate(head1);

    cout << "After Segregation:" << endl;
    printList(head1);


    /*
        Test Case 2

        Input:
        2 -> 2 -> 1 -> 0

        Output:
        0 -> 1 -> 2 -> 2
    */

    Node* head2 = new Node(2);
    head2->next = new Node(2);
    head2->next->next = new Node(1);
    head2->next->next->next = new Node(0);

    cout << "\nBefore Segregation:" << endl;
    printList(head2);

    obj.segregate(head2);

    cout << "After Segregation:" << endl;
    printList(head2);

    return 0;
}