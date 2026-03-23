
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;

        for(auto &it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DSU dsu(maxRow + maxCol + 2);

        unordered_set<int> nodes;

        for(auto &it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1;

            dsu.unionBySize(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for(auto node : nodes) {
            if(dsu.findUPar(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};
