/*
Min. Absolute Difference In Array
Send Feedback
Given an lleger array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
Input format :
Line 1 : lleger N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Minimum difference
Constralls :
1 <= N <= 10^6
Sample Input :
5
2 9 0 4 5
Sample Input :
1
*/
#include <iostream>
using namespace std;
ll minAbsoluteDiff(ll *input,ll size){
    sort(input,input+size);
    ll min_diff=arr[1]-arr[0];
    for(ll i=0;i<size-1;i++){
       ll curr_diff=arr[i+1]-arr[i];
       if(min_diff>curr_diff){
           min_diff=curr_diff;
    }
    return min_diff;
}
ll main() {
    ll size;
	cin >> size;
	ll *input = new ll[1 + size];
	for(ll i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsoluteDiff(input,size) << endl;
	return 0;
}
