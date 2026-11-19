class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
          int m=matrix.size();
          int n=matrix[0].size();
          int upleft=0;
          int upright=n-1;
          int downleft=0;
          int downright=m-1;
          vector<int> ans;
          while(upleft<=downright && upright>=downleft)
          {
            for(int i=upleft;i<=upright;i++)
            {
                ans.push_back(matrix[upleft][i]);
            }
            upleft++;
            for(int i=upleft;i<=downright;i++)
            {
                ans.push_back(matrix[i][upright]);
            }
            upright--;
            if(upleft<=downright){for(int i=upright;i>=downleft;i--)
            {
                ans.push_back(matrix[downright][i]);
            }
            downright--;}
            if(downleft<=upright){for(int i=downright;i>=upleft;i--)
            {
                ans.push_back(matrix[i][downleft]);
            }
            downleft++;}


          }
          return ans;
    }
};