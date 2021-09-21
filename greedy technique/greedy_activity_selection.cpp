/*
Activity Selection
Send Feedback
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one lleger denoting N.
Next N lines contains two space separated llegers denoting the start time and finish time for the ith activity.

Output
Output one lleger, the maximum number of activities that can be performed
Constralls
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;
bool comparator(const pair<ll,ll> a,const pair<ll,ll> b)
  {   
      return a.second<b.second; 
  }
ll main()
{   ll n;
    cin>>n;
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++){
        pair<ll,ll> p;
        ll f,s;
        cin>>f>>s;
        p.first=f;
        p.second=s;
        v.push_back(p);
    }
    // for(ll i=0;i<v.size();i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    //sort this vector according to final time
    sort(v.begin(),v.end(),comparator)
    pair<ll,ll> curr_included_activity=v[0];
    ll ans_activites=1;//first one which is having least finishing time
    for(ll i=1;i<v.size();i++){
     if(v[i].first>=curr_included_activity.second){
       ans_activites+=1;
       curr_included_activity=v[i];
     }
    }
    cout<<ans_activites<<endl;
    return 0;
}
