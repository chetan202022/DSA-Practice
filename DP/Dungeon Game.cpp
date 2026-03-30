
// https://leetcode.com/problems/dungeon-game/description/

class Solution {
public:

    int f(int row, int col, vector<vector<int>>& dungeon, vector<vector<int>> &dp){
        int n = dungeon.size(), m = dungeon[0].size();

        if(row == n || col == m) return 1e9;

        if(row == n-1 && col == m-1){
            return (dungeon[row][col] <= 0) ? - dungeon[row][col] + 1 : 1;
        }

        if(dp[row][col] != -1) return dp[row][col];

        int right = f(row, col+1, dungeon, dp);
        int down = f(row+1, col, dungeon, dp);

        int minHealthreq = min(right, down) - dungeon[row][col];

        dp[row][col] = (minHealthreq <= 0) ? 1 : minHealthreq;
        return dp[row][col];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , -1));
        
        return f(0, 0, dungeon, dp);
    }
};
