/*
Code : Min Cost Path
Send Feedback
Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)
Output Format :
Minimum cost
Constraints :
1 <= m, n <= 20
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **input,int m,int n,int i,int j,int **dp){
    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(i==m-1 && j==n-1){
        dp[i][j]=input[i][j];

        return input[i][j];
    }
    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    int val1=minCostPath(input,m,n,i+1,j,dp);
    int val2=minCostPath(input,m,n,i+1,j+1,dp);
    int val3=minCostPath(input,m,n,i,j+1,dp);
    dp[i][j]=input[i][j]+min(val1,min(val2,val3));
    return input[i][j]+min(val1,min(val2,val3));
}
int minCostPath_2(int **input,int m,int n){
  int dp[m][n];
  dp[m-1][n-1]=input[m-1][n-1];
  for(int i=m-2;i>=0;i--){
      dp[i][n-1]=dp[i+1][n-1]+input[i][n-1];
  }
  for(int j=n-2;j>=0;j--){
      dp[m-1][j]=dp[m-1][j+1]+input[m-1][j];
  }
  for(int i=m-2;i>=0;i--){
      for(int j=n-2;j>=0;j--){
          dp[i][j]=min(dp[i+1][j+1],min(dp[i][j+1],dp[i+1][j]))+input[i][j];
      }
  }
  return dp[0][0];
}
int minCostPath(int **input, int m, int n) {
    // int **dp=new int*[m];
    // for(int i=0;i<m;i++){
    //     dp[i]=new int[n];
    //     for(int j=0;j<n;j++){
    //         dp[i][j]=INT_MAX;
    //     }
    // }
    // return minCostPath(input,m,n,0,0,dp);//answer for 0,0 to m-1,n-1
    int dp[m][n];//dp[i][j] answer required from 0,0 to i,j
    dp[0][0]=input[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){continue;}
            int val1=INT_MAX,val2=INT_MAX,val3=INT_MAX;
            if(i-1>=0 && j-1>=0){
                val1=dp[i-1][j-1];
            }
            if(i-1>=0){
                val2=dp[i-1][j];
            }
            if(j-1>=0){
                val3=dp[i][j-1];
            }
            dp[i][j]=input[i][j]+min(val1,min(val2,val3));
        }
    }
    return dp[m-1][n-1];
}
#include "solution.h"

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
