
// https://www.geeksforgeeks.org/problems/box-stacking/1

class Solution {
public:

    struct Box{
        int h, w, l;
    };

    static bool comp(Box a, Box b){
        return a.l * a.w > b.l * b.w;
    }

    int f(int idx, int prev, vector<Box> &boxes, vector<vector<int>> &dp){
        if(idx == boxes.size()) return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int take = 0;
        if(prev == -1 || 
           (boxes[prev].w > boxes[idx].w && boxes[prev].l > boxes[idx].l)){
            
            take = boxes[idx].h + f(idx+1, idx, boxes, dp);
        }

        int not_take = f(idx+1, prev, boxes, dp);

        return dp[idx][prev+1] = max(take, not_take);
    }

    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        
        int n = height.size();
        vector<Box> boxes;

        // Generate rotations
        for(int i=0;i<n;i++){
            
            boxes.push_back({height[i], 
                            max(width[i], length[i]), 
                            min(width[i], length[i])});

            boxes.push_back({width[i], 
                            max(height[i], length[i]), 
                            min(height[i], length[i])});

            boxes.push_back({length[i], 
                            max(height[i], width[i]), 
                            min(height[i], width[i])});
        }

        // Sort by base area
        sort(boxes.begin(), boxes.end(), comp);

        int m = boxes.size();
        vector<vector<int>> dp(m, vector<int>(m+1, -1));

        return f(0, -1, boxes, dp);
    }
};
