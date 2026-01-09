
// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

class Solution {
public:
    int countLessEqual(int m, int n, int x) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(n, x / i);
        }
        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(m, n, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
