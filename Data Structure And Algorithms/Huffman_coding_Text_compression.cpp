#include<bits/stdc++.h>
using namespace std;
// a tree node
class node{
public:
  char ch;
  int freq;
  node *left,*right;
};

class cmp{
public:
  bool operator()(node * a,node *b){
    return a->freq>b->freq;
  }
};
node *getNode(char ch,int freq,node *left,node *right){
  node *newNode=new node();
  newNode->ch=ch;
  newNode->freq=freq;
  newNode->left=left;
  newNode->right=right;
  return newNode;
}
void encode(node *root,string str,unordered_map<char,string> &huffmanCode){
  if(root==NULL){
    return;
  }
  //leaf node
  if(!root->left && !root->right){
    huffmanCode[root->ch]=str;
  }
  encode(root->left,str+'0',huffmanCode);
  encode(root->right,str+'1',huffmanCode);
}
void printCodes(unordered_map<char,string> huffmanCode){
  for(auto pair:huffmanCode){
    cout<<pair.first<<" "<<pair.second<<endl;
  }
}
void buildHuffmanTree(string text){
  unordered_map<char,int> freq;
  for(char ch:text){
    freq[ch]++;
  }
  //creating priority queue to store all leaf nodes of huffman tree
   priority_queue<node*,vector<node*>,cmp> pq;
   for(auto pair:freq){
     pq.push(getNode(pair.first,pair.second,NULL,NULL));
   }
   //do this till we have no more than one node in pq
   while(pq.size()!=1){
     //removing 2 nodes of highest priority
     node *left=pq.top();
     pq.pop();
     node *right=pq.top();
     pq.pop();
     int sum=left->freq+right->freq;
     //storing all the intermediate nodes and when we get out of this loop it
     //will finally store one node containing root node that will node having freq as sum of all nodes
     pq.push(getNode('\0',sum,left,right));
   }
   node *root=pq.top();
   unordered_map<char,string> huffmanCode;
   encode(root,"",huffmanCode);
   printCodes(huffmanCode);
}

int main(){
  string s="abaaacb";
  buildHuffmanTree(s);
}
