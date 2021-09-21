/*SUBXOR
Send Feedback
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases.
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7
Sample Output
3
*/

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

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
   /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
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

    /* Copy the remaining elements of L[], if there
       are any */
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
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


class trieNode{
public:
  int cnt;//stores number of leaf nodes this node is having
  trieNode *children[2];
  trieNode(){
    this->cnt=0;
    children[0]=NULL,children[1]=NULL;
  }
};

void insert(trieNode *head,int val){
  //will update also as we keep on inserting the prefix xor values of the array
  trieNode *curr=head;
  for(int j=20;j>=0;j--){
    bool k=(1<<j)&val;//can't write bool as 1 hummesha nhi aayega
     //gives jth bit or we can also write as
     //int bit=(val>>j)&1;
    if(!curr->children[k])
    {
     trieNode* newNode=new trieNode();
      newNode->cnt=1;
      //act as leaf node
      curr->children[k]=newNode;
    }
    else{
      (curr->children[k]->cnt)++;
    }
    curr=curr->children[k];
  }
}

int findQuery(trieNode *head,int val,int k_target){
  if(head==NULL){
    return 0;
  }
  trieNode *curr=head;
  int ans=0;
  for(int j=20;j>=0;j--){
    bool p=(1<<j)&val;
    bool q=(1<<j)&k_target;
    if(q==1){
      if(curr->children[p]!=NULL){
        ans+=curr->children[p]->cnt;
      }
      curr=curr->children[1-p];
     }
    else{
      curr=curr->children[p];
    }
    if(curr==NULL){break;}
   }
  return ans;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    int arr[n];
    trieNode *head=new trieNode();
    int xor_val=0;
    long long int ans=0;
    insert(head,xor_val);
    for(int i=0;i<n;i++){
      cin>>arr[i];
      xor_val^=arr[i];
      ans+=findQuery(head,xor_val,k);
      insert(head,xor_val);
    }
    cout<<ans<<"\n";
  }
  return 0;
}
