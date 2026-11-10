class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        vector<int> ahead1(2,0);
        vector<int> ahead2(2,0);
        for(int i=prices.size()-1;i>=0;i--)
        {
            vector<int> curr(2,0);
            for(int j=0;j<=1;j++)
            {
                
                int profit=-1e9;
                if(j)
                {
                    profit=max((-prices[i]+ahead1[0]),(ahead1[1]));
                }
                else {profit=max((prices[i]+ahead2[1]),ahead1[0]);}
                curr[j]=profit;
                
            }
            ahead2=ahead1;
            ahead1=curr;
        }
        return ahead1[1];      
    }
};