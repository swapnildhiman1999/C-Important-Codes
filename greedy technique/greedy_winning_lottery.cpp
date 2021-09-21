/*
Winning Lottery
Send Feedback
Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.
*/
#include<bits/stdc++.h>
using namespace std;
void findAns(int n,int s){
    if(s>9*n){
        return;
    }
    if(s==0){
        if(n==1){
          cout<<'0'<<endl;
          return; 
        }
    }
    s-=1;
    for(int i=n-1;i>=1;i--){
        if(s>9){
            arr[i]=9;
            s-=9;
        }
        else{
            arr[i]=s;
            s=0;
        }
    }
    if(s==0){
        arr[0]=1;
    }
    else{
        arr[0]=s;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
    int d,s;
    cin>>d>>s;
    int n=d;
    findAns(n,s);
    return 0;
}