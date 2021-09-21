/*
Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/
#define ll long long
#define mod 1000000007
int balancedBTs(int h,int dp[]) {
    if(h<=1){
        dp[h]=1;
        return 1;
    }
    // if(h==2){
    //     return 3;
    // }
    if(dp[h]!=0){
        return dp[h];
    }
    int t1=balancedBTs(h-1,dp);
    int t2=balancedBTs(h-2,dp);
    //long iss liya example
    //int a=(b+c)*d yahaan pehle b and c add hoke int temporay buffer mai store hoke and then multiplied by d return to a hota hai
    //aise he yahaan pe agr int temp buffer hota toh out of context jaa skta tha isliye badhe container mai store kiya
    int temp1=(int)(((long)(t1)*t1)%mod);
    int temp2=(int)((2*(long)(t1)*t2)%mod);
    int ans=(temp1+temp2)%mod;
    dp[h]=ans;
    return ans;
}
int balancedBTs(int h){
   //  int *dp=new int[h+1];
   //  for(int i=0;i<=h;i++){
   //      dp[i]=0;
   //  }
   // return balancedBTs(h,dp);
    int dp[h+1];
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=h;i++){
        int t1=dp[i-1],t2=dp[i-2];
        int temp1=(int)(((long)(t1)*t1)%mod);
        int temp2=(int)((2*(long)(t2)*t1)%mod);
        dp[i]=(temp1+temp2)%mod;
    }
    return dp[h];
}
#include <iostream>
#include "Solution.h"
using namespace std;
#include <cmath>

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
