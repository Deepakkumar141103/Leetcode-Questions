class Solution {
public:
    void helper(int i,vector<int> &nums,vector<int> res,int n,set<vector<int>> &s)
    {
        if(i==n){s.insert(res);return;}
        for(int j=i;j<n;j++)
        {
            swap(res[i],res[j]);
            helper(i+1,nums,res,n,s);
            swap(res[i],res[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        helper(0,nums,nums,nums.size(),s);
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};