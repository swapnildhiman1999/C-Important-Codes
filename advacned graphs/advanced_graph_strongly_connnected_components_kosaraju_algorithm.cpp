#include<bits/stdc++.h>
#define pb push_back
using namespace std;
//kosaraju algorithm for finding SCC by using DFS,stack and inverted(transposed) graph

void dfs1(vector<int>* edges,stack<int> &finishedVertices,bool *visited,int sv){
  visited[sv]=true;
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      dfs1(edges,finishedVertices,visited,next);
    }
  }
  finishedVertices.push(sv);
}

void dfs2(vector<int> *edges,bool *visited,int sv,unordered_set<int>* component){
  visited[sv]=true;
  component->insert(sv);
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      dfs2(edges,visited,next,component);
    }
  }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int> *edges,vector<int> *edgesT,int n){
  //create stack on the basis of finishing time by applying DFS on edges
  bool *visited=new bool[n];
  memset(visited,false,sizeof(visited));
  stack<int> finishedVertices;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      dfs1(edges,finishedVertices,visited,i);
    }
  }
  //stack is ready
  //now do dfs on edgesT by picking elements from the top of stack
  bool *visited2=new bool[n];
  memset(visited2,false,n*sizeof(bool));
  unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
  while(!finishedVertices.empty()){
    int element=finishedVertices.top();
    finishedVertices.pop();
    if(visited2[element]){continue;}
    unordered_set<int>* component=new unordered_set<int>();
    dfs2(edgesT,visited2,element,component);
    output->insert(component);
  }
  return output;
}

int main(){
  int n;
  cin>>n;
  vector<int> *edges=new vector<int>[n];
  vector<int>* edgesT=new vector<int>[n];
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int j,k;
    cin>>j>>k;
    edges[j-1].pb(k-1);
    edgesT[k-1].pb(j-1);
  }
  //adj list is ready
    unordered_set<unordered_set<int>*>* components=getSCC(edges,edgesT,n);
    unordered_set<unordered_set<int>*>::iterator it=components->begin();
    while(it!=components->end()){
         unordered_set<int>* component=*it;
         unordered_set<int>::iterator it2=component->begin();
         while(it2!=component->end()){
           cout<<*it2+1<<" ";
           it2++;
         }
         cout<<endl;
         it++;
    }
    return 0;
}
