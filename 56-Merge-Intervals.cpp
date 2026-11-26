class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:intervals)
        {
            pq.push({it[0],it[1]});
        }
        vector<vector<int>> ans;
        while(pq.size()>1)
        {
            auto choota=pq.top();
            pq.pop();
            auto bda=pq.top();
            pq.pop();
            if(choota.second>=bda.first)
            {
                pq.push({choota.first,max(choota.second,bda.second)});
            }
            else{
                vector<int> pr={choota.first,choota.second};
                ans.push_back(pr);
                pq.push(bda);
            }
        }
        if(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            vector<int> pr={it.first,it.second};
            ans.push_back(pr);
        }
        return ans;
    }
};