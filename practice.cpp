#include<bits/stdc++.h>
using namespace std;

class node{


public:

int data;
node* left;
node* right;

// calling out a constructor

node(int value){

this->data = value;
left = NULL;
right = NULL;


}


};

int search(int inorder[] , int start ,  int end , int curr){


for(int i = start ; i<=end ; i++){

if(inorder[i] == curr){


return i;


}




}

return -1;


}









node* buildTree(int preorder[] , int inorder[] , int start , int end){

static int index = 0;

// base case

if(start>end){


return NULL;


}






int curr = preorder[index];





index++;

node *mack = new node(curr);



if(start == end){

return mack;


}



int pos = search(inorder , start ,  end , curr);

// now we will call the recursive function


mack->left = buildTree(preorder , inorder , start ,  pos-1);
mack->right = buildTree(preorder , inorder , pos+1 ,  end);

return mack;



}

void printInorder(node* root){

if(root == NULL){

return ;

}

printInorder(root->left);
cout << root->data << " ";
printInorder(root->right);



}



int main(){

int preorder[] = {1,2,4,3,5};
int inorder[] =  {4,2,1,5,3};

node* root = buildTree(preorder , inorder , 0 , 4);
printInorder(root);



return 0;
    
}