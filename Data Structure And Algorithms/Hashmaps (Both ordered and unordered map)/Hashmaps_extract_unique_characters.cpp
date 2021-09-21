/*
Extract Unique characters
Send Feedback
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/
#include<unordered_map>
using namespace std;
#include<string>
#include<cstring>
char* uniqueChar(char *str){
    char *ans=new char[strlen(str)+1];
    unordered_map<char,bool> seen;
    int k=0;
     for(int i=0;i<strlen(str);i++){
        if(seen.count(str[i])==0){
            ans[k++]=str[i];
            seen[str[i]]=true;
        }
    }
   //ans[strlen(str)]='\0';
  return ans;
}
