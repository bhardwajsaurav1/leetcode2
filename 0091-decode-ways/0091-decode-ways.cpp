class Solution {
public:
    int ans=0;
    int dp[100];
    int solve(int idx,string&s, int n){
        if(idx==n) return 1;
        if(idx>n) return 0;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        ans+= solve(idx+1,s, n);
        int num=stoi(s.substr(idx,2));
        if(num<=26){
            ans+=solve(idx+2,s,n);
        }
        dp[idx]=ans;
        return 0;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        solve(0,s,s.size());
        return ans;
    }
};