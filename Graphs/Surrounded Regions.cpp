
// https://leetcode.com/problems/surrounded-regions/description/

class Solution {

private: 
    void dfs(int row, int col, int m, int n, vector<vector<char>>& board){
        board[row][col] = 'T';

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(0 <= nrow && nrow < m && 0 <= ncol && ncol < n && 
                board[nrow][ncol] == 'O'){
                    dfs(nrow, ncol, m, n, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0; i<m; i++){
            if(board[i][0] == 'O') dfs(i, 0, m, n, board);
            if(board[i][n-1] == 'O') dfs(i, n-1, m, n, board);
        }
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O') dfs(0, j, m, n, board);
            if(board[m-1][j] == 'O') dfs(m-1, j, m, n, board);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
