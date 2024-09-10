/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    // Write your code here
    Node*slow = head;
    Node*fast = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) break;
    }

    if(fast == NULL) return 0;

    slow = slow->next;
    int len = 0;

    while(fast != slow) {
        slow = slow->next;
        len++;
    }

    return len+1;
}
