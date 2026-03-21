
// https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        
        vector<vector<int>> vis(N, vector<int>(M,0));
        queue<pair<pair<int, int>, int>> q;
        
        q.push({{0,0},0});
        vis[0][0] = 1;
        
        int dx[4] = {-1, 0, +1, 0};
        int dy[4] = { 0, +1, 0, -1};
        
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int dist = it.second;
            
            if(row == X && col == Y) return dist;
             
            for(int i=0; i<4; i++){
                int drow = dx[i] + row;
                int dcol = dy[i] + col;
                
                if(0 <= drow && drow < N && 0 <= dcol && dcol < M && 
                    A[drow][dcol] == 1 && !vis[drow][dcol]){
                        vis[drow][dcol] = 1;
                        q.push({{drow, dcol}, dist+1});
                    }
            }
        }
        return -1;
    }
};
