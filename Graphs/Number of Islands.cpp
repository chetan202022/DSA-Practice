
// https://leetcode.com/problems/number-of-islands/description/

class Solution {
private:
    void dfs(int row, int col, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(0 <= nrow && nrow < m && 0 <= ncol && ncol < n &&
                !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    dfs(nrow, ncol, m, n, vis, grid);
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // m * n
        int m=grid.size();
        int n=grid[0].size();
        
        int count=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(i, j, m, n, vis, grid);
                }
            }
        }
        return count;
    }
};
