class Solution {
public:
    int ispalindrome(int i,int j,string &s,vector<vector<int>> &dp)
    {
       if(i>=j){return 1;}
       if(dp[i][j]!=-1){return dp[i][j];}
       if(s[i]!=s[j]){return dp[i][j]=0;}
       else return dp[i][j]=ispalindrome(i+1,j-1,s,dp);
    }
    
    
    string longestPalindrome(string s) {
        int start=0;
        int maxm=0;
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(ispalindrome(i,j,s,dp))
                {
                    if(j-i+1>maxm){start=i;maxm=j-i+1;}
                }
            }
        }
        return s.substr(start,maxm);

    }
};