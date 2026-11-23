class Solution {
public:
    bool checkString(string s) {
        int la=-1;
        int fb=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a'){la=i;}
            else{
                if(fb==-1){fb=i;}
            }
        }
        if(la==-1 || fb==-1){return true;}
        return fb>la;

    }
};