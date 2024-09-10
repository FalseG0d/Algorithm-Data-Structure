Node* oddEvenList(Node* head)
{
	// Write your code here.
    Node*odd = NULL;
    Node*eve = NULL;

    Node*lastOdd = NULL;
    Node*lastEve = NULL;

    int pos = 0;
    Node* itr = head;

    while(itr) {
        Node*next = itr->next;
        if(pos % 2 == 0) {
            if(!odd) {
                lastOdd = odd = itr;
                odd->next = NULL;
            } else {
                lastOdd->next = itr;
                lastOdd = lastOdd->next;
                lastOdd->next = NULL;
            }
        } else {
            if(!eve) {
                lastEve = eve = itr;
                eve->next = NULL;
            } else {
                lastEve->next = itr;
                lastEve = lastEve->next;
                lastEve->next = NULL;
            }
        }

        pos++;
        itr = next;
    }

    lastOdd->next = eve;

    return odd;
}