
// https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, pair<int, int>>> vec;
        for(auto p : points){
            int x = p[0];
            int y = p[1];
            int dist = (x*x) + (y*y);
            vec.push_back({dist, {x, y}});
        }

        sort(vec.begin(), vec.end());

        vector<vector<int>> ans(k, vector<int>(2,0));
        for(int i=0; i<k; i++){
            ans[i][0] = vec[i].second.first;
            ans[i][1] = vec[i].second.second;
        }
        return ans;
    }
};
