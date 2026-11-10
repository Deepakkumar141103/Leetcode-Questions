class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        vector<int> ahead(2,0);
        for(int i=prices.size()-1;i>=0;i--)
        {
            vector<int> curr(2,0);
            for(int j=0;j<=1;j++)
            {
                
                int profit=-1e9;
                if(j)
                {
                    profit=max((-prices[i]+ahead[0]),(ahead[1]));
                }
                else {profit=max((prices[i]+ahead[1]),ahead[0]);}
                curr[j]=profit;
                
            }
            ahead=curr;
        }
        return ahead[1];
    }
};