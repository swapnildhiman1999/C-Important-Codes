/*
Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int visited[51][51];
int found=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void DFS(char board[][MAXN],int n,int m,int x,int y,int fromx,int fromy,char character,int &cycle_count){
  if(x<0 || x>=n || y<0 || y>=m) return;
  if(visited[x][y] && cycle_count>=4){
    found=1;
    return;
  }
  if(board[x][y]!=character){
   return;
  }
  visited[x][y]=1;
  for(int k=0;k<4;k++){
    int newx=x+dx[k];
    int newy=y+dy[k];
    if(newx==fromx && newy==fromy) continue;
    DFS(board,n,m,newx,newy,x,y,character,cycle_count+1);
  }
}
int solve(char board[][MAXN],int n,int m){
  int i,j;
  memset(visited,0,sizeof(visited));
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(!visited[i][j]){
        int cycle_count=0;
        DFS(board,n,m,i,j,-1,-1,board[i][j],cycle_count);
        if(found && cycle_count>=4){
          return 1;
        }
      }
    }
  }
  return found;
}
int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}
