#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    // Calling an Constructor

    node(int value)
    {

        this->data = value;
        left = NULL;
        right = NULL;
    }
};

int findNumberOfNode(node *root)
{

    // now here we will perform the recursive function

    // special case
    if (root == NULL)
    {

        return 0;
    }

    return findNumberOfNode(root->left) + findNumberOfNode(root->left) + 1;
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << findNumberOfNode(root);

    return 0;
}
