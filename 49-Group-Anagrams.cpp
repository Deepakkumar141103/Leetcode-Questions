class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> mp;
        for(auto it:strs)
        {
            string s=it;
            vector<int> frq(26,0);
            for(auto it:s)
            {
                frq[it-'a']++;
            }
            string key;
            for(auto n:frq)
            {
                key+=to_string(n)+'#';
            }
            mp[key].push_back(s);

        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};