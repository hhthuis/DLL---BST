#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node (int x) {
        data = x;
        left = nullptr;
      	right = nullptr;
    }
};

void inorder(Node* root) 
{
    if (root->left) {

        Node* pred  = root->left;
        while (pred->right){
            pred = pred->right;
        }
        
        inorder(root->left);
        
        pred->right = root;
        root->left = pred;
    }
    
    if (root->right) {
        
        Node* succ = root->right;
        while (succ->left) {
            succ = succ->left;
        }
        
        inorder(root->right);
        
        root->right = succ;
        succ->left = root;
    }
}

Node* bToDLL(Node* root) {
    
    if (root == nullptr) return root;
    
    Node* head = root;
    while (head->left != nullptr) 
        head = head->left;
        
    inorder(root);
    
    return head;
}

void printList(Node* head){
    Node* curr = head;
    
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout<<endl;
}

int main() {
    //          8
    //         /  \
    //       3    10    
    //      / \     \
    //     1   6    14
    //        / \    /
    //        4  7  13   
    Node* root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right= new Node(7);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Node* head = bToDLL(root);

    printList(head);

    return 0;
}
