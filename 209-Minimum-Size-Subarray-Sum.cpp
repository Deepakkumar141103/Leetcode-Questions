class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int ans=INT_MAX;
        int j=1;
        int sum=nums[0];
        if(nums.size()==1){return nums[0]>=target;}
        while(i<nums.size() && j<nums.size())
        {
            while(j<nums.size() && sum<target)
            {
                sum+=nums[j];
                j++;
            }
            if(sum>=target)ans=min(ans,j-i);
            while(i<j && sum >=target){sum-=nums[i];ans=min(ans,j-i);i++;}
        }
        while(i<nums.size())
        {
            if(sum>target){sum-=nums[i];i++;ans=min(ans,(j-i));}
            else break;
        }
        return ans==INT_MAX?0:ans;
    }
};