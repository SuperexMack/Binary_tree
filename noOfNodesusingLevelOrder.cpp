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

void sumofnodes(node *root)
{

    int count = 0;

    if (root == NULL)
    {

        return;
    }

    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *mack = q.front();
        q.pop();

        if (mack != NULL)
        {

            cout << mack->data << " ";

            count++;

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

    cout << endl;
    cout << count;
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
    root->right->right->right = new node(8);

    sumofnodes(root);

    return 0;
}