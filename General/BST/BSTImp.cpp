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

bool search(BstNode*root,int data){
	if(root==NULL){
		return false;
	}
	
	if(root->data==data){
		return true;
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


int findMax(BstNode*root){
    if(root==NULL){
        return -1;
    }
	if(root->right==NULL){
		return root->data;
	}else{
		return findMax(root->right);
	}
}

int findMin(BstNode*root){
    if(root==NULL){
        return -1;
    }
	if(root->left==NULL){
		return root->data;
	}else{
		return findMin(root->left);
	}
}

int findHeight(BstNode*root){
	if(root==NULL){
		return -1;
	}
	
	int l=findHeight(root->left);
	int r=findHeight(root->right);
	
	return l>r?l+1:r+1;
}

int main(){
	BstNode*root=NULL;
	root=insert(root,15);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,10);
	root=insert(root,40);
	root=insert(root,35);
	
	if(search(root,35)){
        cout<<"Found";
    }else{
        cout<<"Not Found";
    }
	
	cout<<"\nMax Element:\t"<<findMax(root);
	cout<<"\nMin Element:\t"<<findMin(root);
	
	cout<<"\nHeight of Tree:\t"<<findHeight(root);
	
	return 0;
}