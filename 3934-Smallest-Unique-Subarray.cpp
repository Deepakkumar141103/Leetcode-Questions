class Solution {
public:
    bool ispossible(int mid,vector<int> &nums,int size)
    {
       long long p = 31;
    long long mod = 1e9 + 7;
    long long invP = 129032259;

    unordered_map<long long, int> s;

    long long sum = 0;
    long long power = 1;

    // Calculate initial window hash
    for (int i = 0; i < mid; i++)
    {
        sum = (sum + nums[i] * power) % mod;
        power = (power * p) % mod;
    }

    s[sum]++;

    // Calculate p^(mid-1)
    power = (power * invP) % mod;

    // Sliding window
    for (int i = 1; i <= size - mid; i++)
    {
        sum = (sum - nums[i-1] + mod) % mod;
        sum = (sum * invP) % mod;

        sum = (sum + nums[i+mid-1] * power) % mod;

        s[sum]++;
    }

    for (auto it : s)
    {
        if (it.second == 1)
            return true;
    }

    return false;
}
    int smallestUniqueSubarray(vector<int>& nums) {
        
        int low=1;
        int high=nums.size();
        int size=nums.size();
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(mid,nums,size)){ans=min(ans,mid);high=mid-1;}
            else{low=mid+1;}

        }
        return ans;
    }
};