
// https://www.geeksforgeeks.org/dsa/cutting-a-rod-dp-13/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cutRodRecur(int i, vector<int>& price, vector<int>& dp) {
        
    // Base case
    if (i == 0) return 0;

    // If answer for this dp 
    // state is already calculated
    if (dp[i] != -1) return dp[i];

    int ans = 0;

    // Find maximum value for each cut.
    // Take value of rod of length j, and 
    // recursively find value of rod of 
    // length (i-j).
    for (int j = 1; j <= i; j++) {
        ans = max(ans, price[j] + cutRodRecur(i - j, price, dp));
    }

    return dp[i] = ans;
}

int cutRod(vector<int>& price) {
    int n = price.size() - 1;
    vector<int> dp(n + 1, -1);

    return cutRodRecur(n, price, dp);
}

int main() {
    vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}
