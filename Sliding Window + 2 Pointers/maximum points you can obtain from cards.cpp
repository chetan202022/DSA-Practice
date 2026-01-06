class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int total_sum=0;
        for(int x : cardPoints) total_sum += x;

        if(k == n)return total_sum;

        int window = n-k;
        int curr_sum=0;

        for(int i=0; i<window; i++) curr_sum += cardPoints[i];
        int minsum = curr_sum;

        for(int i=window; i<n; i++){
            curr_sum += cardPoints[i];
            curr_sum -= cardPoints[i - window];
            minsum = min(minsum, curr_sum);
        }

        return total_sum - minsum;
    }
};
