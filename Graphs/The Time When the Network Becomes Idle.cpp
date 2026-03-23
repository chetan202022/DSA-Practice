
// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);

        // build graph
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS to find shortest distance from node 0
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while(!q.empty()) {
            int node = q.front(); q.pop();

            for(auto it : adj[node]) {
                if(dist[it] == -1) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }

        int ans = 0;

        for(int i = 1; i < n; i++) {
            int rt = 2 * dist[i];

            int lastReply;

            if(patience[i] >= rt) {
                lastReply = rt;
            } else {
                int lastSent = ((rt - 1) / patience[i]) * patience[i];
                lastReply = lastSent + rt;
            }

            ans = max(ans, lastReply);
        }

        return ans + 1; // network idle time
    }
};
