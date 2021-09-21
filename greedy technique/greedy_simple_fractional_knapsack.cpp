#include<bits/stdc++.h>
using namespace std;
struct Item{
    ll value,weight;
};
bool myFunction(struct Item a, struct Item b){
    double val1=((double)a.value)/a.weight;
    double val2=((double)b.value)/b.weight;
    return val1>val2;
}
ll go(Item arr[],ll n,ll W){
    ll currW=0;
    double fVal=0;
    for(ll i=0;i<n;i++){
     if(currW+arr[i].weight<=W){
         currW+=arr[i].weight;
         fVal+=arr[i].value;
     }
     else{
         ll rWeight=W-currW;
         fVal+=arr[i].value*((double)rWeight/arr[i].weight);
         return fVal;
     }
    }
    return fVal;
}
ll main(){
  ll W=70;
  Item arr[]={{60,20},{70,15},{80,40}};
  cout<<go(arr,3,W)<<endl;
  return 0;
}