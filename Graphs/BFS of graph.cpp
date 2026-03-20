
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
  
    void f(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &ans){
        queue<int> q;
        vis[node] = 1;
        q.push(node);
        
        while(!q.empty()){
            int curr = q.front(); q.pop();
            ans.push_back(curr);
            
            for(int x : adj[curr]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }
  
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(!vis[i]) f(i, vis, adj, ans);   
        }
        return ans;
    }
};
