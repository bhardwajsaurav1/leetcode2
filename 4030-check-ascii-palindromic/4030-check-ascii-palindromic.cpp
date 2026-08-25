class Solution {
public:
    bool isPalindromic(string s) {
        string si;
        for(int i=0;i<s.size();i++){
            int ascii=s[i];
            si+=bitset<8>(ascii).to_string();
        }
        string ri=si;
        (reverse(ri.begin(),ri.end()));
        return si==ri;
    }
};