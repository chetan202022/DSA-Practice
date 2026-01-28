
// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?track=amazon-heap&batchId=192

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=arr.size();
        
        for(int i=0; i<=k && i<n; i++) pq.push(arr[i]);
        
        int idx=0;
        for(int i=k+1; i<n; i++){
            arr[idx++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};
