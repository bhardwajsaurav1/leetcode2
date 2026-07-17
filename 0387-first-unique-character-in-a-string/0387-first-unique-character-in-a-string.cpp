class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0);
        vector<int>mp(26,-1);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            mp[s[i]-'a']=i;
        }
        int mini=s.size();
        for(int i=0;i<26;i++){
            if(freq[i]==1){
                mini=min(mini,mp[i]);
            }
        }
        return (mini==s.size())?-1:mini;
    }
};