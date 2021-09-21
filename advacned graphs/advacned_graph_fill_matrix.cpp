/*
FILLMTR
Send Feedback
Fill The Matrix
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Constraints
1 ≤ T ≤ 10^6
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^6
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
yes
no
yes
no
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

bool bipartite(vector<int> *edges,int sv,bool *visited){
  if(edges->size()==0){return false;}
  //finding first non empty index
  int i=0;
  for(;i<edges->size();i++){
    if(edges[i].size()!=0){break;}
  }
   unordered_set<int> sets[2];
   queue<int> pendingVertices;
   sets[0].insert(sv);
   pendingVertices.push(sv);
   visited[sv]=true;
   while(!pendingVertices.empty()){
     int element=pendingVertices.front();
     pendingVertices.pop();
     int currentSetElement=sets[0].count(element)>0 ? 0:1;
     for(int i=0;i<edges[element].size();i++){
       int neighbor=edges[element][i];
       if(sets[0].count(neighbor)==0 && sets[1].count(neighbor)==0){
         sets[1-currentSetElement].insert(neighbor);
         pendingVertices.push(neighbor);
         visited[neighbor] = true;
       }
       else if(sets[currentSetElement].count(neighbor)>0){return false;}
     }
   }
     return true;
 }

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,q;
    cin>>n>>q;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
       arr[i]=new int[n];
    }
    for(int i=0;i<q;i++){
      int v1,v2,wt;
      cin>>v1>>v2>>wt;
      arr[v1-1][v2-1]=wt;
      arr[v2-1][v1-1]=wt;
    }
    //do the sanity checking for diagonal and mirror elements
    bool flag1=true,flag2=true;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j && arr[i][j]!=0){
          flag1=false;
          break;
        }
        else if(arr[i][j]==1 || arr[i][j]==0 && arr[j][i]!=arr[i][j]){
          flag2=false;
          break;
        }
      }
    }
    //if sanity checking is correct
    if(flag1 && flag2){
       //need to do clubbing of all the zeroes values attached by
       //union find algorithm
       int *parent=new int[n];
       for(int i=0;i<n;i++){
         parent[i]=i;
       }
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(arr[i][j]==0){
             int v1=i,v2=j;
             int p1=parent[v1],p2=parent[v2];//topmost parent
             while(p1!=parent[p1]){
               v1=parent[v1];
               p1=parent[v1];
             }
             while(p2!=parent[p2]){
               v2=parent[v2];
               p2=parent[v2];
             }
             v1=i,v2=j;
             if(p1!=p2){
               parent[p2]=p1;
             }
           }
        }
      }
      vector<int> *edges=new vector<int>[n];
      //parent array is ready
      //bool flag3=true;
      for(int i=0;i<n;i++){
        //bool flag4=true;
        for(int j=0;j<n;j++){
          if(arr[i][j]==1){
            int v1=i,v2=j;
            int p1=parent[v1],p2=parent[v2];
            while(p1!=parent[p1]){
              v1=parent[v1];
              p1=parent[v1];
            }
            while(p2!=parent[p2]){
              v2=parent[v2];
              p2=parent[v2];
            }
            v1=i,v2=j;
            // if(p1==p2){
            //   cout<<"no"<<endl;
            //   flag3=false;
            //   flag4=false;
            //   break;
            // }
            edges[p1].pb(p2);
            edges[p2].pb(p1);
          }
        }
      }
      //check for bipartite
      bool *visited=new bool[n];
     bool flag3=true;
      memset(visited,0,n*sizeof(bool));
      for(int i=0;i<n;i++){
        if(!visited[i]){
      bool ans=bipartite(edges,i,visited);
      if(!ans){cout<<"no"<<endl;
    flag3=false;
  break;}
    }
  }
      if(flag3){
      cout<<"yes"<<endl;}
    }
    else{
      cout<<"no"<<endl;
    }
  }
}
