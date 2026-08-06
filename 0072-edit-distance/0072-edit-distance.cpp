class Solution {
public:
    int dp[501][501];
    int solve(string &s, string &t, int m, int n){
        if(m==0){
            return n;
        }
        else if(n==0){
            return m;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m-1]==t[n-1]){
            return dp[m][n]=solve(s, t, m-1,n-1);
        }
        int insert=1+solve(s,t,m,n-1);
        int del=1+solve(s,t,m-1,n);
        int replace=1+solve(s,t,m-1,n-1);
        return dp[m][n]=min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1, sizeof(dp));
        return solve(word1,word2,word1.size(),word2.size());
    }
};