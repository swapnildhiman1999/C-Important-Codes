/*
Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3
*/
#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
#include "solution.h"
char cake[NMAX][NMAX];
int visited[NMAX][NMAX];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool isSafe(int n,int x,int y,char cake[NMAX][NMAX]){
  if(x>=0 && x<n && y>=0 && y<n && cake[x][y]=='1'){
    return true;
  }
  return false;
}
void DFS(int n,char cake[NMAX][NMAX],int &length,int x,int y){
  visited[x][y]=1;
  for(int k=0;k<4;k++){
    int newx=x+dx[k];
    int newy=y+dy[k];
    if(isSafe(n,newx,newy,cake) && !visited[newx][newy]){
      length++;
      DFS(n,cake,length,newx,newy);
    }
  }
}
int solve(int n,char cake[NMAX][NMAX]){
  int max_length=0;
  memset(visited,0,sizeof(visited));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(cake[i][j]!='0' && !visited[i][j]){
        int length=1;
        DFS(n,cake,length,i,j);
        if(length>max_length){
          max_length=length;
        }
      }
    }
  }
  return max_length;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
