#include<string>
#include<bits/stdc++.h>
using namespace std;
template<typename V>
class mapNode{
public:
  V value;
  string key;
  mapNode<V>* next;
  mapNode(string key,V val){
    this->key = key;
    this->value = val;
    next = NULL;
  }
  ~mapNode(){
    delete next;
  }
};
template<typename V>
class ourmap{
  int count;
  int numBucketsize;
  mapNode<V>** buckets;
public:
  ourmap(){
    count=0;
    numBucketsize=5;
    buckets=new mapNode<V>*[numBucketsize];
    for(int i=0;i<numBucketsize;i++){
      buckets[i]=NULL;
    }
  }
  ~ourmap(){
    for(int i=0;i<numBucketsize;i++){
      delete buckets[i];
    }
    delete[] buckets;
  }
  int gethashCode(string key){
    int hashCode=0;
    int hashCoeff=1;
    for(int i=key.length()-1;i>=0;i--){
      hashCode+=(hashCoeff*key[i])%numBucketsize;
      hashCode=hashCode%numBucketsize;
      hashCoeff=hashCoeff*37;
      hashCoeff=hashCoeff%numBucketsize;
    }
    return hashCode%numBucketsize;
  }
  void rehash(){
    count=0;
    mapNode<V>**temp=buckets;
    buckets=new mapNode<V>*[2*numBucketsize];
    for(int i=0;i<2*numBucketsize;i++){
      buckets[i]=NULL;
    }
    int oldBucketsize=numBucketsize;
    numBucketsize*=2;
    for(int i=0;i<oldBucketsize;i++){
      mapNode<V> *head=temp[i];
      while(head!=NULL){
        insert(head->key,head->value);
        head=head->next;
      }
    }
    for(int i=0;i<oldBucketsize;i++){
      delete temp[i];
    }
    delete[] temp;
  }
public:
  double loadFactor(){
    return (1.0*count)/numBucketsize;
  }
  int getsize(){
    return count;
  }
  void insert(string key,V value){
    int bucketIndex=gethashCode(key);
    mapNode<V>* head=buckets[bucketIndex];
    while(head!=NULL){
      if(head->key==key){
        head->value=value;
        return;
      }
      head=head->next;
    }
    head=buckets[bucketIndex];
    mapNode<V>* newNode=new mapNode<V>(key,value);
    count++;
    newNode->next=head;
    buckets[bucketIndex]=newNode;
    if(loadFactor()>0.7){
      rehash();
    }
  }
  V search(string key){
    int bucketIndex=gethashCode(key);
    mapNode<V>* head=buckets[bucketIndex];
    while(head!=NULL){
      if(head->key==key){
        return head->value;
      }
      head=head->next;
    }
    return 0;
  }
  V remove(string key){
    int bucketIndex=gethashCode(key);
    mapNode<V>* head=buckets[bucketIndex];
    mapNode<V>* prev=NULL;
    while(head!=NULL){
      if(head->key==key){
        if(!prev){
          buckets[bucketIndex]=head->next;
        }
        else{
          prev->next=head->next;
        }
        count--;
        V value=head->value;;
        head->next=NULL;
        delete head;
        return value;
      }
      prev=head;
      head=head->next;
    }
    return 0;
  }
};
int main(){
  ourmap<int> map;
  for(int i=0;i<10;i++){
    char c='0'+i;
    string key="abc";
    key=key+c;
    int value=i+1;
    map.insert(key,value);
    cout<<map.loadFactor()<<endl;
  }
  map.remove("abc2");
  //map.remove("abc7");

  for(int i=0;i<10;i++){
    char c='0'+i;
    string key="abc";
    key=key+c;
    cout<<key<<" "<<map.search(key)<<endl;
  }
    cout<<map.getsize()<<endl;
}
