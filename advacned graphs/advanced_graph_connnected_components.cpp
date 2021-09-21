#include<bits/stdc++.h>
using namespace std;
void DFS(unordered_set<int>* component,vector<int>* edges,bool*visited,int sv){
  visited[sv]=true;
  component->insert(sv);
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      DFS(component,edges,visited,next);
    }
  }
}
unordered_set<unordered_set<int>*>*  getcomponents(vector<int>*edges,int n){
  bool *visited = new bool[n];
  for(int i=0;i<n;i++){visited[i]=false;}
  unordered_set<unordered_set<int>*>* output=new   unordered_set<unordered_set<int>*>();
  for(int i=0;i<n;i++){
    if(!visited[i]){
       unordered_set<int>* component=new unordered_set<int>();
       DFS(component,edges,visited,i);
       output->insert(component);
     }
    }
    return output;
}
int main(){
  int n,m;
  cin>>n>>m;
  //array in which each element is vector
  vector<int> * edges=new vector<int>[n];
  for(int i=0;i<m;i++){
    int j,k;
    cin>>j>>k;
    edges[j-1].push_back(k-1);
    edges[k-1].push_back(j-1);
  }
    unordered_set<unordered_set<int>*>* components=getcomponents(edges,n);
    unordered_set<unordered_set<int>*>::iterator it1=components->begin();
    while(it1!=components->end()){
      unordered_set<int>* component=*it1;
      unordered_set<int>::iterator it2=component->begin();
      while(it2!=component->end()){
        cout<<*it2+1<<" ";
        it2++;
      }
      cout<<endl;
      it1++;
    }
}
