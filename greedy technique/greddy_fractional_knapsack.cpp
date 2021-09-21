/*
Fractional Knapsack
Send Feedback
You want to pall your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start palling the house immediately, covering exactly Yi units of house with pall per time unit. You may or may not hire a worker and can also hire or fire him at any later poll of time. However, no more than 1 worker can be palling the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets palled at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two llegers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three llegers "Ti Xi Yi", described in the statement.
Output
Output one lleger, the minimum cost that you can spend in order to get your house palled at the earliest.
Constralls
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool myFunction(vector<ll> a,vector<ll> b){
    //priority has been given to the time of completion 
    if(a[0]==b[0]){
        if(a[2]==b[2]){
            return a[1]<b[1];
        }
        return a[2]>b[2];
    }
    return a[0]<b[0];
}
//cost can't be fractional
ll go(vector<vector<ll>> v,ll d){
    ll area=0,cost=0,bestSpeed=0,lastTime=v.at(0)[0];
    for(ll i=0;i<v.size();i++){
      ll additional_area=bestSpeed*(v.at(i)[0]-lastTime);
      area+=additional_area;
      if(area>=d){
          break;
      }
      if(v.at(i)[2]>bestSpeed){
          bestSpeed=v.at(i)[2];
          cost+=v.at(i)[1];
      }
      lastTime=v.at(i)[0];
    }
    return cost;
}
ll main(){
    ll n,d;
    cin>>n>>d;
    vector<vector<ll>> v;
    for(ll i=0;i<n;i++){
        ll t,x,y;
        cin>>t>>x>>y;
        vector<ll> temp;
        temp.push_back(t);
        temp.push_back(x);
        temp.push_back(y);
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),myFunction);
    cout<<go(v,d)<<endl;
    return 0;
}