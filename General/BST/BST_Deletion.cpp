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


BstNode*findMin(BstNode*root){
	if(root->left==NULL){
		return root;
	}else{
		return findMin(root->left);
	}
}

BstNode* delete_Node(BstNode*root,int data){
	if(root==NULL){
		//Terminating Condition
		return root;
	}
	
	if(root->data>data){
		root->left=delete_Node(root->left,data);
	}else if(root->data<data){
		root->right=delete_Node(root->right,data);
	}
	else{
		//Found The Element
		if(root->left==NULL&&root->right==NULL){
			//Case 1. The Node has No Children
			delete root;
			root=NULL;
		}else if(root->left==NULL){
			//Case 2. The Node has No Left Child
			BstNode*temp=root;
			root=root->right;
			
			delete temp;
		}else if(root->right==NULL){
			//Case 3. The Node has No Right Child
			BstNode*temp=root;
			root=root->left;
			
			delete temp;
		}else{
			//Case 4. The Tree has Children On Both Sides
			BstNode*temp=findMin(root->right);
			root->data=temp->data;
			
			delete temp;
		}
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
	
	cout<<"\nBefore Deletion:\n";
	if(search(root,35)){
        cout<<"Found The Element 35";
    }else{
        cout<<"Not Found The Element 35";
    }
	
	delete_Node(root,35);
	
	cout<<"\nAfter Deletion:\n";
	if(search(root,35)){
        cout<<"Found The Element 35";
    }else{
        cout<<"Not Found The Element 35";
    }
	
	return 0;
}