
// https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:

    int f(vector<int>& heights){
        int area = 0;
        int n = heights.size();
        stack<int> st;

        for(int i=0; i<=n; i++){
            int curr = (i == n) ? 0 : heights[i];

            while(!st.empty() && curr < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int width = (st.empty()) ? i : i - st.top() - 1;
                area = max(area, (h * width));
            }
            st.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> heights(n, 0);

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, f(heights));
        }
        return ans;
    }
};
