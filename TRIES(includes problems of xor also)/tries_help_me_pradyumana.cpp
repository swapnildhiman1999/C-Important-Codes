

#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>


using namespace std;


#define pb push_back
#define INF 1000000000
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define fi first
#define se second


#define SZ(x) ((int)(x.size()))
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define BETWEEN(s,t,v) ((s)<=(v)&&(v)<=(t))


#define inpt(n) int (n); scanf("%d",&(n));
#define inpt2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define inpt3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void prnt(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
         merge(arr, l, m, r);
    }
}

class trieNode{
public:
  char ch;
  trieNode *children[26];
  trieNode(){
    for(int i=0;i<26;i++){
      children[i]=NULL;
    }
  }
};

void insert(trieNode *head,string s){
  if(s.size()==0){
    return;
  }
  int index=s[0]-'a';
  trieNode *child;
  if(head->children[index]){
    child=head->children[index];
  }
  else{
    child=new trieNode();
    child->ch=s[0];
    head->children[index]=child;
  }
  insert(child,s.substr(1));
}

void solve(trieNode *node,string &str,int length){
  //DFS
  bool found_leaf=true;
  for(int i=0;i<26;i++){
    if(node->children[i]!=NULL){
      found_leaf=false;
      break;
    }
  }
  if(found_leaf)
  {
    for(int i=0;i<length;i++){
      cout<<str[i];
    }
    cout<<"\n";
  }
  else{
  for(int i=0;i<26;i++){
    if(node->children[i]){
      str.push_back(char(i+97));
      solve(node->children[i],str,length+1);
    }
  }
 }
}

void query(trieNode *head,string q){
  //intially travel till q's length
  int n=q.size();
  trieNode *curr=head;
  bool found=true;
  for(int i=0;i<n;i++){
    int index=q[i]-'a';
    if(curr->children[index]==NULL){
      found=false;
      cout<<"No suggestions"<<"\n";
      break;
    }
    if(found){
      solve(curr,q,n);
    }
  }
}

int main(){
  int a;
  cin>>a;
  trieNode *head=new trieNode();
  while(a--){
    string s;
    cin>>s;
    insert(head,s);
  }
  int q;
  cin>>q;
  while(q--){
    string s;
    cin>>s;
    query(head,s);
  }
}
