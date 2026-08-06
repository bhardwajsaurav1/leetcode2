class Solution {
public:
    int dp[501][501];
    int solve(string s, string t, int i, int j){
        if(i==s.size()){
            return dp[i][j]=t.size()-j;
        }
        if(j==t.size()){
            return dp[i][j]=s.size()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(s, t, i+1,j+1);
        }
        int insert=1+solve(s,t,i,j+1);
        int del=1+solve(s,t,i+1,j);
        int replace=1+solve(s,t,i+1,j+1);
        return dp[i][j]=min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1, sizeof(dp));
        return solve(word1,word2,0,0);
    }
};