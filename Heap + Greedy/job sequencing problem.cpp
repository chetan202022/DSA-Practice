
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution {
  public:
    vector<int> parent;

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        vector<pair<int,int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // sort by profit descending
        sort(jobs.begin(), jobs.end(), greater<>());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());

        parent.resize(maxDeadline + 1);
        for(int i = 0; i <= maxDeadline; i++) parent[i] = i;

        int count = 0, prof = 0;

        for(auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int slot = find(d);
            if(slot > 0) {
                count++;
                prof += p;
                parent[slot] = find(slot - 1); // union
            }
        }

        return {count, prof};
    }
};
