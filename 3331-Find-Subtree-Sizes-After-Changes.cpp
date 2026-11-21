
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> last, newp, ans;
    
    void dfs(int u, string &s, vector<int>& parent) {
        int c = s[u] - 'a';

        int old = last[c];

        // Find nearest ancestor with same character
        if (old != -1)
            newp[u] = old;
        else
            newp[u] = parent[u];

        last[c] = u;

        for (int v : adj[u]) {
            dfs(v, s, parent);
        }

        last[c] = old;
    }

    void calculate(int u, vector<vector<int>>& tree) {
        for (int v : tree[u]) {
            calculate(v, tree);
            ans[u] += ans[v];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newp.resize(n);
        ans.assign(n, 1);
        last.assign(26, -1);

        // Original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Find new parents
        dfs(0, s, parent);

        // Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newp[i]].push_back(i);
        }

        // Calculate subtree sizes
        calculate(0, tree);

        return ans;
    }
};
