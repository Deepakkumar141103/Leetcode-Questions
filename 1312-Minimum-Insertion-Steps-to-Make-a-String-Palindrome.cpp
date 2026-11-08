class Solution {
public:
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i<0 || j<0){return 0;}
        if(dp[i][j]!=-1e9){return dp[i][j];}
        if(s1[i]==s2[j]){return dp[i][j]=1+helper(i-1,j-1,s1,s2,dp);}
        else{
            int one=helper(i-1,j,s1,s2,dp);
            int two=helper(i,j-1,s1,s2,dp);
            return dp[i][j]=max(one,two);
        }
    }
    int minInsertions(string s) {
        string src=s;
        reverse(src.begin(),src.end());
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1e9));
        int size=s.length()-1;
        int len=helper(size,size,s,src,dp);
        return (s.length()-len);
    }
};