/*
All possible ways
Send Feedback
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2
Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)
Output Format :
Count
Constraints :
1 <= a <= 10^5
1 <= b <= 50
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
*/

#include<iostream>
#include<cmath>
using namespace std;
int allWaysHelper(int x,int n,int num){
    int val=x-int(pow(num,n));
    if(val==0){
        return 1;
    }
    if(val<0){
        return 0;
    }
    return allWaysHelper(val,n,num+1)+allWaysHelper(x,n,num+1);
}
int allWays(int x, int n) {
return allWaysHelper(x,n,1);
}
#include <iostream>
using namespace std;
#include "Solution.h"

int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}
