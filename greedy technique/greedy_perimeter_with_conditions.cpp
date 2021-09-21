#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool myFunction(ll a,ll b){
    return a>b;
}
bool myFunction2(vector<ll> a,vector<ll> b){
    if(a[3]==b[3]){
     if(a[0]==b[0]){
       return a[2]>b[2];
     }
     return a[0]>b[0];
    }
    return a[3]>b[3];
}
/*
ll main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,myFunction);
    vector<vector<ll>> possibilties;
    for(ll first=0;first<=n-3;first++){
     for(ll second=1;second<=n-2;second++){
         for(ll third=2;third<=n-1;third++){
          if(arr[first]<(arr[second]+arr[third])){
              vector<ll> v;
              ll perimeter=arr[first]+arr[second]+arr[third];
              v.push_back(arr[first]);
              v.push_back(arr[second]);
              v.push_back(arr[third]);
              v.push_back(perimeter);
              possibilties.push_back(v);
          } 
         }
      } 
    }
    if(possibilties.size()>0){
    sort(possibilties.begin(), possibilties.end(),myFunction2);
    cout<<possibilties.at(0)[0]<<" "<<possibilties.at(0)[1]<<" "<<possibilties.at(0)[2]<<endl;
    }
    else{
     cout<<"-1"<<endl;
    }
    return 0;
}
*/
ll main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll i=n-3;
    while(i>=0 && arr[i]+arr[i+1]<=arr[i+2]){
        i--;
    }
    if(arr[i]+arr[i+1]>arr[i+2]){
        cout<<arr[i]<<" "<<arr[i+1]<<" "<<arr[i+2]<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}