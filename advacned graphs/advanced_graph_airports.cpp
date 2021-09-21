/*
AIRPORTS
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.
Input
The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output
Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
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
  int sr,destination,wt;
};
bool comparator(Edges &a,Edges &b){
  return a.wt<b.wt;
}
int findroot(int v,int *parent,int n){
  if(parent[v]==v && v<=n){
    return v;
  }
  int root=findroot(parent[v],parent,n);
  return root;
}
int main(){
  int t;
  cin>>t;
  for(int z=1;z<=t;z++){
    int n,m,a;
    cin>>n>>m>>a;
     Edges *edges=new Edges[m];
     for(int i=0;i<m;i++){
       int j,k,rc;
       cin>>j>>k>>rc;
       edges[i].sr=j;
       edges[i].destination=k;
       edges[i].wt=rc;
     }
    sort(edges,edges+m,comparator);
    // cout<<endl;
    // for(int i=0;i<m;i++){
    //   cout<<edges[i].sr<<" "<<edges[i].destination<<" "<<edges[i].wt<<endl;
    // }
    int *parent=new int[n+1];
    for(int i=1;i<=n;i++){
      parent[i]=i;
    }
    int k=0;
    ll cost=0;
    while(k<m){
      int source=edges[k].sr;
      int target=edges[k].destination;
      int weight=edges[k].wt;
      int topmost_parent_source=findroot(source,parent,n);
      int topmost_parent_target=findroot(target,parent,n);
      //cout<<cost<<endl;
      if(topmost_parent_source!=topmost_parent_target && weight<a){
        //not forming a cycle
        cost+=weight;
        parent[topmost_parent_source]=topmost_parent_target;
      }
    //  cout<<cost<<endl;
      k++;
    }
  //  cout<<cost<<endl;
    //adding airport building cost
    ll airport_count=0;
    for(int i=1;i<=n;i++){
      if(i==parent[i]){
        airport_count++;
      }
    }
    cost+=airport_count*a;
    cout<<"Case #"<<z<<": "<<cost<<" "<<airport_count<<endl;
  }
}
