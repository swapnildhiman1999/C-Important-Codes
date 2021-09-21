/*
Dilemma
Send Feedback
Abhishek, a blind man recently bought N binary strings all of equal length .A binary string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek can identify one character at a position of a string from the set. Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different .
Constraints :
2<=N<=10
1<=|L|<=100 , L is length of the strings .
Input Format:
Line 1 : An Integer N, denoting the number of binary strings .
Next N lines : strings of equal length
Output Format:
Return the minimum number of touches
Sample Input :
2
111010
100100
Sample Output :
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


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
         merge(arr, l, m, r);
    }
}
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    // base case
    if (a == b)
        return a;
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

/*
int minimumTouchesRequired(int n, vector<string> v) {
    if(v.size()==1){
      //1 string is present only, no touches required
      return 0;
    }
   //if(v[0].size()==0){return 0;}
    vector<int> index0;
    vector<int> index1;
    int count0=0;
    int count1=0;
    for(int i=0;i<v.size();++i){
      if(v[i][0]=='0'){
          count0++;
        index0.pb(i);//those strings which have 0index as 0
      }
      else{
          count1++;
        index1.pb(i);
      }
    }
    vector<string> v0;
    for(int i=0;i<index0.size();i++){
      if(v[index0[i]].size()>1){
      string a=v[index0[i]].substr(1);
      v0.pb(a);
      }
    }
    vector<string> v1;
    for(int i=0;i<index1.size();i++){
      if(v[index1[i]].size()>1){
      string a=v[index1[i]].substr(1);
      v1.pb(a);
      }
    }
    vector<string> v2;
    int count3=0;
    for(int i=0;i<v.size();++i){
      if(v[i].size()>1){
      count3++;
      string a=v[i].substr(1);
      v2.pb(a);
     }
    }
  int a=v.size()+minimumTouchesRequired(count0,v0)+minimumTouchesRequired(count1,v1);
  int  b=minimumTouchesRequired(count3,v2);
  int ans=min(a,b);
  return ans;
}*/
int minimumTouchesRequiredHelper(int pos,vector<string> v,int mask){
  if((mask&(mask-1))==0 && mask){
    //if mask contains only one bit means only one string is left to examine
    return 0;
  }
  if(pos==-1){return INT_MAX;}

}
int minimumTouchesRequired(int n,vector<string> v){
  return minimumTouchesRequiredHelper(v[0].size()-1,v,(1<<n)-1);//currently working on all the strings
}
int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;

vector<string> v;

cin >> n;
for(int i = 0; i < n; i++) {
string a;
cin >> a;
v.push_back(a);
}
cout << minimumTouchesRequired(n, v) << endl;

}
