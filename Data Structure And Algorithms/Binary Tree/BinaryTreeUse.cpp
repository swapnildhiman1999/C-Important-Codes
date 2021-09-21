#include<bits/stdc++.h>
using namespace std;
#include"BinaryTreeNode.h"
BinaryTreeNode<int>* takeInput(){
  int rootData;
  cin>>rootData;
  if(rootData==-1){return NULL;}
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
  BinaryTreeNode<int>* leftchild=takeInput();
  BinaryTreeNode<int>* rightchild=takeInput();
  root->left=leftchild;
  root->right=rightchild;
  return root;
}
BinaryTreeNode<int>* takeInputLevelWise(){
  int rootData;
  cout<<"enter root Data"<<endl;
  cin>>rootData;
  if(rootData==-1){return NULL;}
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(!pendingNodes.empty()){
    BinaryTreeNode<int>* front=pendingNodes.front();
    pendingNodes.pop();
    int leftchild;
    cout<<"enter left child data of "<<front->data<<endl;
    cin>>leftchild;
    if(leftchild!=-1){
      BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftchild);
      front->left=child;
      pendingNodes.push(child);
    }
    int rightchild;
    cout<<"enter right child data of "<<front->data<<endl;
    cin>>rightchild;
    if(rightchild!=-1){
      BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightchild);
      front->right=child;
      pendingNodes.push(child);
    }
  }
  return root;
}
void printTree(BinaryTreeNode<int>* root){
 if(root==NULL){return;}
  cout<<root->data<<":";
  if(root->left){
    cout<<"L"<<root->left->data;
  }
  if(root->right){
    cout<<"R"<<root->right->data;
  }
  cout<<endl;
  printTree(root->left);
  printTree(root->right);
}

#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) {
   if(root==NULL){return;}
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while(!pn.empty()){
        BinaryTreeNode<int>* front=pn.front();
        pn.pop();
        cout<<front->data<<":";
        if(front->left==NULL){
            cout<<"L:-1,";
        }
        else{
            cout<<"L:"<<front->left->data<<",";
            pn.push(front->left);
        }
        if(front->right==NULL){
            cout<<"R:-1"<<endl;
        }
        else{
            cout<<"R:"<<front->right->data<<endl;
            pn.push(front->right);
        }
    }
}
int countNodes(BinaryTreeNode<int>* root){
  if(root==NULL){return 0;}
  return 1+countNodes(root->left)+countNodes(root->right);
}
int height(BinaryTreeNode<int> *root) {
   if(root==NULL){return 0;}
  //if(root->left==NULL && root->right==NULL){return 1;}
   return 1+max(height(root->left),height(root->right));
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
  if(root==NULL){return;}
   BinaryTreeNode<int> *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
void Inorder(BinaryTreeNode<int>* root){
  if(root==NULL){return;}
  Inorder(root->left);
  cout<<root->data<<" ";
  Inorder(root->right);
}

void preOrder(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return;
    }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
   if(root==NULL){return false;}
   if(root->data==x){return true;}
   bool ans=isNodePresent(root->left,x) || isNodePresent(root->right,x);
   return ans;
}

BinaryTreeNode<int> *helper(int *preorder,int *inorder,int pos,int poe,int ins,int ine){
  if(pos>poe || ins>ine){return NULL;}
  int rootData=preorder[pos];
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
  //root index in inorder
  int root_index=-1;
  for(int i=ins;i<=ine;++i){
    if(inorder[i]==rootData){
      root_index=i;
      break;
    }
  }
  int lins=ins,line=root_index-1,lpos=pos+1,lpoe=line-lins+lpos;
  root->left=helper(preorder,inorder,lpos,lpoe,lins,line);
  int rpos=lpoe+1,rpoe=poe,rins=root_index+1,rine=ine;
  root->right=helper(preorder,inorder,rpos,rpoe,rins,rine);
  return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
//building binary tree from preorder and inorder
  return helper(preorder,inorder,0,preLength-1,0,inLength-1);
}

BinaryTreeNode<int> *getTreeFromPostorderAndInorderHelper(int *postorder,int* inorder,int pos,int poe,int ins,int ine){
  if(pos>poe || ins>ine){return NULL;}
  int rootData=postorder[poe];
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
  int root_index=-1;
  for(int i=ins;i<=ine;++i){
    if(inorder[i]==rootData){
      root_index=i;
      break;
    }
  }
  int lins=ins,line=root_index-1,lpos=pos,lpoe=(root_index-1)-lins+lpos;
  root->left=getTreeFromPostorderAndInorderHelper(postorder,inorder,lpos,lpoe,lins,line);
  int rins=root_index+1,rine=ine,rpos=lpoe+1,rpoe=poe-1;
  root->right=getTreeFromPostorderAndInorderHelper(postorder,inorder,rpos,rpoe,rins,rine);
  return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
  return    getTreeFromPostorderAndInorderHelper(postorder,inorder,0,postLength-1,0,inLength-1);
}

