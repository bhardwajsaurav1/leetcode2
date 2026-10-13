class Solution:
    def reverseVowels(self, s: str) -> str:
        v="aeiouAEIOU"
        x=[]
        for c in s:
            if c in v:
                x.append(c)
        x.reverse()
        s_list=list(s)
        i=0
        j=0
        while(j<len(s_list) and i<len(x)):
            if s_list[j] in v:
                s_list[j]=x[i]
                i+=1
                j+=1
            else:
                j+=1
        return "".join(s_list)
        