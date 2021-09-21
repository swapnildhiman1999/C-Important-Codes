/*
Edges in MST
Send Feedback
Edges in MST
You are given a connected weighted undirected graph without any loops and multiple edges.

Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.

Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input
The first line contains two integers n and m (2 ≤ n ≤ 105, ) — the number of the graph's vertexes and edges, correspondingly. Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi" (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106, ai ≠ bi), where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight. It is guaranteed that the graph is connected and doesn't contain loops or multiple edges.
Output
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Sample input 1
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
sample output 1
none
any
at least one
at least one
any
Sample input 2
3 3
1 2 1
2 3 1
1 3 2
sample output 2
any
any
none
sample input 3
3 3
1 2 1
2 3 1
1 3 1
sample output 3
at least one
at least one
at least one
Note
In the second sample the MST is unique for the given graph: it contains two first edges.

In the third sample any two edges form the MST for the given graph. That means that each edge is included at least in one MST.
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

class Edges{
public:
  int sr,dest,wt;
  string str;
};
bool comparator(Edges &a,Edges &b){
  return a.wt<b.wt;
}
int main(){
  int n,m;
  cin>>n>>m;
  Edges *edges=new Edges[m];
  Edges* temp_edges=new Edges[m];
  FOR(i,m){
    int j,k,w;
    cin>>j>>k>>w;
    edges[i].sr=j;
    edges[i].dest=k;
    edges[i].wt=w;
    temp_edges[i].sr=j;
    temp_edges[i].dest=k;
    temp_edges[i].wt=w;
    }
    sort(temp_edges,temp_edges+m,comparator);
    int count=0;
    while(count<n-1){
      int v1,v2,weight;
      v1=temp_edges[count].sr;
      v2=temp_edges[count].dest;
      int i=count+1;
      bool flag=false;
      for(;i<m;i++){
        if(temp_edges[i].wt!=temp_edges[count].wt){
          break;
        }
        else if(temp_edges[i].wt==temp_edges[count].wt){
          flag=true;
        }
      }
      if(i-count==1 && flag==false){
        temp_edges[count].str="any";
        count++;
      }
      else if(i-count>=1 && flag==true){
        int val=i-count;
        for(int z=count;z<=i;z++){
          temp_edges[z].str="atleast one";
        }
        count+=val;
      }
    }
    for(int z=count;z<m;z++){
      temp_edges[z].str="none";
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
        if(edges[i].sr==temp_edges[j].sr && edges[i].dest==temp_edges[j].dest){
        //  cout<<edges[i].wt<<endl;
          cout<<temp_edges[j].str<<endl;
        }
      }
    }
}
