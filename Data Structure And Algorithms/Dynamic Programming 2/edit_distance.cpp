/*
Code : Edit Distance (Memoization and DP)
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
/*
int editDistance(string s1, string s2){
  int m=s1.size();
  int n=s2.size();
  if(m==0){
      return n;
  }
  if(n==0){
      return m;
  }
  if(s1[0]==s2[0]){
      return editDistance(s1.substr(1),s2.substr(1));
  }
  else{
      return 1+min(editDistance(s1.substr(1),s2.substr(1)),min(editDistance(s1.substr(1),s2),editDistance(s1,s2.substr(1))));
  }
}
*/

int editDistanceHelper(string s1, string s2,int **dp){
    int m=s1.size();
    int n=s2.size();

    if(m==0){
        return n;
    }
    if(n==0){
      return m;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(s1[0]==s2[0]){
        int ans=editDistanceHelper(s1.substr(1),s2.substr(1),dp);
        dp[m][n]=ans;
        return ans;
    }
    else{
        int a=editDistanceHelper(s1.substr(1),s2,dp)+1;
        int b=editDistanceHelper(s1,s2.substr(1),dp)+1;
        int c=editDistanceHelper(s1.substr(1),s2.substr(1),dp)+1;
        int ans=min(a,min(b,c));
        dp[m][n]=ans;
        return ans;
    }
}
int editDistance(string s1,string s2){
   int **dp=new int*[s1.size()+1];
   for(int i=0;i<=s1.size();i++){
     dp[i]=new int[s2.size()+1];
     for(int j=0;j<=s2.size();j++){
       dp[i][j]=-1;
     }
   }
   return editDistanceHelper(s1,s2,dp);
}
int editDistance_dp(string s1,string s2){
    int m=s1.size();
    int n=s2.size();
    int dp[s1.size()+1][s2.size()+1];
    dp[0][0]=0;
    for(int i=0;i<=s1.size();i++){
        dp[i][0]=i;//here s2 is length 0
    }
    for(int j=0;j<=s2.size();j++){
        dp[0][j]=j;//s1.length()==0
    }
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[m-i]==s2[n-j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    return dp[m][n];
}
#include "Solution.h"

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
