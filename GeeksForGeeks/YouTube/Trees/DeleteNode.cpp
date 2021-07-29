# include <iostream>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
};

int minEleToRight(struct Node*root);
// Min Element in a BST is returned

struct Node*Delete(struct Node*root, int data){
    if(root==NULL) return NULL;
    else if(data < root->data) root->left=Delete(root->left,data);
    else if(data > root->data) root->right=Delete(root->right,data);

    else{
        if(root->left == NULL && root->right == NULL){
            // Case 1: Leaf Node
            delete root;
            root=NULL;
        }
        // Case 2: Only One Child
        else if(root->left == NULL){
            struct Node*temp=root;
            root=root->right;
            delete temp;
        }else if(root->right == NULL){
            struct Node*temp=root;
            root=root->left;
            delete temp;
        }
        // Case 3: 2 Children
        else{
            int min=minEleToRight(root->right);
            root->data=min;

            root->right=Delete(root->right,min);
        }
    }

    return root;    
}