class Solution {
public:
    int helper(vector<vector<int>> &matrix,int row,int col,int m,int n,vector<vector<int>> &dp){
        if(row==m-1){return matrix[row][col];}
        if(dp[row][col]!=1e9){return dp[row][col];}
        int down=1e9;
        int db=1e9;int da=1e9;
        if(row+1<m){down=matrix[row][col]+helper(matrix,row+1,col,m,n,dp);}
        if(row+1<m && col-1>=0){db=matrix[row][col]+helper(matrix,row+1,col-1,m,n,dp);}
        if(row+1<m && col+1<n){da=matrix[row][col]+helper(matrix,row+1,col+1,m,n,dp);}
        dp[row][col]=min(down,min(db,da));
        return dp[row][col];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        for(int i=0;i<matrix[0].size();i++)
        {
            ans=min(ans,helper(matrix,0,i,m,n,dp));
        }
        return ans;
    }
};