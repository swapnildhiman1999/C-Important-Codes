#include<bits/stdc++.h>
using namespace std;
#define pb push_back
void printDFS(int **edges,int n,int sv,bool *visited){
  cout<<sv<<endl;
  visited[sv]=true;
  for(int i=0;i<n;i++){
    if(i==sv){
      continue;
    }
    if(edges[sv][i]==1){
      if(visited[i]){
        continue;
      }
      printDFS(edges,n,i,visited);
    }
  }
}
void printBFS(int **edges,int n,int sv,bool *visited){
  queue<int> adj;
  adj.push(sv);
  visited[sv]=true;
  while(!adj.empty()){
    int var;
    var=adj.front();
    cout<<var<<" ";
    adj.pop();
    for(int i=0;i<n;i++){
      if(edges[var][i]==1){
        if(visited[i]){
          continue;
        }
        adj.push(i);
        visited[i]=true;
      }
    }
  }
}
//for disconnected graph
void BFS(int **edges,int n){
  bool *visited=new bool[n];
  memset(visited,false,n);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      printBFS(edges,n,i,visited);
    }
  }
  delete[] visited;
}
void DFS(int **edges,int n){
  bool *visited=new bool[n];
  memset(visited,false,n);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      printDFS(edges,n,i,visited);
    }
  }
  delete[] visited;
}
bool hasPath(int **edges,int n,int sv,int ev,bool * visited){
   if(edges[sv][ev]==1){
     return true;
   }
   visited[sv]=true;
   for(int i=0;i<n;i++){
     if(!visited[i] && edges[i][sv]==1){
       bool ans=hasPath(edges,n,i,ev,visited);
       if(ans){
         return true;
       }
     }
   }
   return false;
}
bool getPathDFS(int **edges,int n,int sv,int ev,vector<int> &answer,bool* visited){
  visited[sv]=true;
  if(sv==ev){
    answer.push_back(ev);
    return true;
  }
  for(int i=0;i<n;i++){
    if(!visited[i] && edges[sv][i]==1){
      bool ans=getPathDFS(edges,n,i,ev,answer,visited);
      if(ans){
        answer.push_back(sv);
        return true;
      }
    }
  }
  return false;
}
vector<int> *getPathBFS(int **edges,int n,int sv,int ev,bool *visited){
  queue<int> pendingVertices;
  unordered_map<int,int> parent;
  pendingVertices.push(sv);
  visited[sv]=true;
  bool done=false;
  while(!done && !pendingVertices.empty()){
    int var=pendingVertices.front();
    pendingVertices.pop();
    for(int i=0;i<n;i++){
      if(edges[var][i]==1 && !visited[i]){
        parent[i]=var;
        pendingVertices.push(i);
        if(i==ev){
          done=true;
          break;
        }
      }
    }
  }
  if(!done){
    return NULL;
  }
  else{
    vector<int> *output=new vector<int>();
    int curr=ev;
    output->push_back(curr);
    while(curr!=sv){
        curr=parent[curr];
        output->push_back(curr);
    }
    return output;
  }
}
void simpleDFS(int **edges,int n,vector<int>* answer,bool *visited,int sv){
  answer->pb(sv);
  visited[sv]=true;
  for(int i=0;i<n;i++){
    if(edges[sv][i]==1 && !visited[i]){
      simpleDFS(edges,n,answer,visited,i);
    }
  }
}
bool isConnected(int **edges,int n){
  bool *visited=new bool[n];
  memset(visited,false,n);
  vector<int> *answer=new vector<int>();//holds DFS for the complete graph
  simpleDFS(edges,n,answer,visited,0);
  for(int i=0;i<n;i++){
    if(!visited[i]){return false;}
  }
  return true;
}
void DFS_acc(int **edges,int n,int sv,bool *visited,vector<int> *ans){
  ans->pb(sv);
  visited[sv]=true;
  for(int i=0;i<n;i++){
    if(edges[sv][i]==1 && !visited[i]){
      DFS_acc(edges,n,i,visited,ans);
    }
  }
}
vector<vector<int>*>* allConnectedComponents(int **edges,int n){
  vector<vector<int>*>* output=new vector<vector<int>*>;
  bool * visited=new bool[n];
  memset(visited,false,n);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      vector<int>* ans=new vector<int>();
      DFS_acc(edges,n,i,visited,ans);
      output->pb(ans);
    }
  }
  return output;
}
int main(){
  int n,e;
  cin>>n>>e;
  int **edges=new int*[n];
  for(int i=0;i<n;i++){
    edges[i]=new int[n];
    for(int j=0;j<n;j++){
      edges[i][j]=0;
    }
  }
  for(int i=0;i<e;i++){
    int f,s;
    cin>>f>>s;
    edges[f][s]=1;
    edges[s][f]=1;
  }
  // cout<<"DFS"<<endl;
  // DFS(edges,n);
  // cout<<"BFS"<<endl;
  // BFS(edges,n);
  bool *visited=new bool[n];
  memset(visited,false,n);
  // int sv,ev;
  // cin>>sv>>ev;
  // if(hasPath(edges,n,sv,ev,visited)){
  //   cout<<"true"<<endl;
  // }
  // else{
  //   cout<<"false"<<endl;
  // }
  //  vector<int> answer;
  // if(getPathDFS(edges,n,sv,ev,answer,visited)){
  //   for(int i=0;i<answer.size();i++){
  //     cout<<answer[i]<<" ";
  //   }
  // }
  // vector<int> *output=getPathBFS(edges,n,sv,ev,visited);
  // for(int i=0;i<output->size();i++){
  //   cout<<output->at(i)<<" ";
  // }
  // if(isConnected(edges,n)){
  //   cout<<"true"<<endl;
  // }
  // else{
  //   cout<<"false"<<endl;
  // }
  vector<vector<int>*>* output=new vector<vector<int>*>;
  output=allConnectedComponents(edges,n);
  for(int i=0;i<output->size();i++){
    sort(output[i]->begin(),output[i]->end());
    for(int j=0;j<output[i]->size();j++){
      cout<<output->at(i)(j)<<" ";
    }
    cout<<endl;
  }
  for(int i=0;i<n;i++){
    delete edges[i];
  }
  delete[] edges;
}
