node *bubble_sort_LinkedList_itr(node *head){
    //swapping will always be of adjacent elements
    int n=length(head);
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        node *curr=head,*prev=NULL;
        while(curr->next!=NULL){
            if(curr->data<=curr->next->data){
                prev=curr;
                curr=curr->next;
            }
            else{
                if(prev==NULL){
                    //element to be swap is 0th index
                    node *agla=head->next;
                    curr->next=agla->next;
                    agla->next=curr;
                    prev=agla;
                    head=agla;
                }
                else{
                    node *agla=curr->next;
                    prev->next=agla;
                    curr->next=agla->next;
                    agla->next=curr;
                    prev=prev->next;
                }
            }
        }
    }
    return head;
}
