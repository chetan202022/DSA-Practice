
// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        queue<pair<int, int>> q;

        int countfreshOranges=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    countfreshOranges++;
                }
            }
        }
        if(countfreshOranges == 0) return 0;
        if(q.empty()) return -1;

        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = { 0, +1, 0, -1};
        int time=-1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [row, col] = q.front(); q.pop();
                for(int i=0; i<4; i++){
                    int drow = dx[i] + row;
                    int dcol = dy[i] + col;

                    if(0 <= drow && drow < m && 0 <= dcol && dcol < n && grid[drow][dcol] == 1){
                        countfreshOranges--;
                        grid[drow][dcol] = 2;
                        q.push({drow, dcol});
                    }
                }
            }
            time++;
        }
        if(countfreshOranges == 0) return time;
        else return -1;
    }
};
