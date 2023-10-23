#include<bits/stdc++.h>
using namespace std;

class Node{

public:
int data;
Node* right; // this is the pointer which is pointing to the right of the node
Node* left;  // this is the pointer which is pointing to the left of the node

Node(int d){

this->data = d;
this->left = NULL;
this->right = NULL;


}


};


Node* buildTree(Node* root){

cout<<"Enter the value of data :"<<endl;
int data;
cin>>data;

root = new Node(data); // by using this constructor ki saari value call ho jainge

if(data == -1){

return NULL;

}

// Now Basically we will use recursion

cout<<"Enter data for inserting at the left :"<<endl;

root->left = buildTree(root->left);

cout<<"Enter data for inserting at the right :"<<endl;

root->right = buildTree(root->right);

return root;


}


int main(){


Node* root = NULL;

root = buildTree(root);







return 0;

}