#include<bits/stdc++.h>
using namespace std;
int fibb_simple(int n){
  if(n<=1){return n;}
  int a=fibb_simple(n-1);
  int b=fibb_simple(n-2);
  return a+b;
}
int fibb_itr(int n){
  int arr[n+1];
  arr[0]=0;
  arr[1]=1;
  for(int i=2;i<=n;i++){
    arr[i]=arr[i-1]+arr[i-2];
  }
  return arr[n];
}
int fibb_helper(int n,int arr[],int size){
  if(n<=1){
    arr[n]=n;
    return n;
  }
  if(arr[n]!=-1){
    return arr[n];
  }
  int a=fibb_helper(n-1,arr,size);
  int b=fibb_helper(n-2,arr,size);
  arr[n]=a+b;
  return a+b;
}
int fibb_memo(int n){
  int arr[n+1];
  for(int i=0;i<=n;i++){
    arr[i]=-1;
  }
  return fibb_helper(n,arr,n+1);
}
int main(){
  int n;
  cin>>n;
  cout<<fibb_itr(n)<<endl;
}
