// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector<int>res;
    
    void inorder(Node* root)
    {    if(!root)
    return;
        inorder(root->left);
        if(!root->left && !root->right)
        res.push_back(root->data);
        inorder(root->right);
    }
    void printLeft(Node* ptr)
    {
        while(ptr)
      {    if(ptr->left || ptr->right)
          res.push_back(ptr->data);
          if(ptr->left)
          ptr=ptr->left;
          else{
          ptr=ptr->right;
          }
      }
    }
    void printRight(Node* ptr)
    {
        stack<int> s;
      while(ptr)
      {
          if(ptr->left || ptr->right)
          s.push(ptr->data);
          if(ptr->right)
          ptr=ptr->right;
          else 
          ptr = ptr->left;
      }
      while(!s.empty())
      {
          res.push_back(s.top());
          s.pop();
      }
    }
    vector<int> printBoundary(Node *root)
    { 
      res.push_back(root->data);
      
      printLeft(root->left);
      inorder(root);
      printRight(root->right);
      
      return res;
      
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends