class Solution {
public:
    map<int,int> dp;
   
    int maxSelectedElements(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(auto x:nums)
        {
            dp[x+1]=max(dp[x+1],dp[x]+1);
            dp[x]=max(dp[x],dp[x-1]+1);
            ans=max(ans,max(dp[x],dp[x+1]));
        }
        return ans;
    }
};