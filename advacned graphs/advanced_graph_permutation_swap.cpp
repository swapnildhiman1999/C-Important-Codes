/*
Permutation Swaps
Send Feedback
Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

Swap Px and Py only if (x, y) is a good pair.
Help him and tell if Kevin can obtain permutation Q using such operations.
Input format:
The first line of input will contain an integer T, denoting the number of test cases.

Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.
Output format:
For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
1 ≤ ai < bi ≤ N
SAMPLE INPUT
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
SAMPLE OUTPUT
NO
YES
*/
#include<bits/stdc++.h>
using namespace std;
void DFS(unordered_set<int>* component,vector<int>* edges,bool *visited,int sv){
  component->insert(sv);
  visited[sv]=true;
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      DFS(component,edges,visited,next);
    }
  }
}
unordered_set<unordered_set<int>*>* getconnectedcomponents(vector<int>* edges,int total_vertices){
  //total_vertices is n+1 as indexing starts from 1
  //[0.....n]
  bool *visited=new bool[total_vertices];
  for(int i=0;i<total_vertices;i++){
    visited[i]=false;
  }
  unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>;
  for(int i=1;i<total_vertices;i++){
    if(!visited[i]){
      unordered_set<int>* component=new unordered_set<int>;
      DFS(component,edges,visited,i);
      output->insert(component);
    }
  }
  return output;
}
int main(){
  int t;
  cin>>t;
  while(t--){
  int n,m;
  cin>>n>>m;
  int *p=new int[n+1];
  int *q=new int[n+1];
  p[0]=q[0]=0;
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }
  for(int i=1;i<=n;i++){
    cin>>q[i];
  }
  vector<int> *edges=new vector<int>[n+1];
  //array where each element is a vector
  for(int i=0;i<m;i++){
    int j,k;
    cin>>j>>k;
    edges[j].push_back(k);
    edges[k].push_back(j);
  }
  unordered_set<unordered_set<int>*>* components=getconnectedcomponents(edges,n+1);
  unordered_set<unordered_set<int>*>::iterator it1=components->begin();
  bool bada_flag=true;
  while(it1!=components->end()){
    unordered_set<int>* component=*it1;
    unordered_set<int>::iterator it2=component->begin();
    while(it2!=component->end()){
      int val=*it2;
      bool flag=false;
      val=p[val];
      unordered_set<int>::iterator it_aise=component->begin();
      while(it_aise!=component->end()){
         int index=*it_aise;
         int q_val=q[index];
         if(val==q_val){
           flag=true;
         }
         it_aise++;
      }
      if(!flag){
        bada_flag=false;
      }
      it2++;
    }
    it1++;
  }
  if(bada_flag){cout<<"YES"<<endl;}
  else{cout<<"NO"<<endl;}
 }
}
