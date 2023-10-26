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

int heightOfNode(node *root)
{

    if (root == NULL)
    {

        return 0;
    }

    int Lheight = heightOfNode(root->left);
    int Rheight = heightOfNode(root->right);

    return max(Lheight, Rheight) + 1;
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

    cout << heightOfNode(root);

    return 0;
}