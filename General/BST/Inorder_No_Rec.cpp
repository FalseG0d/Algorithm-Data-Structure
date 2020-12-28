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

void inorder_Traversal(BstNode*root){
	BstNode*current=root;
    stack<BstNode*> S;

    int done=0;

    while(!done){
        if(current!=NULL){
            S.push(current);
            current=current->left;
        }else{
            if(S.empty()){
                done=1;
            }
            else{
                current=S.top();
                S.pop();
                cout<<current->data<<"\t";
                current=current->right;
            }
        }
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
	
	inorder_Traversal(root);
	
	return 0;
}