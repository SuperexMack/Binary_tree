#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    // Now Making a Constructor

    node(int data)
    {

        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int search(int inOrder[], int start, int end, int curr)
{

    for (int i = start; i <= end; i++)
    {

        if (inOrder[i] == curr)
        {

            return i;
        }
    }

    return -1;
}

node *buildTree(int preOrder[], int inOrder[], int start, int end)
{

    static int index = 0;

    if (start > end)
    {

        return NULL;
    }

    int curr = preOrder[index];
    index++;
    node *mack = new node(curr);

    //  special case

    if (start == end)
    {

        return mack;
    }

    int pos = search(inOrder, start, end, curr);

    mack->left = buildTree(preOrder, inOrder, start, pos - 1);
    mack->right = buildTree(preOrder, inOrder, pos + 1, end);

    return mack;
}

void inorderPrint(node *root)
{

    // using this we are calling the inorder

    if (root == NULL)
    {

        return;
    }

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{

    int preOrder[] = {1, 2, 4, 3, 5};
    int inOrder[] = {4, 2, 1, 5, 3};

    // build tree

    node *root = buildTree(preOrder, inOrder, 0, 4);

    inorderPrint(root);

    return 0;
}