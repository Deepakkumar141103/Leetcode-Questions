class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int top=0;
        int right=n-1;
        int left=0;
        int bottom=n-1;
        int sum=0;
        while(top<=bottom && left<=right)
        {
            for(int i=top;i<=right;i++)
            {
                ans[top][i]=++sum;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                ans[i][right]=++sum;
            }
            right--;
           if(top<=bottom) {for(int i=right;i>=left;i--)
            {
                ans[bottom][i]=++sum;
            }
            bottom--;}
            if(left<=right){for(int i=bottom;i>=top;i--)
            {
                ans[i][left]=++sum;
            }
            left++;}
        }
        return ans;
    }
};