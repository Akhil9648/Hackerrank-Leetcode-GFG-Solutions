class Solution:
    def check(self, nums: List[int]) -> bool:
        n=len(nums)
        cnt=0
        for i in range(0,n-1):
            if(nums[i]>nums[i+1]):
                if(cnt==0):
                    cnt=1
                else:
                    return False
        if(cnt==1 and nums[n-1]>nums[0]):
            return False
        return True