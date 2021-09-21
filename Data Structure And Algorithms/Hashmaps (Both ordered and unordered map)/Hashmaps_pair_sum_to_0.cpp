/*
Code : Pair Sum to 0
Send Feedback
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
0 <= N <= 10^4
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2
*/
#include<unordered_map>
#include<iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
#include "solution.h"


void pairSum(int *input, int n)
{
  void pairSum(int *input, int n)
{/*
approach_1
  unordered_map<int,int> freq;
   for(int i=0;i<n;i++){
     freq[input[i]]++;
   }
   for(int i=0;i<n;i++){
     if(input[i]==0 && freq.count(input[i])>0){
         int val_0=freq[input[i]];
         //nc2 will be number of times we should print these
         int total_count=((val_0)*(val_0-1))/2;
         for(int j=0;j<total_count;j++){
             cout<<"0"<<" "<<"0"<<endl;
         }
         freq.erase(0);
     }
     else if(freq.count(-1*input[i])>0){
       int val1=freq[input[i]];
       int val2=freq[-1*input[i]];
       for(int j=0;j<val1*val2;++j){
         cout<<min(input[i],-1*input[i])<<" "<<max(input[i],-1*input[i])<<endl;
       }
         freq.erase(input[i]);
         freq.erase(-1*input[i]);
     }
   }
   */
    //approach_2
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        if(map.count(-1*input[i])>0){
            int val=map[-1*input[i]];
            for(int i=0;i<val;i++){
                cout<<min(input[i],-1*input[i])<<" "<<max(input[i],-1*input[i])<<endl;
            }
        }
        map[input[i]]++;
    }
 }
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}
