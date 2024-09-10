Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(k == 1) return head;
    
    Node*itr = head;
    Node*last = head;

    while(itr) {
        Node*prev = NULL;
        Node*next = NULL;
        Node*start = itr;

        bool rev = false;

        for(int i=0;i<k;i++) {
            if(!itr) {
                rev = true;
                break;
            }

            next = itr->next;
            
            itr->next = prev;
            prev = itr;
            itr = next;
        }

        if(rev) {
            itr = prev;
            prev = NULL;

            while(itr) {
                Node*next = itr->next;

                itr->next = prev;
                prev = itr;
                itr = next;
            }
        }

        if(last == head) {
            last = head;
            head = prev;
        }
        else {
            last->next = prev;
            last = start;
        }
    }

    return head;
}