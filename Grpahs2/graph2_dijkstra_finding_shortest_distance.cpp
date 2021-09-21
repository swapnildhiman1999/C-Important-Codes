/*
Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/
#include<bits/stdc++.h>
using namespace std;
int getmindistance(int *distance,bool *visited,int n){
  int min_index=-1;
  for(int i=0;i<n;i++)
  {
    if(!visited[i] && (min_index==-1 || distance[i]<distance[min_index])){
      min_index=i;
    }
  }
  return min_index;
}
void Dijkstra(int **edges,int n){
  bool *visited=new bool[n];
  int *distance=new int[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
    distance[i]=INT_MAX;
  }
  distance[0]=0;//considering 0 as source Vertex
  for(int count=0;count<n-1;count++){
    int u=getmindistance(distance,visited,n);
    visited[u]=true;
    for(int i=0;i<n;i++){
      if(edges[u][i]!=0 && !visited[i]){
        if(distance[i]>(distance[u]+edges[u][i])){
          distance[i]=distance[u]+edges[u][i];
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<i<<" "<<distance[i]<<endl;
  }
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
    int s,d,w;
    cin>>s>>d>>w;
    edges[s][d]=w;
    edges[d][s]=w;
  }
  Dijkstra(edges,n);
  for(int i=0;i<n;i++){delete[] edges[i];}
  delete [] edges;
}
