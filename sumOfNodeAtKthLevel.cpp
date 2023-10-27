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

int KthLevelSum(node *root, int k)
{

    if (root == NULL)
    {

        return -1;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty())
    {

        node *mack = q.front();
        q.pop();

        if (mack != NULL)
        {

            if (k == level)
            {

                sum = sum + mack->data;
            }

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
            level++;
        }
    }

    return sum;
}

int main()
{

    
    //  1
//     / \
//    2   5
//   /\  / \
//  3  4 6  7

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(8);

    cout << KthLevelSum(root, 2);

    return 0;
}