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

bool bipartite(vector<int> *edges,bool *visited,int n,int sv){
  if(n==0){
    return false;
  }
   visited[sv]=true;
   queue<int> pendingVertices;
   unordered_set<int> sets[2];
   sets[0].insert(sv);
   pendingVertices.push(sv);
   while(!pendingVertices.empty()){
     int element=pendingVertices.front();
     pendingVertices.pop();
     int currentElementSet= sets[0].count(element)> 0 ? 0 : 1;
     for(int i=0;i<edges[element].size();i++){
       int neighbor=edges[element][i];
       if(sets[0].count(neighbor)==0 && sets[1].count(neighbor)==0){
         sets[1-currentElementSet].insert(neighbor);
         pendingVertices.push(neighbor);
         visited[neighbor] = true;
        }
       else if(sets[currentElementSet].count(neighbor)>0){
         return false;
       }
     }
   }
   return true;
}

int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
      int n;
      cin>>n;
      if(n==0){
        return 0;
      }
      int m;
      cin>>m;
      vector<int> *edges=new vector<int>[n];
      for(int i=0;i<m;i++){
        int j,k;
        cin>>j>>k;
        edges[j].pb(k);
        edges[k].pb(j);
      }
      bool *visited=new bool[n];
      memset(visited,false,n*sizeof(bool));
      bool flag=true;
      for(int i=0;i<n;i++){
        if(!visited[i]){
          bool ans=bipartite(edges,visited,n,i);
          if(!ans){
            flag=false;
            cout<<"NOT BIPARTITE"<<endl;
            continue;
          }
        }
      }
      if(flag){
        cout<<"BIPARTITE"<<endl;
      }
    }
 }
