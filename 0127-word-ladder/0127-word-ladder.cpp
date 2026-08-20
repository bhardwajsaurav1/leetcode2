class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> qt;
        qt.push({beginWord,1});
        st.erase(beginWord);
        int count=0;
        while(!qt.empty()){
            string word=qt.front().first;
            int size=qt.front().second;
            qt.pop();
            if(word==endWord) count=size;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        qt.push({word,size+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return count;
    }
};