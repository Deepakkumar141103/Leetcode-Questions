class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            pair<string,int> p=q.front();
            string st=p.first;
            int val=p.second;
            q.pop();
            if(st==endWord){return val;}
            for(int i=0;i<st.length();i++)
            {
                char original=st[i];
                for(int j=0;j<26;j++)
                {
                    st[i]='a'+j;
                    if(s.find(st)!=s.end())
                    {
                        s.erase(st);
                        q.push({st,val+1});
                    }
                }
                st[i]=original;
            }
        }
        return 0;

    }
};