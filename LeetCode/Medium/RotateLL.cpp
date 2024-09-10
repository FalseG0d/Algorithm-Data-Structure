/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(k == 0) return head;

     Node*prev = NULL;
     Node*curr = head;

     int size = 0;

     while(curr) {
          Node*next = curr->next;

          curr->next = prev;
          prev = curr;
          curr = next;
          size++;
     }

     if(size < k) k %= size;
     if(k == 0) k = size;

     head = curr = prev;
     prev = NULL;

     for (int i = 0; i < k; i++) {
          Node*next = curr->next;

          curr->next = prev;
          prev = curr;
          curr = next;
     }

     if(size == k) return prev;

     Node*res = prev;
     prev = NULL;

     while(curr) {
          Node*next = curr->next;

          curr->next = prev;
          prev = curr;
          curr = next;
     }

     head->next = prev;

     return res;
}