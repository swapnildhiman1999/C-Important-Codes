/*
Mehta And Bank Robbery
Send Feedback
One fine day, when everything was going good, Mehta was fired from his job and had to leave all the work. So, he decided to become a member of gangster squad and start his new career of robbing. Being a novice, mehta was asked to perform a robbery task in which he was given a bag having a capacity W units. So, when he reached the house to be robbed, there lay N items each having particular weight and particular profit associated with it. But, theres a twist associated, He has first 10 primes with him, which he can use atmost once, if he picks any item x, then he can multiply his profit[x] with any of the first 10 primes and then put that item into his bag. Each prime can only be used with one particular item and one item can only have atmost one prime multiplied with its profit. Its not necessary to pick all the items. If he doesnt want to use a prime with any particular item, he can simply add the profit as it is, more specifically, 1*profit[x] for xth item will get added to its total profit, and that he can do with as many items as he wants. He cannot fill his bag more than weight W units. Each item should be picked with its whole weight, i.e it cannot be broken into several other items of lesser weight. So, now to impress his squad, he wishes to maximize the total profit he can achieve by robbing this wealthy house.
Input:
First Line of input containts two integers N and W. Next N lines contain information of ith item, describing profit and weight of the ith item, profit and weight are separated by single space.
Output:
In a single line, output the maximum profit obtainable.
Constraints:
1 <= N <= 2000, 1 <= W <= 2000

1 <= Profit[i] <= 10^9, 1 <= Weight[i] <= 2000

SAMPLE INPUT
3 4

1 1

2 1

3 1

SAMPLE OUTPUT
152

Explanation:
As all, the items can be picked, so maximum profit is equal to = 1 X 19 + 2 X 23 + 3 X 29 = 152
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

ll solve(vector<pair<ll,ll>> &v,ll n,ll W){
  ll ***dp=new ll**[2];
  for(int i=0;i<2;++i){
    dp[i]=new ll*[n+1];
    for(int j=0;j<n+1;++j){
    dp[i][j]=new ll[W+1];
   for(ll k=0;k<W+1;++k){
   dp[i][j][k]=0;
    }
  }
 }
  ll primes[11]={1,2,3,5,7,11,13,17,19,23,29};
  //base case if p==0 simple knapsack problem
  for(ll i=1;i<=n;++i){
  for(ll j=0;j<=W;++j){
      dp[0][i][j]=dp[0][i-1][j];
      if(j-v[i-1].second>=0){
      dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-v[i-1].second]+v[i-1].first);
      }
    }
  }


  for(ll prime=1;prime<=10;++prime){
   ll p=prime%2;
   for(int i=1;i<=n;++i){
   for(int j=0;j<=W;++j){
        dp[p][i][j]=dp[p][i-1][j];
          if(j-v[i-1].second>=0){
            dp[p][i][j]=max(dp[p][i][j],max(dp[p^1][i-1][j-v[i-1].second]+v[i-1].first,dp[p^1][i-1][j-v[i-1].second]+(v[i-1].first*primes[prime])));
        }
      }
    }
  }

   return dp[0][n][W];

}

int main(){
 ll n;
 ll W;
 cin>>n>>W;
 vector<pair<ll,ll>> v;
 for(int i=0;i<n;++i){
   pair<ll,ll> a;
   ll f,s;
   cin>>f>>s;
   a.first=f;a.second=s;
   v.pb(a);
  }
  sort(v.begin(),v.end());
  cout<<solve(v,n,W)<<endl;
}
