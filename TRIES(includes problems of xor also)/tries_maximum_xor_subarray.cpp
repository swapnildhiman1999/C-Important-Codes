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

class trieNode{
public:
  trieNode *children[2];//0 for left and 1 for right
  trieNode(){
    children[0]=NULL;
    children[1]=NULL;
  }
};

void insert(trieNode *head,int val){
  trieNode *curr=head;
  for(int i=31;i>=0;i--){
    int bit=(val>>i)&1;
    if(bit==0){
      if(!curr->children[0]){
        curr->children[0]=new trieNode();
      }
      curr=curr->children[0];
    }
    else{
      if(!curr->children[1]){
        curr->children[1]=new trieNode();
      }
      curr=curr->children[1];
    }
  }
}

int findQuery(trieNode *head,int val){
  trieNode *curr=head;
  //int max_xor=INT_MIN;
  int curr_xor=0;
  for(int j=31;j>=0;j--){
    int bit=(val>>j)&1;
    if(bit==0){
      if(curr->children[1]){
        curr=curr->children[1];
        curr_xor+=pow(2,j);
      }
      else{curr=curr->children[0];}
    }
    else{
      if(curr->children[0]){
        curr=curr->children[0];
        curr_xor+=pow(2,j);
      }
      else{curr=curr->children[1];}
   }
 }
 return curr_xor;
}


int main(){
  int n;
  cin>>n;
  int *arr=new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  trieNode *head=new trieNode();
  int ans=INT_MIN;
  int max_xor=0;
  insert(head,max_xor);//so that woh subarray poora bhi rhe answer hone possibility mai as a^0=a
  for(int i=0;i<n;i++){
    max_xor^=arr[i];
    ans=max(ans,findQuery(head,max_xor));
    insert(head,max_xor);
  }
  cout<<ans<<endl;
}
