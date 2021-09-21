//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
#include <iostream>
#include<bits/stdc++.h>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* arrange_LinkedList(node* head)
{
    node *oh=NULL,*ot=NULL,*eh=NULL,*et=NULL;
    node *curr=head;
    while(curr!=NULL){
      if((curr->data)&1){
        if(oh==NULL){
          oh=curr;
          ot=curr;
          curr=curr->next;
        }
        else{
          ot->next=curr;
          ot=curr;
          curr=curr->next;
        }
      }
      else{
        if(eh==NULL){
          eh=curr;
          et=curr;
          curr=curr->next;
         }
         else{
           et->next=curr;
           et=curr;
           curr=curr->next;
         }
      }
    }
    if(eh==NULL){return oh;}
    if(oh==NULL){return eh;}
    if(et!=NULL){et->next=NULL;}
    if(ot!=NULL){ot->next=eh;}
    return oh;
}

int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
