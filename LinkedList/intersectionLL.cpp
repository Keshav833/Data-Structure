#include <iostream>
using namespace std;

/*
    Structure of Node
*/

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

    Node* intersectPoint(Node* head1, Node* head2) {

        Node* temp1 = head1;
        Node* temp2 = head2;

        while (temp1 != temp2) {

            // Move temp1
            if (temp1 == NULL) {
                temp1 = head2;
            } else {
                temp1 = temp1->next;
            }

            // Move temp2
            if (temp2 == NULL) {
                temp2 = head1;
            } else {
                temp2 = temp2->next;
            }
        }

        return temp1;
    }
};

// Print result
void printIntersection(Node* node) {

    if (node == NULL) {
        cout << "No Intersection" << endl;
    } else {
        cout << "Intersection at node with value: "
             << node->data << endl;
    }
}

int main() {

    /*
        Common part:
        30 -> 40 -> 50
    */

    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    /*
        List 1:
        10 -> 20 -> 30 -> 40 -> 50
    */

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = common;

    /*
        List 2:
        15 -> 30 -> 40 -> 50
    */

    Node* head2 = new Node(15);
    head2->next = common;

    Solution obj;

    Node* ans = obj.intersectPoint(head1, head2);

    cout << "Test Case 1:" << endl;
    printIntersection(ans);


    /*
        Test Case 2
        No intersection
    */

    Node* a = new Node(1);
    a->next = new Node(2);
    a->next->next = new Node(3);

    Node* b = new Node(4);
    b->next = new Node(5);

    ans = obj.intersectPoint(a, b);

    cout << "\nTest Case 2:" << endl;
    printIntersection(ans);

    return 0;
}