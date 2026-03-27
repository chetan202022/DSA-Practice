
// https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

vector<int> f(int i, int j, vector<int> &a, vector<int> &b, 
              vector<vector<vector<int>>> &dp){
    
    if(i == a.size() || j == b.size()) return {};
    
    if(!dp[i][j].empty()) return dp[i][j];
    
    if(a[i] == b[j]){
        vector<int> temp = f(i+1, j+1, a, b, dp);
        temp.insert(temp.begin(), a[i]);
        return dp[i][j] = temp;
    }
    
    vector<int> left = f(i+1, j, a, b, dp);
    vector<int> right = f(i, j+1, a, b, dp);
    
    if(left.size() > right.size())
        return dp[i][j] = left;
    else
        return dp[i][j] = right;
}



vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m)
    );
    
    return f(0, 0, a, b, dp);
}
