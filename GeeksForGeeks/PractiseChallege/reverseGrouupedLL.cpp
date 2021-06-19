struct node *reverse (struct node *head, int k)
{

int c=0;
struct node *parso=NULL;
struct node *aaj=head;
struct node *kal=NULL;

while(aaj!=NULL && c<k) {="" kal="aaj-">next;
aaj->next=parso;
parso=aaj;
aaj=kal;

c++;

}

if(kal!=NULL)
{

head->next=reverse(kal, k);

}

return parso;
}