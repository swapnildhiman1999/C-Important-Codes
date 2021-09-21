/*
Longest Increasing Subsequence
Send Feedback
Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
Line 1 : An integer N
Line 2 : Elements of arrays separated by spaces
Output Format
Line 1 : Length of longest subsequence
Input Constraints
1 <= n <= 10^3
Sample Input :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2:
3
1 2 2
Sample Output 2 :
2
*/

#include<iostream>
using namespace std;

 int lis(int arr[], int n) {
	int lis_arr[n];
     int maxi=1;
     lis_arr[0]=1;
     for(int i=1;i<n;i++){
         lis_arr[i]=1;
         for(int j=i-1;j>=0;j--){
             if(arr[i]>arr[j]){
                 lis_arr[i]=max(lis_arr[i],lis_arr[j]+1);
             }
         }
         maxi=max(maxi,lis_arr[i]);
     }
   return maxi;
 }

#include <iostream>
#include "solution.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << lis(arr, n);
}
