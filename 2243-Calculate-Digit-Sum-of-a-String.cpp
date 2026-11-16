class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k)
        {
            string f;
            int sum=0;
            int x=0;
            for(int i=0;i<s.length();i++)
            {
                sum=sum+s[i]-'0';
                x+=1;
                if(x==k){

                    f+=to_string(sum);
                    sum=0;
                    x=0;
                }
                
            }
            if(x>0){f+=to_string(sum);}
            s=f;
            
        }
        return s;
    }
};