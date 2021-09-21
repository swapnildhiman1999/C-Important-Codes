/*
Code : Staircase using Dp
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/
long helper(int n,long arr[],int size){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }
    if(arr[n]!=-1){
      return arr[n];
    }
    long a=helper(n-1,arr,size);
    long b=helper(n-2,arr,size);
    long c=helper(n-3,arr,size);
    arr[n]=a+b+c;
    return a+b+c;
}
long staircase(int n)
{
    // long *arr=new long[n+1];
    // for(int i=0;i<=n;i++){
    //     arr[i]=-1;
    // }
    // return helper(n,arr,n+1);
    long dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}
#include <iostream>
using namespace std;
#include "solution.h"

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
