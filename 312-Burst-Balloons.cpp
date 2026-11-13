class Solution {
public:
    int helper(int i,int j,vector<int>&nums,vector<vector<int>> &dp)
    {
        if(i>j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int amx=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int cost=nums[i-1]*nums[k]*nums[j+1];
            int remin=helper(i,k-1,nums,dp)+helper(k+1,j,nums,dp);
            amx=max(amx,cost+remin);
        }
        return dp[i][j]=amx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=helper(1,n,nums,dp);
        return ans;
    }
};