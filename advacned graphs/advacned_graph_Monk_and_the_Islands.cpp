/*
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/
#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>

using namespace std;

#define pb push_back
#define INF 1000000000
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define fi first
#define se second

#define SZ(x) ((int)(x.size()))
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define BETWEEN(s,t,v) ((s)<=(v)&&(v)<=(t))

#define inpt(n) int (n); scanf("%d",&(n));
#define inpt2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define inpt3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void prnt(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }

int BFS_level(vector<int> *edges,int n){
  //int n=edges->size();
  cout<<edges->size()<<endl;
  int *level=new int[n];
  bool *visited=new bool[n];
  queue<int> pendingVertices;
  memset(visited,false,sizeof(visited));
  level[0]=0;
  pendingVertices.push(0);
  visited[0]=true;
  while(!pendingVertices.empty()){
    int element=pendingVertices.front();
    pendingVertices.pop();
    for(int i=0;i<edges[element].size();i++){
      if(!visited[edges[element][i]]){
        level[edges[element][i]]=1+level[element];
        pendingVertices.push(edges[element][i]);
        visited[edges[element][i]]=true;
      }
    }
  }
  return level[n-1];
}

//doing by BFS and returning level of target element
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vector<int> *edges=new vector<int>[n];
    for(int i=0;i<m;i++){
      int j,k;
      cin>>j>>k;
      edges[j-1].pb(k-1);
      edges[k-1].pb(j-1);
    }
    cout<<"edges size "<<edges->size()<<endl;
    for(int i=0;i<n;i++){
      cout<<i<<" ";
      for(int j=0;j<edges[i].size();j++){
        cout<<edges[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<BFS_level(edges,n)<<endl;
  }
  return 0;
}
