class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        long l=0;
        long r=0;
        long long int total=0;
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(r;r<n;r++)
        {
            total+=nums[r];
            while(l<=r && (1LL * nums[r]*(r-l+1))> total+k)
            {
                total-=nums[l];
                l++;
            }
            long long int res=r-l+1;
            ans=max(ans,res);

        }
        return ans;
    }
};