class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res=strs[0];
        for(int i=1;i<strs.size();i++){
            string s=strs[i];
            string ans="";
            int j=0; int k=0;
            while(j<res.size()&&k<s.size()){
                if(res[j]==s[k]){
                    ans+=res[j];
                    j++; 
                    k++;
                }
                else break;
            }
            res=ans;
        }
        return res;
    }
};