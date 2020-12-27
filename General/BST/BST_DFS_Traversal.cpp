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

void dfs_Traversal_Pre_Order(BstNode*root){
	//Value in Data Printed Before The Sub Trees
	if(root==NULL){
		return;
	}
	
	cout<<root->data<<"\t";
	
	dfs_Traversal_Pre_Order(root->left);
	dfs_Traversal_Pre_Order(root->right);
}

void dfs_Traversal_Post_Order(BstNode*root){
	//Value in Data Printed After The Sub Trees
	if(root==NULL){
		return;
	}
	
	dfs_Traversal_Post_Order(root->left);
	dfs_Traversal_Post_Order(root->right);
	
    cout<<root->data<<"\t";
}

void dfs_Traversal_In_Order(BstNode*root){
	//Value in Data Printed Between The Sub Trees
	if(root==NULL){
		return;
	}
	
	dfs_Traversal_In_Order(root->left);

	cout<<root->data<<"\t";
	
    dfs_Traversal_In_Order(root->right);
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

int main(){
	BstNode*root=NULL;
	root=insert(root,15);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,10);
	root=insert(root,40);
	root=insert(root,35);
	
    cout<<"In Order Traversal:\n";
	dfs_Traversal_In_Order(root);
	
    cout<<"\nPre Order Traversal:\n";
	dfs_Traversal_Pre_Order(root);
	
    cout<<"\nPost Order Traversal:\n";
	dfs_Traversal_Post_Order(root);
	
	return 0;
}