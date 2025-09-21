#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* root = NULL;

node* successor(node* root, node* x) {
    // Case 1: right subtree exists
    if (x->right) {
        node* temp = x->right;
        while (temp->left) temp = temp->left;
        return temp;
    }

    // Case 2: no right child → go up to ancestors
    node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;         // potential successor
            root = root->left;
        } else if (x->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

node* predecessor(node* root, node* x) {
    // Case 1: left subtree exists
    if (x->left) {
        node* temp = x->left;
        while (temp->right) temp = temp->right;
        return temp;
    }

    // Case 2: no left child → go up to ancestors
    node* pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;         // potential predecessor
            root = root->right;
        } else if (x->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}


int main(){
    return 0;
}