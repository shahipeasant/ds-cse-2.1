#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;
void BST_insert(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *curr_node = root;
        node *prev_node = root;
        while (curr_node != NULL)
        {
            prev_node = curr_node;
            if (val < curr_node->data)
            {
                curr_node = curr_node->left;
            }
            else
            {
                curr_node = curr_node->right;
            }
        }
        if (val < prev_node->data)
        {
            prev_node->left = temp;
        }
        else
        {
            prev_node->right = temp;
        }
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

void BST_delete(int val)
{
    node *prev_node = root;
    node *curr_node = root;
    while (curr_node != NULL)
    {
        if (val == curr_node->data)
        {
            break;
        }
        prev_node = curr_node;
        if (val < curr_node->data)
        {
            curr_node = curr_node->left;
        }
        else if (val > curr_node->data)
        {
            curr_node = curr_node->right;
        }
    }
    if (curr_node == NULL)
    {
        return;
    }
    else
    {
        if ((curr_node->left == NULL) && (curr_node->right == NULL))
        {
            if (prev_node->left == curr_node)
            {
                prev_node->left = NULL;
            }
            else if (prev_node->right == curr_node)
            {
                prev_node->right = NULL;
            }
        }
        else if (curr_node->left == NULL || curr_node->right == NULL)
        {
            node *child;
            if (curr_node->left == NULL)
            {
                child = curr_node->right;
            }
            else
            {
                child = curr_node->left;
            }
            if (prev_node->left == curr_node)
                prev_node->left = child;
            else
                prev_node->right = child;
        }
        else
        {
            node *temp = curr_node;
            prev_node = curr_node;
            curr_node = curr_node->right;
            while (curr_node->left != NULL)
            {
                prev_node = curr_node;

                curr_node = curr_node->left;
            }
            temp->data = curr_node->data;
            if (prev_node->left == curr_node)
                prev_node->left = curr_node->right;
            else
                prev_node->right = curr_node->right;
        }
    }
}

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
    BST_delete(6);
    PreOrder(root);
    return 0;
}
