class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> vec(prices.size()+1,vector<vector<int>> (2,vector<int>(3,0)));
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int capacity=1;capacity<=2;capacity++)
                {
                    int profit=-1e9;
                    if(j)
                    {
                        profit=max((-prices[i]+vec[i+1][0][capacity]),(vec[i+1][1][capacity]));
                    }
                    else{
                        profit=max((prices[i]+vec[i+1][1][capacity-1]),(vec[i+1][0][capacity]));
                    }
                    vec[i][j][capacity]=profit;
                }
            }
        }
        return vec[0][1][2];
    }
};