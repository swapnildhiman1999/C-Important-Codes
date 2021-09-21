/*
Code : Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/
int helper(int n,int *dp){
    if(n==0){
      return 0;
    }
    if(dp[n]!=INT_MAX){
        return dp[n];
    }
    int minimum=INT_MAX;
	for(int i=1;i<=sqrt(n);i++){
        minimum=min(minimum,1+helper(n-pow(i,2),dp));
    }
    dp[n]=minimum;
    return minimum;
}
int minCount(int n)
{  // int *dp=new int[n+1];
 //     for(int i=0;i<=n;i++){
 //         dp[i]=INT_MAX;
 //     }
 // return helper(n,dp);
  int *dp=new int[n+1];
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  for(int i=3;i<=n;i++){
      dp[i]=INT_MAX;
      for(int j=1;j<=sqrt(i);j++){
          int index=i-pow(j,2);
          dp[i]=min(dp[i],1+dp[index]);
      }
  }
   return dp[n];
}
#include <bits/stdc++.h>
using namespace std;
#include "solution.h"

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
