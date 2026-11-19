class Solution {
public:
    int check(int i,int j,string &s)
    {
        stack<char> t;
        t.push(s[i]);
        i++;
        while(i<=j)
        {
            if(s[i]=='('){t.push(s[i]);}
            else{
                if(t.empty()  || t.top()!='('){return 0;}
                else t.pop();
            }
            i++;
        }
        return t.empty()?1:0;

    }
    int helper(int i,int j,string &s,vector<vector<int>> &dp)
    {
        if(i>j){return 0;}
        
        if(dp[i][j]!=-1){return dp[i][j];}
        if(check(i,j,s)){return dp[i][j]=j-i+1;}
        else{
            return max(helper(i+1,j,s,dp),helper(i,j-1,s,dp));
        }
    }
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(),0);
        int ans=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='('){dp[i]=2;if(i>=2)dp[i]+=dp[i-2];}
                else{
                    int j=i-dp[i-1]-1;
                    if(j>=0 && s[j]=='('){
                        dp[i]=dp[i-1]+2;
                        if(j>0){dp[i]+=dp[j-1];}
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};