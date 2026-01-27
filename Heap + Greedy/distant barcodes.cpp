
// https://leetcode.com/problems/distant-barcodes/description/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> freq;
        for (int x : barcodes) freq[x]++;

        vector<pair<int,int>> v;
        for (auto &p : freq) v.push_back({p.second, p.first});

        sort(v.begin(), v.end(), greater<>()); // sort by frequency

        int n = barcodes.size();
        vector<int> ans(n);
        int idx = 0;

        for (auto &p : v) {
            int cnt = p.first;
            int val = p.second;

            while (cnt--) {
                if (idx >= n) idx = 1;   // switch to odd positions
                ans[idx] = val;
                idx += 2;
            }
        }
        return ans;
    }
};
