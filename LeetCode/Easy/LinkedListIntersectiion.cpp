Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int len1 = 0;
    int len2 = 0;

    Node*itr1 = firstHead;
    Node*itr2 = secondHead;

    while(itr1 && itr2) {
        itr1 = itr1->next;
        itr2 = itr2->next;

        len1++;
        len2++;
    }

    while(itr1) {
        itr1 = itr1->next;
        
        len1++;
    }

    while(itr2) {
        itr2 = itr2->next;
        
        len2++;
    }

    itr1 = firstHead;
    itr2 = secondHead;

    if(len1 > len2) {
        for(int i=0;i<len1-len2;i++) itr1 = itr1->next;
    } else if(len2 > len1) {
        for(int i=0;i<len2-len1;i++) itr2 = itr2->next;
    }

    while(itr1 != itr2) {
        itr1 = itr1->next;
        itr2 = itr2->next;
    }

    return itr1;
}