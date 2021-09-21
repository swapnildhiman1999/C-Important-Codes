/*
Connected horses
Send Feedback
You all must be familiar with the chess-board having
8*8 squares of alternate black and white cells. Well, here
we have for you a similar
N*M size board with similar arrangement of black and white
cells.
A few of these cells have Horses placed over them.
Each horse is unique. Now these horses are not the
usual horses which could jump to any of the
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo
10^9+7
Input:
First line contains
T which is the number of test cases.
T test cases follow first line of each containing three integers
N, M and Q where
N,M is the size of the board and
Q is the number of horses on it.

Q lines follow each containing the 2 integers
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/
/*
{#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
long long int factorial(long long int n){
  long long int *result=new long long int[n+1];
  result[0]=1;
  if(n>=0){
    for(int i=1;i<=n;i++){
      result[i]=(result[i-1]*i)%mod;
    }
  }
  return result[n];
}
bool isSafe(int n,int m,int x,int y){
  if(x>=0 && x<n && y>=0 && y<m){
    return true;
  }
  return false;
}
void DFS(vector<int>*edges, unordered_set<int>* component,bool *visited,int sv){
  visited[sv]=true;
  component->insert(sv);
  for(int i=0;i<edges[sv].size();i++){
    int next=edges[sv][i];
    if(!visited[next]){
      DFS(edges,component,visited,next);
    }
  }
}
unordered_set<unordered_set<int>*>* getconnectedcomponents(vector<int>*edges,int q){
  bool *visited=new bool[q];
  memset(visited,false,sizeof(visited));
  unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>;

  for(int i=0;i<q;i++){
    if(!visited[i]){
        unordered_set<int>* component=new unordered_set<int>;
        DFS(edges,component,visited,i);
        output->insert(component);
    }
  }
  return output;
}
int main(){
  int t;
  cin>>t;
  while(t--){
  int n,m,q;
  cin>>n>>m>>q;
  vector<pair<int,int>> horses;
  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    horses.pb(make_pair(x,y));
  }
  //as number of horses are my number of vertices
  vector<int>*edges=new vector<int>[q];
  for(int i=0;i<q;i++){
    pair<int,int> pair_s=horses[i];
    int x=pair_s.first;
    int y=pair_s.second;
    int o1a=x-2,o1b=y-1;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }


    o1a=x-2,o1b=y+1;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }


    o1a=x-1,o1b=y+2;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }

    o1a=x+1,o1b=y-2;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }


    o1a=x+2,o1b=y+1;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }


    o1a=x+2,o1b=y-1;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }


    o1a=x+1,o1b=y-2;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }


    o1a=x-1,o1b=y-2;
    if(isSafe(n,m,o1a,o1b)){
      for(int j=0;j<q;j++){
        if(o1a==horses[j].first && o1b==horses[j].second){
          //pair found means edge
          edges[i].pb(j);
        }
      }
    }
  }
  //edges adj list is ready
  long long int ans=1;
   unordered_set<unordered_set<int>*>* components=getconnectedcomponents(edges,q);
   unordered_set<unordered_set<int>*>::iterator it1=components->begin();
   while(it1!=components->end()){
     unordered_set<int>* component=*it1;
     long long int val=component->size();
     val=factorial(val);
     //val=val%mod;
     ans=(ans*val)%mod;
     it1++;
   }
   cout<<ans<<endl;
 }
 return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

long long n , m , q , x , y, tem1, tem2 , t, sum, mod = 1e9 + 7, ans;

bool vis [1000 + 1][1000 + 1];
bool arr [1000 + 1][1000 + 1];
long long factorial [1000000 + 1];

int dirc [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };

void pre_calculate(){       // calculating factorial

    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

void dfs(int x, int y){

    vis[x][y] = true;
    sum++;

    for(int i = 0; i < 8; i++){                     // check for the 8 movements

        int dx = x + dirc[i][0];
        int dy = y + dirc[i][1];

        if(dx <= 0 || dx > n || dy <= 0 || dy > m) continue;        // out of board
        if(vis[dx][dy] || !arr[dx][dy]) continue;                   // check if the cell is visited or doesn't contain a horse
        dfs(dx, dy);

    }

}


int main()
{

    pre_calculate();

    cin >> t;

    while(t--){

        cin >> n >> m >> q;

        ans = 1;

        for(int i = 0; i <= n; i++){                // reset arrays in each test case

            for(int j = 0; j <= m; j++){

                vis[i][j] = false;
                arr[i][j] = false;
            }
        }

        for(int i = 0; i < q; i++){

            cin >> tem1 >> tem2;
            arr[tem1][tem2] = true;
        }

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                if(!vis[i][j] && arr[i][j]){

                    sum = 0;
                    dfs(i , j);                             // begin dfs from that unvisited horse (New group of connected horses)
                    ans = (ans * factorial[sum]) % mod;     // number of arrangements
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
