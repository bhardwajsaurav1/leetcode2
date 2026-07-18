class Solution {
public:
    void solve(int start,vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp){
        ans.emplace_back(temp);
        for(int i=start;i<nums.size();i++){
            temp.emplace_back(nums[i]);
            solve(i+1,nums,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,nums,ans,temp);
        return ans;
    }
};