
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
  
    void f(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& ans){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]) f(it, vis, adj, ans);
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(), 0);
        vector<int> ans;
        for(int i=0; i<adj.size(); i++){
            if(!vis[i]) f(i, vis, adj, ans);
        }
        return ans;
    }
};
