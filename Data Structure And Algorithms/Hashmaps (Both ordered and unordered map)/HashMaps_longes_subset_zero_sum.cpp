/*
Longest subset zero sum
Send Feedback
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
NOTE: You have to return the length of longest subarray .
Input Format :
Line 1 : Contains an integer N i.e. size of array

Line 2 : Contains N elements of the array, separated by spaces
Output Format
 Line 1 : Length of longest subarray
Constraints:
0 <= N <= 10^8
Sample Input :
10
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output :
5
*/
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  //converting it into prefix sum
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
        arr[i]=sum;
    }
   int m=0;
   unordered_map<int,int> map;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            m=i+1;
        }
       else if(map.count(arr[i])>0){
           if(m<i-map[arr[i]]){
            m=i-map[arr[i]];
           }
       }
        else{
            map[arr[i]]=i;
        }
    }
    return m;
}
