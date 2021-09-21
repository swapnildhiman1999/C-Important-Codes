/*Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/





#include<bits/stdc++.h>
#define pb push_back
using namespace std;
bool hasPath(int n,int **edges,int sv,int ev,bool* visited){
  if(edges[sv][ev]==1){
    return true;
  }
  visited[sv]=true;
  for(int i=0;i<n;i++){
    if(edges[sv][i]==1 && !visited[sv]){
      bool ans=hasPath(n,edges,i,ev,visited);
      if(ans){return ans;}
    }
  }
  return false;
}

class Edge{
  public:
  int source,destination,weight;
};

bool comparator(Edge a, Edge b){
  return a.weight<b.weight;
}
//will give you topmost parent
int getParent(int v,int *parent){
  if(parent[v]==v){
  return v;
  }
  return getParent(parent[v],parent);
}
//using union find algorithm to detect cycle- O(V) for one go
void Kruskal_MST(vector<Edge> input,vector<Edge> &output,int n,int e){
       int count=0;
       int i=0;
       int parent[n];
       for(int i=0;i<n;i++){
         parent[i]=i;
       }
       while(count< n-1 && i<input.size()){
         int v1=input[i].source;
         int v2=input[i].destination;
         int wt=input[i].weight;
         int p1=parent[v1],p2=parent[v2];//topmost parent ka account rkhega
         while(p1!=parent[p1]){
           v1=parent[v1];
           p1=parent[v1];
         }
         while(p2!=parent[p2]){
           v2=parent[v2];
           p2=parent[v2];
         }
          v1=input[i].source;
          v2=input[i].destination;
          if(p1==p2){
            i++;
            continue;
          }
          i++;
          Edge a;
          a.source=v1;
          a.destination=v2;
          a.weight=wt;
          output.pb(a);
          parent[p2]=p1;
          count++;
       }
}


int main(){
  /*{// int n,e;
  // cin>>n>>e;
  // int **edges=new int*[n];
  // for(int i=0;i<n;i++){
  //   edges[i]=new int[n];
  //   for(int j=0;j<n;j++){
  //     edges[i][j]=0;
  //   }
  // }
  // for(int i=0;i<e;i++){
  //   int f,s,weight;
  //   cin>>f>>s>>weight;
  //   edges[f][s]=weight;
  //   edges[s][f]=weight;
  // }
  // bool *visited=new bool[n];
  // memset(visited,false,n);
}*/
  int n,e;
  cin>>n>>e;
  vector<Edge> input;
  for(int i=0;i<e;i++){
    int v1,v2,wt;
    cin>>v1>>v2>>wt;
    Edge a;
    a.source=v1;
    a.destination=v2;
    a.weight=wt;
    input.pb(a);
  }
  sort(input.begin(),input.end(),comparator);
  vector<Edge> output;
  //MST is
  Kruskal_MST(input,output,n,e);
  for(int i=0;i<output.size();i++){
      int mini=min(output[i].source,output[i].destination);
      int maxi=max(output[i].source,output[i].destination);
       cout<<mini<<" "<<maxi<<" "<<output[i].weight<<endl;
  }
  return 0;
}
