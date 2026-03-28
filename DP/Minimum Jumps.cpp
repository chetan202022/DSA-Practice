
// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        
        if(n <= 1) return 0;

        int jumps = 0, currEnd = 0, farthest = 0;

        for(int i = 0; i < n-1; i++){
            
            farthest = max(farthest, i + arr[i]);

            if(i == currEnd){
                if(farthest == i) return -1;
                
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};
