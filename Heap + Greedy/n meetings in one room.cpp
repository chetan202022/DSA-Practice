
// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        int n=start.size();
        vector<vector<int>> vec(n, vector<int>(2,0));
        
        for(int i=0; i<n; i++){
            vec[i][0] = start[i];
            vec[i][1] = end[i];
        }
        
        sort(vec.begin(), vec.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int count=1;
        int last_idx=vec[0][1];
        for(int i=1; i<n; i++){
            if(vec[i][0] > last_idx){ count++; last_idx = vec[i][1]; }
        }
        return count;
    }
};
