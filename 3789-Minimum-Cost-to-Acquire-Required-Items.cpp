class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       
       long long ans=0;
       long long less=min(need1,need2);
       int lar=need1>need2?cost1:cost2;
       ans+=min((long long)(less*(cost1+cost2)),(long long)(less*costBoth));
       int remaining=max(need1,need2)-less;
       ans+=(long long)remaining*(min(lar,costBoth));
       return ans;
    }

       

};