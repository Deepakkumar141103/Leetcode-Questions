class Solution {
public:
    
    int numOfSubarrays(vector<int>& arr) {
        
        
        int even=1;
        int odd=0;
        int pref=0;
        int ans=0;
        int m=1000000007;
        for(auto it:arr)
        {
            pref+=it;
            if(pref%2==0){
                ans+=odd;
            }
            else{ans+=even;}

            if(pref%2==0)even++;
            else odd++;

            ans%=m;
        }
        return ans;}
};