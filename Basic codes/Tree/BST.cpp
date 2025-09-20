#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* root = NULL;
void BST_insert(int val)
{
    node* temp;
    temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL){
        root = temp;
    }
    else
    {
        node *curr_node = root;
        node *prev_node = root;
        while(curr_node != NULL)
        {
            prev_node = curr_node;
            if(curr_node -> data > val)
            {
                curr_node = curr_node -> left;
            }
            else
            {
                curr_node = curr_node -> right;
            }
        }
        if(prev_node -> data > val) prev_node -> left = temp;
        else prev_node -> right = temp;
    }
}

void PreOrder(node *temp)
{
    if(temp != NULL)
    {
        cout << temp->data << " ";
        PreOrder(temp->left);
        PreOrder(temp->right);
    }
}

void inOrder(node *temp)
{
    if(temp!=NULL)
    {
        inOrder(temp->left);
        cout << temp->data << " ";
        inOrder(temp->right);
    }
}

void postOrder(node *temp)
{
    if(temp!=NULL)
    {
        postOrder(temp->right);
        postOrder(temp->left);
        cout << temp->data << " ";
    }
}

/*
9
9 5 15 2 6 1 3 7 4
*/

int main()
{
    int n, x;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        BST_insert(x);
    }
    PreOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    return 0;
}
