/*
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one lleger denoting N.
Next N lines contains three space separated llegers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one lleger, the maximum profit that can be achieved.
Constralls
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250


Code Pair

1
#include<bits/stdc++.h>
2
using namespace std;
3
ll main()
4
{
5
    ll start_time;
6
    ll 
7
    return 0;
8
}

CUSTOM INPUT


SUBMIT SOLUTION


PREVIOUS
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Job{
    public:
    ll start,finish,profit;
};
bool myFunction(Job a,Job b){
    return a.finish<b.finish;
}
ll binary_search(Job arr[],ll si,ll ei,ll target_index){
    if(si>ei){
        return -1;
    }
    if(si==ei){
        if(arr[si].finish<=arr[target_index].start){
            return si;
        }
        else return -1;
    }
    ll mid=si+(ei-si)/2;
    if(arr[mid].finish<=arr[target_index].start){
        ll answer=binary_search(arr,mid+1,ei,target_index);
        if(answer==-1){
            return mid;
        }
    }
    return binary_search(arr,si,mid-1,target_index);
}
ll go(Job arr[],ll n){
    sort(arr,arr+n,myFunction);
    ll *dp=new ll[n];
    dp[0]=arr[0].profit;
    for(ll i=1;i<n;i++){
        ll include=arr[i].profit;
        ll id=-1;//excluding the element
        //including arr[i-1]th element-finding the first non conflicting job present at jth index
        // ll j=i-1;
        // for(;j>=0;j--){
        //     if(arr[j].finish<=arr[i].start){
        //        id=j;
        //        break;
        //     }
        // }
        id=binary_search(arr,0,i-1,i);
        if(id!=-1){
            include+=dp[id];
        }
        dp[i]=max(dp[i-1],include);
    }
    return dp[n-1];
}
ll main(){
    ll n;
    cin>>n;
    Job arr[n+1];
    for(ll i=0;i<n;i++)
    {   ll st,ft,pf;
        cin>>st>>ft>>pf;
        arr[i].start=st;
        arr[i].finish=ft;
        arr[i].profit=pf;
    }
    cout<<go(arr,n)<<endl;
    return 0;
}