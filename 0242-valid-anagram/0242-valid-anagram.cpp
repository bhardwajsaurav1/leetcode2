class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<int,int>mp;
       for(char x:s){
        mp[x]++;
       } 
       for(char x:t){
        mp[x]--;
       }
       for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second!=0) return false;
       }
       return true;
    }
};