/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1
*/
#include<iostream>
#include<vector>
using namespace std;
/*
void DFS_helper(int **edges,int n,int sv,bool *visited,vector<int> &ans){
  ans.push_back(sv);
  visited[sv]=true;
  for(int i=0;i<n;i++){
    if(!visited[i] && edges[sv][i]==1){
      DFS_helper(edges,n,i,visited,ans);
    }
  }
}
vector<vector<int>> solve_helper(int **edges,int n){
  bool *visited=new bool[n];
  memset(visited,false,n);
  vector<vector<int>> output;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      vector<int> ans;
      DFS_helper(edges,n,i,visited,ans);
      output.push_back(ans);
    }
  }
  return output;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
  int **edges=new int*[n];
  for(int i=0;i<n;i++){
    edges[i]=new int[n];
  }
  for(int i=0;i<m;i++){
    edges[u[i]-1][v[i]-1]==1;
    edges[v[i]-1][u[i]-1]==1;
  }
  vector<vector<int>> output=solve_helper(edges,n);
  return output.size();
}
*/

#define pb push_back
#define NM 105
vector<int> adj[NM];
int visited[NM];
void DFS(int u,int p){
  if(visited[u]){
    return;
  }
  visited[u]=1;
  for(int i=0;i<adj[u].size();i++)
  if(adj[u][i]!=p){
      DFS(adj[u][i],u);
    }
}
int solve(int n,int m,std::vector<int> v,std::vector<int> u){
  for(int i=0;i<m;i++){
    adj[u[i]].pb(v[i]);
    adj[v[i]].pb(u[i]);
  }
  int count=0;
  for(int i=1;i<n;i++){
    if(!visited[i]){
      DFS(i,i);
      count++;
    }
  }
  return count;
}
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
