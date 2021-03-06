#include<bits/stdc++.h> 
using namespace std; 

class Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
}; 

int max(int a, int b); 

int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

Node* newNode(int key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; 
    
	return(node); 
} 

Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	return x; 
} 

Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	return y; 
} 

int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

Node* insert(Node* node, int key) 
{ 
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = getBalance(node); 

    //Left Left
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

    //Right Right
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

    //Left Right
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

    //Right Left
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	return node; 
} 

void preOrder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->key << " ";
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

Node*inorder_successor(Node*r){
    Node*demo=r;
    while(demo->left!=NULL){
        demo=demo->left;
    }
    return demo;
}

Node*deleteNode(Node*r,int val){
    if(r==NULL){
        return r;
    }

    if(val<r->key){
        r->left=deleteNode(r->left,val);
    }else if(val>r->key){
        r->right=deleteNode(r->right,val);
    }else{
        if(r->left==NULL||r->right==NULL){
            Node*temp=r->left?r->left:r->right;

            if(temp==NULL){
                temp=r;
                r=NULL;
            }else{
                *r=*temp;
            }
            delete temp;
        }else{
            Node*temp=inorder_successor(r->right);
            r->key=temp->key;
            r->right=deleteNode(r->right,temp->key);
        }
    }
    if(r==NULL){
        return r;
    }

    r->height = 1 + max(height(r->left), 
						height(r->right)); 

	int balance = getBalance(r); 

    //Left Left
	if (balance > 1 && val < r->left->key) 
		return rightRotate(r); 

    //Right Right
	if (balance < -1 && val > r->right->key) 
		return leftRotate(r); 

    //Left Right
	if (balance > 1 && val > r->left->key) 
	{ 
		r->left = leftRotate(r->left); 
		return rightRotate(r); 
	} 

    //Right Left
	if (balance < -1 && val < r->right->key) 
	{ 
		r->right = rightRotate(r->right); 
		return leftRotate(r); 
	} 

	return r;
}

int main() 
{ 
	Node *root = NULL; 
	
	root = insert(root, 10); 
	root = insert(root, 20); 
	root = insert(root, 30); 
	root = insert(root, 40); 
	root = insert(root, 50); 
	root = insert(root, 25); 

	cout << "\nPreorder Traversal\n"; 
	preOrder(root);
    root=deleteNode(root,20);
	cout << "\nPreorder Traversal\n"; 
	preOrder(root); 
	
	return 0; 
}