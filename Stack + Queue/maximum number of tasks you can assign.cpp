
// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

class Solution {
public:

    bool can_assign(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int> usable_workers(workers.end() - mid, workers.end());

        for(int i=mid-1; i>=0; i--){
            auto curr_worker = --usable_workers.end();
            if(*curr_worker < tasks[i]){
                if(pills<=0)    return false;
                
                auto weakest_worker = usable_workers.lower_bound(tasks[i]-strength);
                if(weakest_worker==usable_workers.end()){
                    return false;
                }
                pills--;
                usable_workers.erase(weakest_worker);
            }else{
                usable_workers.erase(curr_worker);
            }
        }
        return true;
        
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0, high = min(tasks.size(), workers.size());
        int assigned=0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(can_assign(mid, tasks, workers, pills, strength)){
                assigned = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return assigned;
    }
};
