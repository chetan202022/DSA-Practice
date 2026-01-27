
// https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        int removal=0;
        int last_idx=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < last_idx) removal++;
            else last_idx = intervals[i][1];
        }
        return removal;
    }
};
