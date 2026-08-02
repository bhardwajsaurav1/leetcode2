class Solution {
public:
    int dp[101];
    int solve(int idx,string&s, int n){
        if(idx==n) return dp[idx]=1;
        if(s[idx]=='0') return dp[idx]=0;

        if(dp[idx]!=-1) return dp[idx];
        int ans= solve(idx+1,s, n);
        if(idx+1<n){
            if(s[idx]=='1'||s[idx]=='2'&&s[idx+1]<='6'){
            ans+=solve(idx+2,s,n);
            }
        }
        return dp[idx]=ans;
        
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s,s.size());
    }
};