class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        st=set()
        for i in nums:
            x=abs(i)
            if(nums[x-1]<0) :
                st.add(x)
            else:
                nums[x-1]=-nums[x-1]
        return list(st)
        