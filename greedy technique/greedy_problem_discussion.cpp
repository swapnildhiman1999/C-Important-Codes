/*
Problem discussion
Send Feedback
Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help
Input Format
The First line contains two space-separated llegers: N,K
Next lines contain N space-separated llegers denoting elements of the array
Output Format
The output contains a single lleger denoting the minimum difference between maximum value and the minimum value in the array
Constralls
1 =< N <= 10^5 
1 <= Ai,K <= 10^9
Sample Input1:
3 6
1 15 10
Sample Output1:
5
Explaination
We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.


Code Pair

>
1
#include<bits/stdc++.h>
2
using namespace std;
3
ll main() {
4
​
5
    // Write your code here
6
}

CUSTOM INPUT


SUBMIT SOLUTION


PREVIOUS
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll ans=arr[n-1]-arr[0];
    ll big=arr[n-1]-k;
    ll small=arr[0]+k;
    if(small>big){
        swap(small,big);
    }
    for(ll i=1;i<=n-2;i++){
      ll subst=arr[i]-k;
      ll add=arr[i]+k;
      //condition when no effect on big or small 
      if(subst>=small || add<=big){
          continue;
      }
      if(big-subst<=add-small){
          small=subst;
      }
      else{
         big=add;
      }
    }
    cout<<min(ans,big-small)<<endl;
    return 0;
}