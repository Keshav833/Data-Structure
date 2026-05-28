#include <iostream>
using namespace std;

/*
    Node structure
*/

class Node {
public:
    int val;
    Node* next;

    Node(int num) {
        val = num;
        next = NULL;
    }
};

class Solution {

public:

    // Check prime
    bool isPrime(int n) {

        if (n == 2)
            return true;

        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {

            if (n % i == 0)
                return false;
        }

        return true;
    }

    // Find nearest prime
    int nearestPrime(int n) {

        if (isPrime(n))
            return n;

        for (int dist = 1;; dist++) {

            bool lower = isPrime(n - dist);
            bool upper = isPrime(n + dist);

            // If both are prime, choose smaller
            if (lower && upper) {
                return n - dist;
            }

            if (lower)
                return n - dist;

            if (upper)
                return n + dist;
        }
    }

    // Replace values with nearest prime
    Node* primeList(Node* head) {

        Node* temp = head;

        while (temp) {

            temp->val = nearestPrime(temp->val);

            temp = temp->next;
        }

        return head;
    }
};

// Print linked list
void printList(Node* head) {

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    /*
        Input:
        1 -> 15 -> 20 -> 30

        Output:
        2 -> 13 -> 19 -> 29
    */

    Node* head = new Node(1);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);

    cout << "Original List:" << endl;
    printList(head);

    Solution obj;

    head = obj.primeList(head);

    cout << "\nAfter Replacing with Nearest Primes:" << endl;
    printList(head);

    return 0;
}