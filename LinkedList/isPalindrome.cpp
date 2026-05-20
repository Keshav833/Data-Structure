#include <iostream>
#include <stack>
using namespace std;

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
    bool isPalindrome(Node *head) {

        stack<int> st;
        Node* temp = head;

        // Push all elements into stack
        while (temp != NULL) {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;

        // Compare with stack
        while (temp != NULL) {

            if (temp->data != st.top()) {
                return false;
            }

            st.pop();
            temp = temp->next;
        }

        return true;
    }
};

// Helper function to print result
void checkPalindrome(Node* head) {
    Solution obj;

    if (obj.isPalindrome(head)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
}

int main() {

    /*
        Test Case 1
        1 -> 2 -> 2 -> 1

        Palindrome
    */

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(1);

    checkPalindrome(head1);


    /*
        Test Case 2
        1 -> 2 -> 3

        Not Palindrome
    */

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    checkPalindrome(head2);


    /*
        Test Case 3
        5 -> 6 -> 5

        Palindrome
    */

    Node* head3 = new Node(5);
    head3->next = new Node(6);
    head3->next->next = new Node(5);

    checkPalindrome(head3);


    /*
        Test Case 4
        Single node

        Palindrome
    */

    Node* head4 = new Node(10);

    checkPalindrome(head4);

    return 0;
}