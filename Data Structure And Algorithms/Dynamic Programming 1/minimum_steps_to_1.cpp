/*
Code : Min Steps to 1
Send Feedback
Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.
1.) Subtract 1 from it. (n= n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ).
Just write brute-force recursive solution for this.
Input format :
Line 1 : A single integer i.e. n
Output format :
Line 1 : Single integer i.e number of steps
Constraints :
1 <= n <= 500
Sample Input 1 :
4
Sample Output 1 :
2
Sample Output 1 Explanation :
For n = 4
Step 1 : n = 4/2 = 2
Step 2 : n = 2/2 = 1
Sample Input 2 :
7
Sample Output 2 :
3
Sample Output 2 Explanation :
For n = 7
Step 1 : n = 7 ­ - 1 = 6
Step 2 : n = 6 / 3 = 2
Step 3 : n = 2 / 2 = 1
*/

#include<climits>
using namespace std;
int helper(int n,int arr[],int size){
   if(n==1){
      return 0;
  }
  if(arr[n]!=-1){
      return arr[n];
  }
  int a=INT_MAX,b=INT_MAX,c=INT_MAX;
  a=helper(n-1,arr,size);
  if(n%3==0){
  b=helper(n/3,arr,size);
  }
  if(n%2==0){
      c=helper(n/2,arr,size);
  }
   arr[n]=1+min(a,min(b,c));
   return 1+min(a,min(b,c));
}
int itr_sol(int n){
    int *dp=new int[n+1];
    dp[0]=0,dp[1]=0;
    for(int i=2;i<=n;i++){
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        a=dp[i-1];
        if(i%2==0){
            b=dp[i/2];
        }
        if(i%3==0){
            c=dp[i/3];
        }
        dp[i]=1+min(a,min(b,c));
    }
    return dp[n];
}
int countStepsToOne(int n)
{
    // int *arr=new int[n+1];
    // for(int i=0;i<=n;i++){
    //     arr[i]=-1;
    // }
    // return helper(n,arr,n+1);
    return itr_sol(n);
}
#include <bits/stdc++.h>
using namespace std;
#include "solution.h"

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
