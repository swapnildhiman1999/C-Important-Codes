

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
  trieNode *left, *right;
};

void insert(trieNode * head,int val){
  //going to do for 32 bits
  trieNode *curr=head;
  for(int i=31;i>=0;i--){
    int bit=(val>>i)&1;
    if(bit==0){
      if(!curr->left){
        //if left side is empty
        curr->left=new trieNode();
      }
      curr=curr->left;
    }
    else{
      if(!curr->right){
        curr->right=new trieNode();
      }
      curr=curr->right;
    }
  }
}

int findmaxXORpair(trieNode * head,int *arr,int n){
  int max_xor=INT_MIN;
  for(int i=0;i<n;i++){
    int curr_xor=0;
    int val=arr[i];
    trieNode *curr=head;
    for(int j=31;j>=0;j--){
      int bit=(val>>j)&1;
      if(bit==0){
        //want to move towards right for encountering 1 if possible to make curr_xor maximum answer
        if(curr->right){
          curr_xor+=pow(2,j);
          curr=curr->right;
        }
        else{curr=curr->left;}
      }
      else{
        if(curr->left){
          curr_xor+=pow(2,j);
          curr=curr->left;
        }
        else{curr=curr->right;}
      }
    }
    if(curr_xor>max_xor){ max_xor=curr_xor;}
  }
  return max_xor;
}

int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int n=3>>1;//shifting towards maximum bit or right shift(number gets towards right) by 1 time
    //cout<<n<<endl;
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    trieNode *head=new trieNode();
    for(int i=0;i<n;i++){
      insert(head,arr[i]);
    }
    cout<<findmaxXORpair(head,arr,n)<<endl;
}
