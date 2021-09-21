/*
Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W llo his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(n).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N llegers i.e. weights of items separated by space
Line 3 : N llegers i.e. values of items separated by space
Line 4 : lleger W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constralls
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//rather than using dp[n][W] we should use dp[2][W] as we only need the value of previous row
ll knapsack_space_optimized(ll *wt,ll *val,ll n,ll W){
    ll dp[2][W+1];
    memset(dp,0,sizeof(dp));
    ll i=0;
    //n is odd store in dp[0][W] else dp[1][W]
    while(i<n){//traversing the array
     ll j=0;
     if(i%2!=0){//till now encountered odd elements
         while(++j<=W){
           if(wt[i]<=j){
               dp[1][j]=max(dp[0][j],val[i]+dp[0][j-wt[i]]);
           }
           else{
               dp[1][j]=dp[0][j];
           }
         }
      }
      else{
          while(++j<=W){
              if(wt[i]<=j){
                  dp[0][j]=max(dp[1][j],val[i]+dp[1][j-wt[i]]);
              }
              else{
                  dp[0][j]=dp[1][j];
              }
          }
      }
        i++;
    }
    return (n&1!=0)?dp[0][W]:dp[1][W];
}
ll knapsack_itr(ll *wt,ll *val,ll n,ll W){
    ll **dp=new ll*[n+1];
    for(ll i=0;i<=n;i++){
        dp[i]=new ll[W+1];
    }
    for(ll i=0;i<=W;i++){
        dp[0][i]=0;
    }
    for(ll i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(ll i=1;i<=n;i++){
        for(ll w=0;w<=W;w++){
            dp[i][w]=dp[i-1][w];
            if(wt[i-1]<=w){
                dp[i][w]=max(dp[i][w],val[i-1]+dp[i-1][w-wt[i-1]]);
            }
        }
    }
    return dp[n][W];
    }
ll knapsack_helper(ll *wt,ll *val,ll n,ll W,ll **dp){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W]!=0){
        return dp[n][W];
    }
    //starting from the last index
    ll ans;
    if(wt[n-1]<=W){
        ans=max(val[n-1]+knapsack_helper(wt,val,n-1,W-wt[n-1],dp),knapsack_helper(wt,val,n-1,W,dp));
    }
    else{
        return knapsack_helper(wt,val,n-1,W,dp);
    }
    dp[n][W]=ans;
    return ans;
}
ll knapsack(ll* wt, ll* val, ll n, ll W){
    return knapsack_space_optimized(wt,val,n,W);
}
ll main(){
    ll n;
    cin>>n;
    ll wt[n],val[n];
    for(ll i=0;i<n;i++){
     cin>>wt[i];
    }
    for(ll i=0;i<n;i++){
     cin>>val[i];
    }
    ll W;
    cin>>W;
    cout<<knapsack(wt,val,n,W)<<endl;
}