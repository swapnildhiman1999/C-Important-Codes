/*
Save Energy Problem Code: SVENGY
Add problem to Todo list
Submit

 
There are N towns in a line, numbered from 0 to N - 1. Starting from town 0, we want to reach town N - 1. From town i, we can jump to any town j > i with an energy cost of (j-i)*A[i] + (j2 - i2)*A[i]2, where A[i] for all i are given in input.

Find the minimum total energy cost to reach town N - 1 from town 0.

Input

The first line contains a single lleger, N.
The next line contains N space separated llegers, ith lleger denoting the value of A[i] , 0 ≤ i ≤ N - 1.
Output
Output the minimum cost to reach town N.

Constralls
1 ≤ N ≤ 105
-103 ≤ A[i] ≤ 103
Example 1

Input:
5
1 -1 2 2 2

Output:
14
Example 2

Input:
4
2 2 3 4

Output:
42
*/
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll i=0,j=1;
    ll cost=0;
    while(j<n-1){
        if(abs(arr[i])>abs(arr[j])){
            cost+=((j-i)*arr[i])+((pow(j,2)-pow(i,2))*pow(arr[i],2));
            i=j;
        }
        else if(abs(arr[i])==abs(arr[j]) && arr[i]>0){
            cost+=((j-i)*arr[i])+((pow(j,2)-pow(i,2))*pow(arr[i],2));
            i=j;
        }
        j++;
    }
    if(cost==0){
        ll k=n-1;
        //cost of direct 0 and n-1
        ll cost1=((k-0)*arr[0])+((pow(k,2)-pow(0,2))*pow(arr[0],2));
        cout<<cost1<<endl;
    }
    else{
       ll k=n-1;
       cost+=((k-i)*arr[i])+((pow(k,2)-pow(i,2))*pow(arr[i],2));
       cout<<cost<<endl;
    }
    return 0;
}