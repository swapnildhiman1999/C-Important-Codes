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

/*int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
      ll n,x;
      cin>>n>>x;
      if(n==0){
        continue;
      }
      ll *arr=new ll[n];
      ll best_sum_ans=INT_MIN;
      ll best_sum_ans_length=-1;
      for(ll i=0;i<n;i++){
        cin>>arr[i];
      }
      if(n==1){
        if(arr[0]%x!=0){
          cout<<"1"<<endl;
       }
       else{
         cout<<"-1"<<endl;
       }
      }
      else{
      for(ll i=0;i<n-1;i++){
        ll sum=arr[i];
        if(best_sum_ans<sum && sum%x!=0){
          best_sum_ans=sum;
          best_sum_ans_length=1;
        }
        for(ll j=i+1;j<n;j++){
          sum+=arr[j];
          if(best_sum_ans<=sum && best_sum_ans_length<=j-i+1  && sum%x!=0){
            best_sum_ans=sum;
            best_sum_ans_length=j-i+1;
          }
        }
      }
      //cout<<best_sum_ans<<endl;
      cout<<best_sum_ans_length<<endl;
      delete[] arr;
    }
  }
    return 0;
 }*/
 int go(int *arr,int n,int &length,int x){
   if(n==1){
     if(arr[0]%x!=0){
       length++;
       return arr[0];
     }
   }
   int aage_sum=go(arr+1,n-1,length,x);
   if(arr[0]+aage_sum%x!=0){
     aage_sum+=arr[0];
     length++;
   }
   return aage_sum;
 }
 int main(){
   int t;
   cin>>t;
   while(t--){
     int n,x;
     cin>>n>>x;
     int *arr=new int[n];
     FOR(i,n){cin>>arr[i];}
     int length=0;
     int sum=go(arr+1,n-1,length,x);
     if(sum+arr[0]%x!=0){length++; sum+=arr[0];}
     cout<<length<<endl;
   }
 }
