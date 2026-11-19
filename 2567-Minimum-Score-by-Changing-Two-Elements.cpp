class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3){return 0;}
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int one=abs(nums[n-2]-nums[1]);
        int start=abs(nums[n-1]-nums[2]);
        int last=abs(nums[n-3]-nums[0]);
        ans+=min(one,min(start,last));
        return ans;

    }
};