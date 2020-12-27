#include<bits/stdc++.h>

using namespace std;

struct BstNode{
	int data;
	BstNode*left;
	BstNode*right;
};

BstNode*GetNewNode(int data){
	BstNode*newNode=new BstNode();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	
	return newNode;
}

BstNode* search(BstNode*root,int data){
	if(root==NULL){
		return NULL;
	}
	
	if(root->data==data){
		return root;
	}else if(root->data>data){
		return search(root->left,data);
	}else{
		return search(root->right,data);
	}
}

BstNode* insert(BstNode*root,int data){
	if(root==NULL){
		root=GetNewNode(data);
	}else if(data<=root->data){
		root->left=insert(root->left,data);
	}else{
		root->right=insert(root->right,data);
	}
	
	return root;
}


BstNode*findMin(BstNode*root){
	if(root->left==NULL){
		return root;
	}else{
		return findMin(root->left);
	}
}

BstNode*getSuccessor(BstNode*root,int data){
	BstNode*current=search(root,data);
	
	if(current==NULL){
		return NULL;
	}
	
	if(current->right!=NULL){
		//Case 1. A Right Sub Tree is Available
		return findMin(current->right);
	}else{
		//Case 2. A Right Sub Tree is Not Available
		//We Will have to go up a level untill we find a Node that is Not Visited
		
		BstNode*successor=NULL;
		BstNode*ancestor=root;
		
		while(ancestor!=current){
			if(current->data<ancestor->data){
				successor=ancestor;
				ancestor=ancestor->left;
			}else{
				ancestor=ancestor->right;
			}
		}
		return ancestor;
	}
}

int main(){
	BstNode*root=NULL;
	root=insert(root,15);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,10);
	root=insert(root,40);
	root=insert(root,35);
	
	cout<<"In Order Successor:\t"<<getSuccessor(root,20)->data;
	
	return 0;
}