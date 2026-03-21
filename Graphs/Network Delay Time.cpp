
// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);
        
        // Build graph
        for(auto &it : times){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }
        
        // Min heap: {dist, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        
        pq.push({0, k});
        
        // Dijkstra
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if(d + wt < dist[adjNode]){
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        
        return ans;
    }
};
