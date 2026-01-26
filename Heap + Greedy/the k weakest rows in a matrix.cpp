
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size(), col = mat[0].size();
        vector<pair<int, int>> vec(row, make_pair(0,0));
        for(int i=0; i<row; i++){
            int count=0;
            for(int j=0; j<col; j++){
                if(mat[i][j]) count++;
                else break;
            }
            vec[i] = {count, i};
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};
