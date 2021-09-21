/*
Dominos
Send Feedback
Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
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

void DFS1(vector<int>*edges,stack<int> &finishedVertices,bool *visited,int sv){
  visited[sv]=true;
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      DFS1(edges,finishedVertices,visited,next);
    }
  }
  finishedVertices.push(sv);
}

void DFS2(vector<int>* edges,bool *visited,int sv){
  visited[sv] = true;
  for(int i=0;i<edges[sv].size();i++){
    int next = edges[sv][i];
    if(!visited[next]){
      DFS2(edges,visited,next);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
      }
      stack<int> finishedVertices;
      bool *visited1=new bool[n];
      memset(visited1,false,n*sizeof(bool));
      for(int i=0;i<n;i++){
        if(!visited1[i]){
          DFS1(edges,finishedVertices,visited1,i);
        }
      }
      bool *visited2=new bool[n];
      memset(visited2,false,n*sizeof(bool));
      int count=0;
      while(!finishedVertices.empty()){
        int element=finishedVertices.top();
        finishedVertices.pop();
        if(!visited2[element]){
          DFS2(edges,visited2,element);
          count++;
        }
      }
      cout<<count<<endl;
    }
 }
