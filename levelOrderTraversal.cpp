#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    // calling the Constructor
    node(int value)
    {

        this->data = value;
        left = NULL;
        right = NULL;
    }
};

void levelOrder(node *root)
{

    if (root == NULL)
    {

        return;
    }

    queue<node*> q;
    q.push(root); // pushing 1 into the queue
    q.push(NULL); // pushing NULL into the queue so that we can make a group of left and right child of  same level

    while (!q.empty())
    {

        node *mack = q.front();

        q.pop();

        if (mack != NULL)
        {

            cout << mack->data << " ";

            if (mack->left)
            {

                q.push(mack->left);
            }

            if (mack->right)
            {

                q.push(mack->right);
            }
        }

        else if (!q.empty())
        {

            q.push(NULL);
        }
    }
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

    levelOrder(root);

    return 0;
}