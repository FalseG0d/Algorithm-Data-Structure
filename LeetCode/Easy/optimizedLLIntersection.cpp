class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 =0;
        int l2=0;

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        while(headA!=NULL)
        {
            l1++;
            headA = headA->next;
        }
        
        while(headB!=NULL)
        {
            l2++;
            headB = headB->next;
        }
        
        headA = temp1;
        headB = temp2;
        
        if(l1>l2)
        {
            int space =  l1-l2;
            while(space)
            {
                headA=headA->next;
                space--;
            }
        }
        else if(l1<l2)
        {
            int space = l2-l1;
            while(space)
            {
                headB = headB->next;
                space--;
            }
        }
        
        while(headA!=NULL && headB!=NULL)
        {
            if(headA==headB)
                return headA;
                
            headA = headA->next;
            headB = headB->next;
        }
            return NULL;
    }
};
