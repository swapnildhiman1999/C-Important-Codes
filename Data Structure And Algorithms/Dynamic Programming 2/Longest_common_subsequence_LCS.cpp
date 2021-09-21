#include<bits/stdc++.h>
using namespace std;
int lcs_memo(string s1,string s2,int **dp){
  if(s1.length()==0 || s2.length()==0){
    dp[s1.size()][s2.size()]=0;
    return 0;
  }
  if(dp[s1.size()][s2.size()]!=0){
    return dp[s1.size()][s2.size()];
  }
  if(s1[0]==s2[0]){
    int a=1+lcs_memo(s1.substr(1),s2.substr(1),dp);
    dp[s1.size()][s2.size()]=a;
    return a;
  }
  else{
    int b=max(lcs_memo(s1,s2.substr(1),dp),lcs_memo(s1.substr(1),s2,dp));
    dp[s1.size()][s2.size()]=b;
    return b;
  }
}

int lcs(string s1,string s2){
  int **dp=new int*[s1.size()+1];
  for(int i=0;i<=s1.size();i++){
    dp[i]=new int[s2.size()+1];
    for(int j=0;j<=s2.size();j++){
      dp[i][j]=0;
    }
  }
  return lcs_memo(s1,s2,dp);
}
int lcs_itr(string s1,string s2){
  int dp[s1.size()+1][s2.size()+1];
  for(int i=0;i<=s1.size();i++){
    dp[i][0]=0;
  }
  for(int j=0;j<=s2.size();j++){
    dp[0][j]=0;
  }
  for(int i=1;i<=s1.size();i++){
    for(int j=1;j<=s2.size();j++){
      if(s1[m-i]==s2[n-j]){
        dp[i][j]=1+dp[i-1][j-1];
      }
      else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[s1.size()][s2.size()];
}
int main(){
  string s1,s2;
  cin >> s1 >>s2;
  cout<<lcs(s1,s2)<<endl;
  cout<<lcs_itr(s1,s2)<<endl;
}
