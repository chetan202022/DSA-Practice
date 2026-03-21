
// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = { 0, -1, 0, +1};
        
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int row = it.first;
            int col = it.second;
            
           
            for(int i=0; i<4; i++){
                int drow = dx[i] + row;
                int dcol = dy[i] + col;
                
                if(0 <= drow && drow < m && 0 <= dcol && dcol < n && dist[drow][dcol] == -1){
                    dist[drow][dcol] = dist[row][col] + 1;
                    q.push({drow, dcol});
                }
            }
        }
        return dist;
    }
};
