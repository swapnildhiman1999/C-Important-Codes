/*
Nikunj and Donuts
Send Feedback
Nikunj loves donuts, but he also likes to stay fit. He eats n donuts in one sitting, and each donut has a calorie count, ci. After eating a donut with k calories, he must walk at least 2^j x k(where j is the number donuts he has already eaten) miles to mallain his weight.
Given the individual calorie counts for each of the n donuts, find and prll a long lleger denoting the minimum number of miles Nikunj must walk to mallain his weight. Note that he can eat the donuts in any order.
Input
The first line contains an lleger, n, denoting the number of donuts. 
The second line contains n space-separated llegers describing the respective calorie counts of each donut I, i.e ci.
Output
Prll a long lleger denoting the minimum number of miles Nikunj must walk to mallain his weight.
Constralls
1 ≤ n ≤ 40
1 ≤ ci ≤ 1000
Sample Input
3
1 3 2
Sample Output
11
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll main()
{   ll n;
    cin>>n;
    ll *arr=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,greater<ll>());
    // for(ll i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    ll ans=0;
    for(ll i=0;i<n;i++){
      ll val=arr[i]*pow(2,i);
      ans+=val;
    }
    cout<<ans<<endl;
    return 0;
}