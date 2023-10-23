#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    // making of constructor

    node(int data)
    {

        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// PreOrder printing of binary tree

void preorder(node *root)
{
    // here we will use recursion

    // base case

    if (root == NULL)
    {

        return;
    }

    // first we will print the root or the topmost parent

    cout << root->data << " ";

    // now we will call the left subtree

    preorder(root->left);

    // now we will call the right subtree

    preorder(root->right);
}

void Inorder(node *root)
{

    // base case

    if (root == NULL)
    {

        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void postorder(node *root)
{

    // base case

    if (root == NULL)
    {

        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(8);
    root->right->right = new node(9);

    /*


        1
       / \
      2   3
     / \  / \
    4   5 8  9

    */

    cout << "The Pre-order tree is :" << endl;
    preorder(root); // output will be  - 1 2 4 5 3 8 9

    cout << endl;

    cout << "The In-order tree is :" << endl;

    Inorder(root); // output will be  - 4 2 5 1  8 3 9

    cout << endl;

    cout << "The Post-order tree is :" << endl;

    postorder(root); // output will be  - 4 5 2 8 9 3 1

    return 0;
}
