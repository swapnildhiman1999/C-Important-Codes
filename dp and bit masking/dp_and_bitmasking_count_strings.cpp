/*
We will using dynamic programing (dp). Let F[i][ok1][ok2] is the number of the strings T that we can generated if we already got the first i-1 characters of it and ok1 and ok2 represent the following information:
ok1 = 0 mean the first i - 1 characters of T still match the corresponding t - 1 characters of S. ok1 = 1 mean T is larger then S.
ok2 = 0 mean in the reversed order the first t - 1 characters in T is already lexicographically larger then the corresponding characters in S. ok2 = 0 if otherwise.
Let N is the length of S The result of course will be F[0][0][0]. We can initialize the dp with F[N + 1][1][1] = 1. We will calculate F in the decreasing order of i. With each i, ok1, ok2, we try to put all possible character in position i so that T is never lexicographically smaller than S in the original order:
//let s is 0-indexed
for (int i = N - 1; i > 0; i--)
    for (int ok1 = 0; ok1 <= 1; ok1++)
      for (int ok2 = 0; ok2 <= 1; ok2++) {
      //make sure that T is always lexicographically larger than S in original order
        for (char c = ok1 == 0 ? s[i] : 'A'; c <= 'Z'; c++) {
          int nextOk2 = ok2;
          if (c != s[pos]) {
            //if we put a character c > s[pos] in position pos of T then T became lexicographically larger than S in reversed order
            nextOk2 = c > s[pos];
          }

          f[pos][ok1][ok2] = (f[pos][ok1][ok2] + f[pos + 1][ok1 || c > s[pos]][nextOk2]) % MOD;
        }
    }
*/

#define ll long long
#define mod 1000000007
int countStrings(char* s) {
    int n=0;
    while(s[n]!='\0')
        n++;
    long ans=0;
    long temp=0;
    int m=1000000007;
    for(int i=0;i<n;i++)
    {
        ans=(ans+ ((temp+1)*('Z'-s[i]))%m)%m;
        temp=((temp*26)%m + 'Z'-s[i])%m;
        cout<<ans<<" "<<temp<<endl;
    }

    return ans;
}
