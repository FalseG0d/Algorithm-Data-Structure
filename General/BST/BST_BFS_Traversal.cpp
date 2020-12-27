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

void bfs_Traversal(BstNode*root){
	//Also Called Level Order Traversal
	//Traversed Using a Queue
	
	if(root==NULL){
		return;
	}
	
	queue<BstNode*>Q;
	Q.push(root);
	
	while(!Q.empty()){
		BstNode*current=Q.front();
		cout<<current->data<<"\t";
		
		if(current->left!=NULL)Q.push(current->left);
		if(current->right!=NULL)Q.push(current->right);
		
		Q.pop();
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

int main(){
	BstNode*root=NULL;
	root=insert(root,15);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,10);
	root=insert(root,40);
	root=insert(root,35);
	
	bfs_Traversal(root);
	
	return 0;
}