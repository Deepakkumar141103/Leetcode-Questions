class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        vector<int> pre(nums.size(),1);
        vector<int> suff(nums.size(),1);
        int ans=INT_MIN;
        if(nums.size()==1){return 1;}
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1]){pre[i]=pre[i]+pre[i-1];}
            if(nums[nums.size()-i-1]>nums[nums.size()-i]){suff[nums.size()-i-1]+=suff[nums.size()-i];}
            ans=max(ans,max(pre[i],suff[nums.size()-i-1]));
        }
        return ans;
    }
};