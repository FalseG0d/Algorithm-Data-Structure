// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node*res=NULL;
        
        Node*itr1=head;
        Node*itr2=res;
        
        int temp;
        
        while(itr1!=NULL){
            temp=itr1->data;
            
            if(temp%2==0){
                if(res==NULL){
                    res=itr2=new Node(temp);
                }else{
                    itr2->next=new Node(temp);
                    itr2=itr2->next;
                }
            }
            
            itr1=itr1->next;
        }
        
        itr1=head;
        
        while(itr1!=NULL){
            temp=itr1->data;
            
            if(temp%2!=0){
                if(res==NULL){
                    res=itr2=new Node(temp);
                }else{
                    itr2->next=new Node(temp);
                    itr2=itr2->next;
                }
            }
            
            itr1=itr1->next;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends