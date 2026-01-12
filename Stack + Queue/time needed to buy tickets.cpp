
// https://leetcode.com/problems/time-needed-to-buy-tickets/description/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int num = tickets[k];
        for(int i=0; i<tickets.size(); i++){
            if(i <= k) ans += min(tickets[i], num);
            else ans += min(tickets[i], num-1);
        }
        return ans;
    }
};
