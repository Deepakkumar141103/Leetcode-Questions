class Solution {
public:
    void helper(int index,string digits,vector<string> &ans,string &curr,vector<string> &vec)
    {
        if(index==digits.size()){ans.push_back(curr);return;}
        int digit = digits[index] - '0';
        for(int i=0;i<vec[digit].length();i++)
        {
            curr.push_back(vec[digit][i]);
            helper(index+1,digits,ans,curr,vec);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
         vector<string> vec={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
         string curr="";
         vector<string> ans;
         helper(0,digits,ans,curr,vec);
         return ans;
         
    }
};