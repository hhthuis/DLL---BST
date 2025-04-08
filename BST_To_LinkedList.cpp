#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* bToDLL(Node* root) {
    Node* curr = root;
    Node* prev = nullptr; 
    Node* final_head = nullptr; 

    while (curr) {
        if (!curr->left) {
            if (!final_head) {
                prev = curr;
                final_head = curr;
            } else {
                prev->right = curr;
                curr->left = prev;
            }
            prev = curr;
            curr = curr->right;
        } else {
            Node* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = curr;
                curr = curr->left;
            } else {
                curr = pre->right;
                prev->right = curr;
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
        }
    }

    return final_head;
}

void print_dll(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->right;
    }
}

int main() {
    
     //       8
    //      / \
    //     5   15
    //    / \   \
    //   2  7   17
    //     /    /
    //    6    16
    Node* root= new Node(10);
    
    root->left= new Node(5);
    root->right=new Node(15);
    
    root->left->left=new Node(2);
    root->left->right=new Node(7);
    root->right->right=new Node(17);

    root->left->right->left=new Node(6);
    root->right->right->left=new Node(16);

    Node* head = bToDLL(root);

    print_dll(head);

    return 0;
}
