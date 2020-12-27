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

bool is_Sub_Tree_Lesser(BstNode*root,int data){
	if(root==NULL){
		return true;
	}
	
	if(data>=root->data&&is_Sub_Tree_Lesser(root->left,data)&&is_Sub_Tree_Lesser(root->right,data)){
		return true;
	}
	
	return false;
}

bool is_Sub_Tree_Greater(BstNode*root,int data){
	if(root==NULL){
		return true;
	}
	
	if(data<=root->data&&is_Sub_Tree_Greater(root->left,data)&&is_Sub_Tree_Greater(root->right,data)){
		return true;
	}
	
	return false;
}

bool is_Binary_Tree(BstNode*root){
    if(root==NULL){
        return true;
    }
    
	if(is_Sub_Tree_Greater(root->right,root->data)&&is_Sub_Tree_Lesser(root->left,root->data)&&is_Binary_Tree(root->left)&&is_Binary_Tree(root->right)){
		return true;
	}else{
		return false;
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
	
	if(is_Binary_Tree(root)){
		cout<<"Is Binary Tree";
	}else{
		cout<<"Not A Binary Tree";
	}
	
	return 0;
}