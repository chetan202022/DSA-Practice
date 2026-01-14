
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?track=amazon-stacks&batchId=192

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> horizontal(n, 0);
        vector<int> vertical(n, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){ horizontal[j]++; vertical[i]++; }
                
            }
        }
        
        int idx = -1;
        for(int i=0; i<n; i++){
            if(horizontal[i] == n && vertical[i] == 1){ idx = i; }
        }
        
        return idx;
    }
};

// optimized approach : using two pointer

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int l = 0, r = n - 1;

        // Step 1: Find candidate
        while (l < r) {
            if (mat[l][r] == 1)
                l++;
            else
                r--;
        } // at l == r this while will over

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i != l) {
                if (mat[l][i] == 1 || mat[i][l] == 0)
                    return -1;
            }
        }

        return l;
    }
};
