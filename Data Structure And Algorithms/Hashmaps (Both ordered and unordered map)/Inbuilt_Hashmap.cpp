#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;


int highestFrequency(int *a, int n){
  unordered_map<int,int> fr;
      int max=INT_MIN;
      int ans=a[0];
      for(int i=0;i<n;i++){
          fr[a[i]]++;
          if(max<fr[a[i]]){
              max=fr[a[i]];
              ans=a[i];
          }
      }
      return ans;
  }

vector<int> removeDuplicates(int *arr,int size){
vector<int> output;
unordered_map<int,bool> seen;
  for(int i=0;i<size;i++){
    if(seen.count(arr[i])==0){
      seen.insert(make_pair(arr[i],true));
      output.push_back(arr[i]);
    }
  }
  return output;
}
int main(){
  int a[]={1,2,3,3,2,1,4,3,6,5,5};
  vector<int> output=removeDuplicates(a,11);
  for(int i=0;i<output.size();i++){
    cout<<output[i]<<endl;
  }
}
