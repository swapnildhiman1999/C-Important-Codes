#include<unordered_map>
#include<map>
#include<iostream>
#include<vector>
using namespace std;
int main(){
  unordered_map<string,int> ourmap;
  map<string,int> maps;
  ourmap["abc"]=1;
  ourmap["abc1"]=2;
  ourmap["abc3"]=3;
  ourmap["abc4"]=4;
  ourmap["abc5"]=5;
  maps["abc"]=1;
  maps["abc1"]=2;
  maps["abc3"]=3;
  maps["abc4"]=4;
  maps["abc5"]=5;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  vector<int>::iterator it_;
  it_=v.begin();
//  cout<<v.begin()<<endl;
  for(;it_!=v.end();it_++){
    cout<<*it_<<" "<<endl;
  }
  unordered_map<string,int> ::iterator it;
  it=ourmap.begin();
  while(it!=ourmap.end()){
    cout<<it->first<<" "<<it->second<<endl;
    it++;
  }
  cout<<endl;
  map<string,int>::iterator itm,itm2;
  itm=maps.find("abc1");
  //cout<<(itm+1)->first<<endl;
  itm2=maps.find("abc5");
  maps.erase(itm,itm2);
  itm=maps.begin();
  while(itm!=maps.end()){
    cout<<itm->first<<" "<<itm->second<<endl;
    itm++;
  }
}
