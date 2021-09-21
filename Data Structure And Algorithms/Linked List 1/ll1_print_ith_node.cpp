/**********
 * Following is the Node class that is already written.

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

*********/
int size(Node *head){
    int ans=0;
    while(head!=NULL){
        head=head->next;
        ans++;
    }
    return ans;
}
void printIthNode(Node *head, int index) {
    if(index>size(head)) return;
    int i=0;
    Node *temp=head;
    while(temp!=NULL && i!=index){
        temp=temp->next;
        i++;
    }
    cout<<temp->data;
}
#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
#include "Solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    printIthNode(head, pos);
    return 0;
}
