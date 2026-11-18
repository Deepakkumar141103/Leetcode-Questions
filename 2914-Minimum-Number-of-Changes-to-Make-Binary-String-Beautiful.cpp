class Solution {
public:
    int minChanges(string s) {
        int n1=0;
        int n0=0;
        int ans=0;
        int k=0;

        for(int i=0;i<s.length();i++)
        {
            
            if((s[i]-'0')==0){n0++;}
            else{n1++;}
            k++;
            if(k==2){ans+=min(n1,n0);k=0;n1=0;n0=0;}
        }
        return ans;
    }
};