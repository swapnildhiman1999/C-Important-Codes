template<typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
   if(root==NULL){
       return NULL;
   }
    if(root->data==k){
        return root;
    }
    if(root->data>k){
        searchInBST(root->left,k);
    }
    else{
        searchInBST(root->right,k);
    }
}
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
  if(root==NULL){
    return;
  }
  if(root->data>=k1 && root->data<=k2){
    //printing in increasing order
    elementsInRangeK1K2(root->left,k1,k2);
     cout<<root->data<<" ";
    elementsInRangeK1K2(root->right,k1,k2);
   }
  if(root->data>k2){
    elementsInRangeK1K2(root->left,k1,k2);
  }
  else if(root->data<k1){
    elementsInRangeK1K2(root->right,k1,k2);
  }
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
}#include<climits>
class isBSTReturn{
public:
  int minimum;
  int maximum;
  bool isBST;
};
isBSTReturn isBSThelper(BinaryTreeNode<int> *root){
  if(root==NULL){
    isBSTReturn ans;
    ans.minimum =INT_MAX;
    ans.maximum =INT_MIN;
    ans.isBST = true;
    return ans;
  }
  isBSTReturn lans=isBSThelper(root->left);
  isBSTReturn rans=isBSThelper(root->right);
  int minimum=min(root->data,min(lans.minimum,rans.minimum));
  int maximum=max(root->data,max(lans.maximum,rans.maximum));
  bool isBSTfinal= root->data>lans.maximum && root->data<=rans.minimum && lans.isBST && rans.isBST;
  isBSTReturn ans;
    ans.minimum=minimum;
    ans.maximum=maximum;
    ans.isBST=isBSTfinal;
    return ans;
}
bool isBST(BinaryTreeNode<int> *root){
     return isBSThelper(root).isBST;
}
bool isBST2(BinaryTreeNode<int>* root,int min=INT_MIN , int max=INT_MAX){
  //top to down manner
  if(root==NULL){
    return true;
  }
  if(root->data<min || root->data>max){return false;}
  return isBST2(root->left,min,root->data-1) && isBST2(root->right,root->data,max);
}
BinaryTreeNode<int>* constructTreeHelper(int *input,int si,int ei){
  if(si>ei){return NULL;}
  int mid=si+(ei-si)/2;
  BinaryTreeNode<int>*  root=new BinaryTreeNode<int>(input[mid]);
  root->left=constructTreeHelper(input,si,mid-1);
  root->right=constructTreeHelper(input,mid+1,ei);
  return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
   //making BST from sorted array
   return constructTreeHelper(input,0,n-1);
}
vector<int>* findPath(BinaryTreeNode<int> *root , int data){
  if(root==NULL){
     return NULL;
   }
    if(root->data==data){
      vector<int> *ans=new vector<int>();
      ans->push_back(data);
      return ans;
    }
    if(root->data<=data){
      //need to go on right
      vector<int> *r=findPath(root->right,data);
      if(r!=NULL){
        r->push_back(root->data);
        return r;
      }
      return NULL;
      }
    else{
      vector<int> *l=findPath(root->left,data);
      if(l!=NULL){
        l->push_back(root->data);
        return l;
      }
      return NULL;
    }
}

void insertDuplicateNode(BinaryTreeNode<int> *root) {
//inserting a duplicate node on left
 if(root==NULL){return;}
 insertDuplicateNode(root->left);
 insertDuplicateNode(root->right);
 BinaryTreeNode<int>* duplicate =new BinaryTreeNode<int>(root->data);
 BinaryTreeNode<int> *temp=root->left;
 root->left=duplicate;
 duplicate->left=temp;
}

