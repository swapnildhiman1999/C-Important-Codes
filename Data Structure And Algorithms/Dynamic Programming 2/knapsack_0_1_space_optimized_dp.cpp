/*
Code: Knapsack (Memoization and DP)
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
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

#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int knapsack_helper(int* weights, int* values, int n, int W,int **dp){
    if(W==0 || n==0){
        return 0;
    }
    if(dp[n][W]!=0){
        return dp[n][W];
    }
    int a=knapsack_helper(weights+1,values+1,n-1,W,dp);
    int b=0;
    if(weights[0]<=W){
     b=values[0]+knapsack_helper(weights+1,values+1,n-1,W-weights[0],dp);
    }
    dp[n][W]=max(a,b);
    return max(a,b);
}
int knapsack(int* weights, int* values, int n, int maxWeight){
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            dp[i][j]=0;
        }
    }
   return knapsack_helper(weights,values,n,maxWeight,dp);
}
int knapsack_dp(int* weights, int* values, int n, int maxWeight){
    int W=maxWeight;
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=W;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            //i size and j is maxWt we have
            if(weights[n-i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(values[n-i]+dp[i-1][j-weights[n-i]],dp[i-1][j]);
            }
        }
    }
    return dp[n][W];
}
int knapsack_dp_space_optimized(int* weights, int* values, int n, int maxWeight){
    int W=maxWeight;
    int dp[2][W+1];
     for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    dp[1][0]=0;
    int start=1,previous=0;
    int count=1;
    int curr_elements=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(i%2!=0){
                //even starting index
                //dp[1][j]
                if(weights[n-i]>W){
                    dp[1][j]=dp[0][j];
                }
                else{
                    dp[1][j]=max(values[n-i]+dp[0][j-weights[n-i]],dp[0][j]);
                }
            }
            else{
                if(weights[n-i]>W){
                    dp[0][j]=dp[1][j];
                }
                else{
                    dp[0][j]=max(values[n-i]+dp[1][j-weights[n-i]],dp[1][j]);
                }
            }
        }
    }
    if(n%2!=0){
     return dp[1][W];
    }
    return dp[0][W];
}
#include<iostream>
using namespace std;
#include "Solution.h"

int main(){

  int n;
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}
