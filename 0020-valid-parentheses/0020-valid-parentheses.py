class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        for x in s:
            if(x=='(' or x=='{' or x=='['):
                stack.append(x)
            else:
                if(len(stack)==0) :
                    return False
                ele=stack[-1]
                stack.pop()
                if((ele=='(' and x!=')') or (ele=='[' and x!=']') or (ele=='{' and x!='}') ):
                    return False
        return len(stack)==0      
        