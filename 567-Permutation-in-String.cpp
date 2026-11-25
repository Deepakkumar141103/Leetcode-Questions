class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        for(auto it:s1)
        {
            m[it]++;
        }
        for(int i=0;i<s2.length();i++)
        {
            int x=i;
            if(m.find(s2[i])!=m.end()){
                int k=0;
                
                unordered_map<char,int> ms=m;
                while(i<s2.length()&& ms.find(s2[i])!=ms.end() && k<s1.length())
                {
                    ms[s2[i]]--;
                    if(ms[s2[i]]==0){ms.erase(s2[i]);}
                    i++;k++;
                    
                }
                if(k==s1.length() && ms.size()==0){return true;}
                i=x;;
            }
        }
        return false;
    }
};