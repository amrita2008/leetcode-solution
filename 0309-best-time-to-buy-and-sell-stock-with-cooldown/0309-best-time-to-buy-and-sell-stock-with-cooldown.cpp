#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(
            n + 2, vector<int>(2, 0)
        );
        for (int index = n - 1; index >= 0; index--) {
            int buy = -prices[index] + dp[index + 1][0];
            int skip = dp[index + 1][1];
            dp[index][1] = max(buy, skip);
            int sell = prices[index] + dp[index + 2][1];
            int hold = dp[index + 1][0];
            dp[index][0] = max(sell, hold);
        }
        return dp[0][1];
    }
};
