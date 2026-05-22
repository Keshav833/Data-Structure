#include <iostream>
using namespace std;

/* Structure of Node */
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:

    Node* mergeResult(Node *node1, Node *node2) {

        Node* temp1 = node1;
        Node* temp2 = node2;

        Node* head = NULL;
        Node* tail = NULL;

        // Merge two sorted lists
        while (temp1 != NULL && temp2 != NULL) {

            Node* newNode;

            if (temp1->data < temp2->data) {

                newNode = new Node(temp1->data);
                temp1 = temp1->next;

            } else {

                newNode = new Node(temp2->data);
                temp2 = temp2->next;
            }

            // First node
            if (head == NULL) {

                head = newNode;
                tail = newNode;

            } else {

                tail->next = newNode;
                tail = newNode;
            }
        }

        // Remaining nodes from list1
        while (temp1 != NULL) {

            Node* newNode = new Node(temp1->data);

            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            temp1 = temp1->next;
        }

        // Remaining nodes from list2
        while (temp2 != NULL) {

            Node* newNode = new Node(temp2->data);

            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            temp2 = temp2->next;
        }

        // Reverse merged list
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) {

            Node* front = temp->next;

            temp->next = prev;

            prev = temp;
            temp = front;
        }

        return prev;
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
        
        List 1:
        1 -> 3 -> 5

        List 2:
        2 -> 4 -> 6

        Merged:
        1 2 3 4 5 6

        Reversed:
        6 5 4 3 2 1
    */

    Node* node1 = new Node(1);
    node1->next = new Node(3);
    node1->next->next = new Node(5);

    Node* node2 = new Node(2);
    node2->next = new Node(4);
    node2->next->next = new Node(6);

    Solution obj;

    Node* result = obj.mergeResult(node1, node2);

    cout << "Merged Reversed List:" << endl;

    printList(result);

    return 0;
}