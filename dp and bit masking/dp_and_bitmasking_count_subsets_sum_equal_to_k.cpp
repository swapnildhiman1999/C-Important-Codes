

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
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    // base case
    if (a == b)
        return a;
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

int subsets_count_rec(int *arr,int n,int count,int i,int sum){
  if(i==n){
  //checked all the indexes
  if(sum==0)
  {count++;}
  return count;
  }
  count=subsets_count_rec(arr,n,count,i+1,sum-arr[i]);//including the element
  count=subsets_count_rec(arr,n,count,i+1,sum);//excluding
  return count;
}

//using bit masking
int subsetCount(int *arr,int n,int sum){
  int count=0;
  for(int mask=0;mask<=((1<<n)-1);++mask){
    int curr_sum=0;
    vector<int> subset;
    for(int j=0;j<n;j++){
      if((mask&(1<<j))!=0){
        //jth bit is set
        curr_sum+=arr[j];
        subset.pb(arr[j]);
      }
    }
    if(curr_sum==sum){
      count++;
      for(int i=0;i<subset.size();i++){
        cout<<subset[i]<<" ";
      }
      cout<<"\n";
    }
  }
  return count;
}

int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inpt(n);
    int *arr=new int[n];
    FOR(i,n){cin>>arr[i];}
    inpt(s);
    //cout<<"Count of subsets: "<<subsets_count_rec(arr,n,0,0,s)<<endl;
    cout<<"Count of subsets: "<<subsetCount(arr,n,s)<<endl;
}
