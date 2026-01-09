
// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-numbers4629/1

class Solution {
  public:
    void segregateEvenOdd(vector<int>& arr) {
        vector<int> even, odd;
        
        for(int a : arr){
            if(a % 2 == 0) even.push_back(a);
            else odd.push_back(a);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        int idx = 0;
        for(int x : even) arr[idx++] = x;
        for(int x : odd) arr[idx++] = x;
        
    }
};