pair<int,int> heightDiameter(BinaryTreeNode<int> *root){
//gives overall height and diamete of the tree
 if(root==NULL){
  pair<int,int> p=make_pair(0,0);
  return p;
  }
  pair<int,int> lAns=heightDiameter(root->left);
  pair<int,int> rAns=heightDiameter(root->right);
  pair<int,int> p;
  p.first=1+max(lAns.first,rAns.first);
  p.second=max(lAns.first+rAns.first,max(lAns.second,rAns.second));
  return p;
}
class PairAns {
    public :
        int min;
        int max;
 };
PairAns minMax(BinaryTreeNode<int> *root) {
   if(root==NULL){
     PairAns p;
     p.min=INT_MAX;
     p.max=INT_MIN;
     return p;
   }
  PairAns lAns=minMax(root->left);
  PairAns rAns=minMax(root->right);
  PairAns p;
  p.min=min(root->data,min(lAns.min,rAns.min));
  p.max=max(root->data,max(lAns.max,rAns.max));
  return p;
}
bool isBalanced(BinaryTreeNode<int> *root) {
    if(root==NULL)
    {return true;}
    bool lAns=isBalanced(root->left);
    bool rAns=isBalanced(root->right);
    int val=abs(height(root->left)-height(root->right));
    if(lAns && rAns && val<=1){
        return true;
    }
    return false;
}

class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
     if(root==NULL){
       vector<node<int>*> v;
       node<int>* a=NULL;
       v.pb(a);
       return v;
     }
    vector<node<int>*> v;
     queue<BinaryTreeNode<int>*> pendingNodes;
     pendingNodes.push(root);
     while(!pendingNodes.empty()){
       node<int> *head=NULL,*tail=NULL;
       int n=pendingNodes.size();
         while(n>0){
         BinaryTreeNode<int>* front=pendingNodes.front();
         pendingNodes.pop();
         int val=front->data;
         node<int> *point=new node<int>(val);
         if(head==NULL){
           head=point;
           tail=point;
         }
         else{
           tail->next=point;
             tail=point;
         }
         if(front->left!=NULL){pendingNodes.push(front->left);}
         if(front->right!=NULL){pendingNodes.push(front->right);}
         n--;
       }
       v.pb(head);
     }
     return v;
}

#include<queue>
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
   if(root==NULL){
       return ;
   }
  //  BinaryTreeNode<int>* rootData=new BinayTreeNode<int>(root->data);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
 while(!q.empty()){
     int nc=q.size();
     while(nc>0){
         BinaryTreeNode<int>* curr=q.front();
         cout<<curr->data<<" ";
         if(curr->left!=NULL){q.push(curr->left);}
         if(curr->right!=NULL){q.push(curr->right);}
         q.pop();
         nc--;
     }
     cout<<endl;
  }
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
   if(root==NULL){return NULL;}
   if(root->left!=NULL){
     if(root->left->left==NULL && root->left->right==NULL){
       root->left=NULL;
     }
   }
   if(root->right!=NULL){
     if(root->right->left==NULL && root->right->right==NULL){root->right=NULL;}
   }
   BinaryTreeNode<int>* lc=removeLeafNodes(root->left);
   BinaryTreeNode<int>* rc=removeLeafNodes(root->right);
   return root;
}

void zigZagOrder(BinaryTreeNode<int> *root) {
   stack<BinaryTreeNode<int>*> s1;
   stack<BinaryTreeNode<int>*> s2;
   if(root==NULL){return;}
   int n=countNodes(root);
   s1.push(root);
   int count=0;
   while(count<n){
     while(!s1.empty()){
       BinaryTreeNode<int> *top=s1.top();
       s1.pop();
       cout<<top->data<<" ";
       count++;
       if(top->left!=NULL){
         s2.push(top->left);
       }
       if(top->right!=NULL){
         s2.push(top->right);
       }
     }
     cout<<endl;
     while(!s2.empty()){
       BinaryTreeNode<int>* top=s2.top();
       s2.pop();
       cout <<top->data<<" ";
       count++;
       if(top->left!=NULL){
         s1.push(top->left);
       }
       if(top->right!=NULL){
         s1.push(top->right);
       }
     }
     cout<<endl;
   }
}


int lcaBinaryTree(BinaryTreeNode <int>* root , int n1, int n2){
    if(root==NULL){
        return -1;
    }
   if(root->data==n1 || root->data==n2){
   return root->data;
   }

   int a=lcaBinaryTree(root->left,n1,n2);
   int b=lcaBinaryTree(root->right,n1,n2);
   if(a==-1 && b==-1){return -1;}
   if(a==-1 && b!=-1){return b;}
   if(a!=-1 && b==-1){return a;}
   if(a!=-1 && b!=-1){return root->data;}
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
  BinaryTreeNode<int>* root=takeInputLevelWise();
  printLevelWise(root);
  cout<<countNodes(root)<<endl;
}
