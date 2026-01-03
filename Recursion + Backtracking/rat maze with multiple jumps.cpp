
// https://www.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1

class Solution {
public:
    bool dfs(int i, int j, int n,
             vector<vector<int>>& mat,
             vector<vector<int>>& ans) {

        // Destination reached
        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        // Invalid cell
        if (i >= n || j >= n || mat[i][j] == 0)
            return false;

        ans[i][j] = 1;

        int maxJump = mat[i][j];

        // Try forward (right) first
        for (int jump = 1; jump <= maxJump; jump++) {
            if (dfs(i, j + jump, n, mat, ans))
                return true;
        }

        // Try down
        for (int jump = 1; jump <= maxJump; jump++) {
            if (dfs(i + jump, j, n, mat, ans))
                return true;
        }

        // Backtrack
        ans[i][j] = 0;
        return false;
    }

    vector<vector<int>> ShortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));

        if (!dfs(0, 0, n, mat, ans))
            return vector<vector<int>>(1, vector<int>(1, -1));

        return ans;
    }
};
