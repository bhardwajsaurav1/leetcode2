class Solution {
public:
    bool flag=true;
    int fact(int n){
        if(n==0) return 0;
        if(n==1) return -1;
        if(n==2) return -2;
        if(n==3) return -6;
        if(n==4) return -5;
        int ans;
        if(flag){
            ans=n*(n-1)/(n-2)+(n-3);
            flag=false;
        }
        else ans=-n*(n-1)/(n-2)+(n-3);
        return ans+fact(n-4);
    }
    int clumsy(int n) {
       if(n==1) return 1;
       if(n==2) return 2;
       if(n==3) return 6;
       if(n==4) return 7;
       return fact(n);
       }
};