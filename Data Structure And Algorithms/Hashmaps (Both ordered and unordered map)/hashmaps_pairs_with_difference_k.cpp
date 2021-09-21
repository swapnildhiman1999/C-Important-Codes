/*
Pairs with difference K
Send Feedback
You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Take difference as absolute.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)
Constraints :
0 <= n <= 10^4
Sample Input 1 :
4
5 1 2 4
3
Sample Output 1 :
2 5
1 4
Sample Input 2 :
4
4 4 4 4
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4
*/

#include<unordered_map>
#include<bits/stdc++.h>
void printPairs(int *arr, int n, int k) {
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    if(k==0){
        for(int i=0;i<n;i++){
            int val=map[arr[i]];
            int total_times=(val*(val-1))/2;
            for(int j=0;j<total_times;j++){
                cout<<arr[i]<<" "<<arr[i]<<endl;
            }
            map[arr[i]]=0;
        }
    }
    else{
    for(int i=0;i<n;i++){
        int rem1=k+arr[i];
        int rem2=arr[i]-k;
        int freq=map[arr[i]];
        if(map.count(rem1)>0){
            int count1=map[arr[i]]*map[rem1];
            for(int j=0;j<count1;j++){
                cout<<min(arr[i],rem1)<<" "<<max(arr[i],rem1)<<endl;
            }
          }
       if(map.count(rem2)>0){
            int count2=map[arr[i]]*map[rem2];
            for(int j=0;j<count2;j++){
                  cout<<min(arr[i],rem2)<<" "<<max(arr[i],rem2)<<endl;
            }
          }
        map[arr[i]]=0;
    }
  }
}
