class Solution {
public:
                                                
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> vec(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            vec[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> vis(numCourses,0);
       
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][1]]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:vec[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        
        return topo.size()==numCourses;
        

    }
};