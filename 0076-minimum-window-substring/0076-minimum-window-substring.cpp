class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int n=s.size();
        int m=t.size();
        int count=0;
        int mini=INT_MAX;
        int index=-1;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int i=0;
        int j=0;
        while(i<n){
            if(mp[s[i]]>0) count++;
            mp[s[i]]--;
            while(j<n&&count>=m){
              
                if(mini>(i-j+1)){
                    mini=i-j+1;
                    index=j;
                    // cout<<index<<" ";
                }
                mp[s[j]]++;
                if(mp[s[j]]>0) count--;
                j++;
            }
            i++;
        }
        
        return (mini==INT_MAX)?"":s.substr(index,mini);
    }
};