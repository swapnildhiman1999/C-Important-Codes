/*
BOTTOM
Send Feedback
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
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

void DFS1(vector<int>* edges,bool *visited,stack<int> &finishedVertices,int sv){
  visited[sv]=true;
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      DFS1(edges,visited,finishedVertices,next);
    }
  }
  finishedVertices.push(sv);
}

void DFS2(vector<int>* edges,bool *visited,unordered_set<int> *component,int sv){
  visited[sv]=true;
  component->insert(sv);
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      DFS2(edges,visited,component,next);
    }
  }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
   bool *visited1=new bool[n];
   memset(visited1,false,n*sizeof(bool));
   stack<int> finishedVertices;
   for(int i=0;i<n;i++){
      if(!visited1[i]){
        DFS1(edges,visited1,finishedVertices,i);
      }
   }
   bool *visited2=new bool[n];
   memset(visited2,0,n*sizeof(bool));
   unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
   //stack is ready
   while(!finishedVertices.empty()){
     int element=finishedVertices.top();
      finishedVertices.pop();
      unordered_set<int>*  component=new unordered_set<int>();
      if(!visited2[element]){
        DFS2(edgesT,visited2,component,element);
        output->insert(component);
      }
   }
   return output;
}


int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    while(n!=0){
    vector<int>*  edges=new vector<int>[n];
    vector<int>* edgesT=new vector<int>[n];
    for(int i=0;i<m;i++){
       int j,k;
       cin>>j>>k;
       edges[j-1].pb(k-1);
       edgesT[k-1].pb(j-1);
    }
    //first getting strongly connected components
    unordered_set<unordered_set<int>*>* components=getSCC(edges,edgesT,n);
    unordered_set<unordered_set<int>*>*   answer=new unordered_set<unordered_set<int>*>();
    unordered_set<unordered_set<int>*>::iterator it=components->begin();
    unordered_map<int,int> map;
    int index=0;
    while(it!=components->end()){
      unordered_set<int>* component=*it;
      unordered_set<int>::iterator it1=component->begin();
      while(it1!=component->end()){
         int val=*it1;
         map[val]=index;
         it1++;
      }
      index++;
      it++;
    }
    it=components->begin();
    while(it!=components->end()){
      unordered_set<int>* component=*it;
      unordered_set<int>::iterator it1=component->begin();
      bool flag=true;
      while(it1!=component->end() && flag!=false){
        int val=*it1;
        //check for all its neighbours
        for(int i=0;i<edges[val].size();i++){
          int neighbor=edges[val][i];
          if(map[neighbor]!=map[val]){
            flag=false;
            break;
          }
        }
        it1++;
      }
      if(flag){
        answer->insert(component);
      }
      it++;
    }
    unordered_set<unordered_set<int>*>::iterator it_ans=answer->begin();
    vector<int> output_answer;
    while(it_ans!=answer->end()){
    unordered_set<int>* answer1=*it_ans;
        unordered_set<int>::iterator it2=answer1->begin();
        while(it2!=answer1->end()){
          int val=*it2+1;
          output_answer.pb(val);
          it2++;
        }
      //cout<<endl;
        it_ans++;
    }
    sort(output_answer.begin(), output_answer.end());
    for(int i=0;i<output_answer.size();i++){
      cout<<output_answer[i]<<" ";
    }
    cout<<endl;
    cin>>n;
    if(n==0){return 0;}
    cin>>m;
  }
 }
