
// https://leetcode.com/problems/top-k-frequent-words/description/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto &w : words) mp[w]++;

        vector<pair<string, int>> vec;
        for(auto& m : mp){
            vec.push_back({m.first, m.second});
        }
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            if(a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });

        vector<string> ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
