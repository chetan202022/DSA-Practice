
// https://www.geeksforgeeks.org/problems/word-boggle4143/1?track=amazon-graphs&batchId=192

class Solution {
  public:
    
    int n, m;
    
    bool dfs(int i, int j, int idx, string &word, 
             vector<vector<char>> &board, vector<vector<bool>> &vis) {
        
        if(idx == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || board[i][j] != word[idx])
            return false;
        
        vis[i][j] = true;
        
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        
        for(int d = 0; d < 8; d++) {
            if(dfs(i + dx[d], j + dy[d], idx + 1, word, board, vis))
                return true;
        }
        
        vis[i][j] = false; // backtrack
        return false;
    }
    
    bool exist(string &word, vector<vector<char>> &board) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 0, word, board, vis))
                        return true;
                }
            }
        }
        return false;
    }
    
    vector<string> wordBoggle(vector<vector<char> >& board,
                              vector<string>& dictionary) {
        
        n = board.size();
        m = board[0].size();
        
        vector<string> ans;
        
        for(auto &word : dictionary) {
            if(exist(word, board)) {
                ans.push_back(word);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