int lcaInBST(BinaryTreeNode<int>* root , int n1 , int n2){
   if(root==NULL){
       return -1;
   }
    if(root->data==n1 || root->data==n2){
        return root->data;
    }
    if(root->data>max(n1,n2)){
        return lcaInBST(root->left,n1,n2);

    }
    if(root->data<min(n1,n2)){
        return lcaInBST(root->right,n1,n2);
    }
    if(root->data>min(n1,n2) && root->data<max(n1,n2)){
    int a=lcaInBST(root->left,n1,n2);
    int b=lcaInBST(root->right,n1,n2);
    if(a & b){
        return root->data;
    }
        else if(a){
            return a;
        }
         else if(b){
             return b;
         }
        return -1;
    }

}
#include<climits>
class ans{
public:
int minimum;
int maximum;
int max_height_BST;//maximum height of BST it contains
bool isBST;//whether that root is included in BST or not
};
ans largestBSTSubtreeHelper(BinaryTreeNode<int> *root) {
  if(root==NULL){
  return {INT_MAX,INT_MIN,0,true};
  }
  ans l=largestBSTSubtreeHelper(root->left);
  ans r=largestBSTSubtreeHelper(root->right);
  if(l.isBST && r.isBST){
  ans output;
  output.maximum=max(root->data,max(l.maximum,r.maximum));
  output.minimum=min(root->data,min(r.minimum,l.minimum));
  if(root->data>l.maximum && root->data<r.minimum){
   output.isBST=true;
   output.max_height_BST=1+max(l.max_height_BST,r.max_height_BST);
   return output;
    }
    output.isBST=false;
    output.max_height_BST=max(l.max_height_BST,r.max_height_BST);
    return output;
  }
  else if(l.isBST && !r.isBST){
  ans output;
  output.maximum=max(root->data,max(l.maximum,r.maximum));
  output.minimum=min(root->data,min(r.minimum,l.minimum));
  output.isBST=false;
  output.max_height_BST=l.max_height_BST;
  return output;
  }
  else if(!l.isBST && r.isBST){
    ans output;
    output.maximum=max(root->data,max(l.maximum,r.maximum));
    output.minimum=min(root->data,min(r.minimum,l.minimum));
    output.isBST=false;
    output.max_height_BST=r.max_height_BST;
    return output;
  }
  else{
    ans output;
    output.maximum=max(root->data,max(l.maximum,r.maximum));
    output.minimum=min(root->data,min(r.minimum,l.minimum));
    output.max_height_BST=max(l.max_height_BST,r.max_height_BST);
    output.isBST=false;
    return output;
  }
}
int largestBSTSubtree(BinaryTreeNode<int>* root){
  return largestBSTSubtreeHelper(root).max_height_BST;
}

int helper(BinaryTreeNode<int> *root,int sum){
 if(root==NULL){
     return sum;
 }
  sum=helper(root->right,sum);
  sum+=root->data;
  root->data=sum;
  sum=helper(root->left,sum);
  return sum;
    //sum is representing the sum of all the nodes i have traversed so far and updated my node's data with
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
   int sum;
   int total_sum=helper(root,0);
    return;
}
vector<vector<int>>* rootToLeafPathsSumToKHelper(BinaryTreeNode<int> *root,int k){
   if(root==NULL){
   return NULL;
   }
   vector<vector<int>>* output=new vector<vector<int>>();
   vector<vector<int>>* lAns=rootToLeafPathsSumToKHelper(root->left,k-root->data);
   vector<vector<int>>* rAns=rootToLeafPathsSumToKHelper(root->right,k-root->data);
   if(lAns){
     for(int i=0;i<lAns->size();i++){
       vector<int> curr=lAns[i];
       curr.push_back(root->data);
       output.push_back(curr);
     }
   }
   if(rAns){
     for(int i=0;i<rAns->size();i++){
       vector<int> curr=rAns[i];
       curr.push_back(root->data);
       output.push_back(curr);
     }
   }
   return output;
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
  vector<vector<int>>* output=rootToLeafPathsSumToKHelper(root,k);
  for(int i=0;i<output->size();++i){
  for(int j=output[i].size()-1;j>=0;j--){
  cout<<output[j]<<" ";
    }
  cout<<endl;
  }
}

void printrootToLeafPathsSumToK(BinaryTreeNode<int> *root,int k,string s){
 if(root==NULL){
  return;
  }
  s.push_back(root->data);
  if(!root->left && !root->right){
    if(k==root->data){
     for(int i=0;i<s.length();++i){
     cout<<s[i]<<" "<<;
      }
      cout<<endl;
    }
    return;
  }
  printrootToLeafPathsSumToK(root->left,k-root->data,s);
  printrootToLeafPathsSumToK(root->right,k-root->data,s);
}

void helperrootToLeafPathSumToK(BinaryTreeNode<int> *root,int k,vector<int> &v){
 if(root==NULL){
   return;//edge case
  }
  v.push_back(root->data);
  k-=root->data;
  if(!root->left && !root->right){
  if(!k){
     for(int i=0;i<v.size();++i){
     cout<<v[i]<<" ";
      }
      cout<<endl;
    }
    v.pop_back();
    return;
  }
  helperrootToLeafPathSumToK(root->left,k,v);
  helperrootToLeafPathSumToK(root->right,k,v);
  v.pop_back();
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
   vector<int> v;
   helperrootToLeafPathSumToK(root,k,v);
}

