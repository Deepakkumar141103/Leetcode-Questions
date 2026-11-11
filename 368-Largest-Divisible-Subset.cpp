class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size());
        sort(nums.begin(),nums.end());
        int maxi=0;
        int maxl=0;
        if(nums.size()==1){return nums;}
        for(int i=1;i<nums.size();i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if((nums[i]%nums[prev]==0 || nums[prev]%nums[i]==0) && (dp[prev]+1>dp[i]))
                {
                    dp[i]=1+dp[prev];
                    maxi=dp[i]>maxl?i:maxi;
                    maxl=max(dp[i],maxl);
                    hash[i]=prev;
                    
                }
            }
        }
        vector<int> ans;
        while(hash[maxi]!=maxi)
        {
            ans.push_back(nums[maxi]);
            maxi=hash[maxi];
        }
        ans.push_back(nums[maxi]);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};