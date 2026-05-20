#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *next;

    Node(char x) : data(x), next(nullptr) {}
};

class Solution {
  public:
    int compare(Node *head1, Node *head2) {
        Node *temp1 = head1;
        Node *temp2 = head2;

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->data != temp2->data) {
                return (temp1->data > temp2->data) ? 1 : -1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 == nullptr && temp2 == nullptr)
            return 0;
        return (temp1 != nullptr) ? 1 : -1;
    }
};

Node *buildList(const string &s) {
    Node *head = nullptr;
    Node *tail = nullptr;
    for (char ch : s) {
        Node *node = new Node(ch);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void freeList(Node *head) {
    while (head != nullptr) {
        Node *next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    vector<pair<string, string>> tests = {
        {"abc", "abc"},
        {"abc", "abd"},
        {"abcd", "abc"},
        {"abc", "abcd"},
        {"", ""},
        {"", "a"},
        {"b", "a"}
    };

    Solution solution;
    cout << "Compare linked-list strings:\n";
    for (auto &test : tests) {
        Node *head1 = buildList(test.first);
        Node *head2 = buildList(test.second);
        int result = solution.compare(head1, head2);
        cout << "compare(\"" << test.first << "\", \"" << test.second << "\") = " << result << '\n';
        freeList(head1);
        freeList(head2);
    }

    return 0;
}
