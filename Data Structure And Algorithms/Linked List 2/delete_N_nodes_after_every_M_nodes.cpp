class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* skipMdeleteN(node  *head, int M, int N) {
    node *curr=head;
    node *temp=NULL;
    while(curr!=NULL){
        int c1=0;
        while(curr!=NULL && c1<M-1){
            c1++;
            curr=curr->next;
        }
        temp=curr;
        int c2=0;
        while(curr!=NULL && c2<=N){
            curr=curr->next;
            c2++;
        }
        if(curr!=NULL){
        temp->next=curr;
        }
    }
    if(temp!=NULL){
        temp->next=NULL;
    }
   return head;
}
