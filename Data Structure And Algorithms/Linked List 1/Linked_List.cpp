#include<bits/stdc++.h>
using namespace std;
#include"Node.cpp"
/*
class Node{
public:
  int data;
  Node *next;
  Node(int data){
    this->data=data;
    this->next=NULL;
  }
};
*/
Node *input1(){
  //O(n^2)
  //taking -1 as delimeter
  int data;
  cin>>data;
  Node *head=NULL;
  while(data!=-1){
    Node *newNode=new Node(data);
    if(head==NULL){
      head=newNode;
    }
    else{
      Node *temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=newNode;
    }
    cin>>data;
  }
  return head;
}
Node *input2(){
  //O(n)
  int data;
  cin>>data;
  Node *head=NULL;
  Node *tail=NULL;
  while(data!=-1){
    Node *newNode=new Node(data);
    if(head==NULL){
      head=newNode;
      tail=newNode;
    }
    else{
      tail->next=newNode;
      tail=newNode;
    }
    cin>>data;
  }
  return head;
}
Node* insertNode(Node *head,int data,int i){
  Node *newNode=new Node(data);
  //if index is 0
  if(i==0){
    newNode->next=head;
    head=newNode;
  }
  Node *temp=head;
  int count=0;
  while(temp!=NULL && count<i-1){
    temp=temp->next;
    count++;
  }
  if(temp!=NULL){
  Node *a=temp->next;
  temp->next=newNode;
  newNode->next=a;
  }
  return head;
}
Node *deleteNode(Node *head,int i){
  Node *temp=head;
  if(i==0){
    head=head->next;
    delete temp;
    return head;
  }
  else{
    int count=0;
    while(count<i-1 && temp!=NULL){
      count++;
      temp=temp->next;
    }
    if(temp!=NULL && temp->next!=NULL){
      Node *a=temp->next;
      Node *b=a->next;
      temp->next=b;
      delete a;
    }
    return head;
  }
}

void print(Node *head){
  //different head from main memory
  Node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
int length_recursive(Node *head){
  if(head==NULL){return 0;}
  int ans=1+length_recursive(head->next);
  return ans;
}

Node* insertNodeRec(Node *head, int i, int data) {
 Node *temp=head;
    if(i>length_recursive(head)){
        return head;
    }
    if(temp==NULL){
        if(i==0){
            Node *newNode=new Node(data);
            return newNode;
        }
        return temp;
    //as we can't add anything now
    }
  if(i==0){
      Node *x=new Node(data);
      x->next=temp;
      head=x;
      return head;
  }
  //recursive work
   else{
       Node *head_recursive=insertNodeRec(temp->next,i-1,data);
       temp->next=head_recursive;
       return head;
   }
}
Node *reverseLL(Node *head){
  if(head==NULL || head->next==NULL){return head;}
  Node *smallnode=reverseLL(head->next);
  head->next->next=head;
  head->next=NULL;
  return smallnode;
}
int size(Node *head){
    if(head==NULL){return 0;}
    int ans=1+size(head->next);
    return ans;
}
bool isPalindrome(Node *head){
   if(head==NULL || head->next==NULL){
        return true;
    }
  int count=size(head);
  int mid=(count%2==0)?(count-1)/2:(count+1)/2;//for handling even length
  int i=0;
  Node *h2=head,*h1=head;
  while(i<=mid){
  h2=h2->next;
  i++;
  }
  int j=0;
  Node *t1=head;
  while(j<mid){
  t1=t1->next;
  j++;
  }
  t1->next=NULL;
 // cout<<count<<" "<<mid<<" "<<h2->data<<" "<<t1->data<<endl;
  h2=reverseLL(h2);
  while(h2!=NULL && h1!=NULL){
    if(h2->data!=h1->data){
      return false;
    }
    else{
      h1=h1->next;
      h2=h2->next;
    }
  }
  return true;
}

int main(){
  //static allocation
  /*Node n1(1);
  Node *head=&n1;
  Node n2(2);

  n1.next=&n2;
  cout<<n1.data<<" "<<n2.data<<endl;
  cout<<head->data<<endl;
  //cout<<head->next->data<<endl;
  //dynamically
  Node *n3=new Node(10);
  Node *n4=new Node(20);
  n3->next=n4;
  Node* head2=n3;

  Node n3(3);
  Node n4(4);
  Node n5(5);
  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n4;
  n4.next=&n5;
  print(head);
  cout<<endl;
  //dynamic allocation
  Node *n11=new Node(1);
  Node *n22=new Node(2);
  Node *n33=new Node(3);
  n11->next=n22;
  n22->next=n33;
  head=n11;*/
  //print(input1());
  // Node *head=input2();
  // print(head);
  // int i,data;
  // cin>>i>>data;
  // head=insertNode(head,data,i);
  // print(head);
  // head=deleteNode(head,2);
  // cout<<endl;
  // print(head);
  // cout<<endl;
  // cout<<length_recursive(head)<<endl;
  Node *head=input2();
  cout<<checkPalindrome(head)<<endl;
}
