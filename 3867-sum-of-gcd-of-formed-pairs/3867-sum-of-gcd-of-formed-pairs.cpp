class Solution {
public:
    long  long gcd(long long a, long long b){
        while(a>0&&b>0){
            if(a>b)a=a%b;
            else b=b%a;
        }
        if(a==0) return b;
        else return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefixGcd(n);
        long long maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(long long)nums[i]);
            prefixGcd[i]=gcd(maxi,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int low=0;
        int high=n-1;
        long long ans=0;
        while(low<high){
            ans+=gcd(prefixGcd[low],prefixGcd[high]);
            low++;
            high--;
        }
        return ans;
    }
};