bool f(int n, int x, int y,int *dp){
    if(n==1 || n==x || n==y){
        return true;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    //beerus wons if he looses for n-1 || N-X || n-y
    if(n>x && n>y){
        dp[n]=!f(n-1,x,y,dp) || !f(n-x,x,y,dp) || !f(n-y,x,y,dp);
        return dp[n];
    }
    if(n<x && n>y){
         dp[n]=!f(n-1,x,y,dp) || !f(n-y,x,y,dp);
        return dp[n];
    }
    if(n>x && n<y){
        dp[n]=!f(n-1,x,y,dp) || !f(n-x,x,y,dp);
      return dp[n];
    }
    else{
        dp[n]=!f(n-1,x,y,dp);
        return dp[n];
    }
}
string solve(int n, int x, int y)
{

//     int *dp=new int[n+1];
//     for(int i=0;i<=n;i++){
//         dp[i]=-1;
//     }
//     bool ans=f(n,x,y,dp);
//     if(ans){
//         return "Beerus";
//     }
//     else{
//         return "Whis";
//     }
    bool dp[n+1];
    dp[0] = false;
    dp[1] = true;

    // Computing other values.
    for (int i = 2; i <= n; i++) {

        // If Beerus losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;

        // Else A loses game.
        else
            dp[i] = false;
    }
    if(dp[n]){return "Beerus";}
    return "Whis";
}
