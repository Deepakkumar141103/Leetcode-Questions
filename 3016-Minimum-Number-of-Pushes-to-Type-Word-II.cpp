class Solution {
public:
    struct Compare {
        bool operator()(pair<char,int>& a, pair<char,int>& b) {
            return a.second < b.second;
        }
    };
    int minimumPushes(string word) {
        if(word.length()<=8){return word.length();}
        int ans=0;
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        vector<int> freq(26, 0);

        for (char ch : word) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({char('a' + i), freq[i]});}}
        
        if(pq.size()<=8){return word.length();}
        int k=0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            char c=it.first;
            freq[c-'a']=(k/8)+1;
            k++;
        }
        for(int j=0;j<word.length();j++)
        {
            ans+=freq[word[j]-'a'];
        }
        return ans;
    }


      
    
};
