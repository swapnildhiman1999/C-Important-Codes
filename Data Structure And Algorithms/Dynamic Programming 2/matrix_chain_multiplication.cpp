/*
Matrix Chain Multiplication
Send Feedback
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format :
Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[]
Output Format :
Line 1 : Minimum number of multiplication needed
Constraints :
1 <= n <= 100
Sample Input 1 :
3
10 15 20 25
Sample Output :
8000
Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000
*/
#include<iostream>
#include<climits>
using namespace std;
int mcm(int *p,int i,int j,int **dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    int temp=INT_MAX;
    for(int k=i;k<=j-1;k++){
        temp=min(temp,mcm(p,i,k,dp)+mcm(p,k+1,j,dp)+p[i-1]*p[k]*p[j]);
    }
    dp[i][j]=temp;
    return temp;
}
int mcm(int* p, int n){
  /*int **dp=new int*[n+1];
  for(int i=0;i<=n;i++){
      dp[i]=new int[n];
      for(int j=0;j<=n;j++){
          dp[i][j]=0;
      }
  }
  //cout<<n<<endl;
  return mcm(p,1,n,dp);
  */
    //3
    //10 15 20 25
    //here n is the last index of p  -> p[3]=25 n=3
   int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        dp[i][i]=0;
    }
    //subsequence of length len
    for(int len=2;len<=n;len++){
        //starting pt of subsequence is i
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<=j-1 && j<=n;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    return dp[1][n];
}
#include<iostream>
using namespace std;

int main(){

  int n;
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n);

}
