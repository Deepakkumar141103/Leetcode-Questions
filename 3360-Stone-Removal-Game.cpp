class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10){return false;}
        int x=10;
        int i=1;
        for(i;i<=5;i++)
        {
            if(n<x){return false;}
            n-=x;
            x-=1;
            if(n<x){return true;}
            n-=x;
            x-=1;
        }
        return i==6;
    }
};