void dfs_update_parent(BinaryTreeNode<int> *root,  unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &parent){
 if(root==NULL){
 return;
  }
  if(root->left){
  parent.insert({root->left,root});
  }
  if(root->right){
  parent.insert({root->right,root});
  }
  dfs_update_parent(root->left,parent);
  dfs_update_parent(root->right,parent);
}
BinaryTreeNode<int>* returnNodeReq(BinaryTreeNode<int>* root,int data){
 if(root==NULL){
 return NULL;
  }
  if(root->data==data){
  return root;
  }
  BinaryTreeNode<int>*lans=returnNodeReq(root->left,data);
  if(lans){return lans;}
  BinaryTreeNode<int>*rans=returnNodeReq(root->right,data);
  if(rans){return rans;}
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
  unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> parent;
  //will store parent for each node
  parent.insert({root,NULL});
  dfs_update_parent(root,parent);
  // unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>::iterator it;
  // for (it = parent.begin(); it != parent.end(); ++it) {
	// 	std::cout << "{" << (*it).first << ": " << (*it).second << "}\n";
  //  }
  BinaryTreeNode<int> *starting_node=returnNodeReq(root,node);
  if(starting_node==NULL){
  //node is not present
  return;
  }
  int level=0;
  unordered_set<BinaryTreeNode<int>> visited;
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(starting_node);
  while(level<k){
  while(!pendingNodes.empty()){
   BinaryTreeNode<int>* front=pendingNodes.front();
   pendingNodes.pop();
   if(visited.find(front->data)==visited.end()){
   visited.insert(front->data);
   }
   if(front->left && visited.find(front->left->data)==visited.end()){pendingNodes.push(front->left);}
   if(front->right && visited.find(front->right->data)==visited.end()){
     pendingNodes.push(front->right);
    }
   if(parent[front] && visited.find(parent[front]->data)==visited.end()){pendingNodes.push(parent[front]);}
   }
   level++;
 }
 while(!pendingNodes.empty()){
   BinaryTreeNode<int>* front=pendingNodes.front();
   pendingNodes.pop();
   cout<<front->data<<endl;
  }
}

#include<bits/stdc++.h>
using namespace std;
int countNodes(BinaryTreeNode<int> *root){
  if(root==NULL){
  return 0;
  }
  return countNodes(root->left)+countNodes(root->right)+1;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
  if(root==NULL){
  return;
  }
  int total_nodes=countNodes(root);
    int count=0;
  stack<BinaryTreeNode<int>*> inorder;//traverse in inorder fashion min element on the top
  stack<BinaryTreeNode<int>*> rev_inorder;
  BinaryTreeNode<int>* temp=root;

  while(temp!=NULL){
  inorder.push(temp);
  temp=temp->left;
  }
  temp=root;

  while(temp!=NULL){
  rev_inorder.push(temp);
  temp=temp->right;
  }



  //cout<<total_nodes<<endl;
  while(count<total_nodes-1){
  BinaryTreeNode<int> *top1=inorder.top();
  BinaryTreeNode<int> *top2=rev_inorder.top();
  if((top1->data+top2->data)==s){
   cout<<top1->data<<" "<<top2->data<<endl;

      count++;
      inorder.pop();
      BinaryTreeNode<int>* temp=top1;
      if(temp->right!=NULL){
       temp=temp->right;
       while(temp!=NULL){
       inorder.push(temp);
       temp=temp->left;
        }
      }

      count++;
      rev_inorder.pop();
      temp=top2;
      if(temp->left!=NULL){
       temp=temp->left;
       while(temp!=NULL){
       rev_inorder.push(temp);
       temp=temp->right;
        }
      }

    }
    else if((top1->data+top2->data)<s){
      count++;
      inorder.pop();
      BinaryTreeNode<int>* temp=top1;
      if(temp->right){
       temp=temp->right;
       while(temp!=NULL){
       inorder.push(temp);
       temp=temp->left;
        }
      }
    }

    else{
      count++;
      rev_inorder.pop();
      BinaryTreeNode<int>* temp=top2;
      if(temp->left){
       temp=temp->left;
       while(temp!=NULL){
       rev_inorder.push(temp);
       temp=temp->right;
        }
      }
    }
  }
}
