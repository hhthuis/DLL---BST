#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* sortedListToBST(Node*& head, int n) {
    
    if (n <= 0) return nullptr;

    Node* left = sortedListToBST(head, n / 2);
    Node* root = new Node(head->data);
    root->left = left;
    head = head->right;
    root->right = sortedListToBST(head, n - n / 2 - 1);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);  
    cout << root->data << " ";  
    inorder(root->right);  
}

int main() {
    // 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> 10 -> 13 -> 14
    Node* head = new Node(1);
    head->right = new Node(3);
    head->right->right = new Node(4);
    head->right->right->right = new Node(6);
    head->right->right->right->right = new Node(7);
    head->right->right->right->right->right = new Node(8);
    head->right->right->right->right->right->right = new Node(10);
    head->right->right->right->right->right->right->right = new Node(13);
    head->right->right->right->right->right->right->right->right = new Node(14);

    Node* temp = head;
    int n = 0;
    while (temp != nullptr) {
        n++;
        temp = temp->right;
    }

    Node* root = sortedListToBST(head, n);
    inorder(root);
    cout << endl;

    return 0;
}
