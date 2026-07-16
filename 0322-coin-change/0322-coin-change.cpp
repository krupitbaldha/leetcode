class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 1e9));

        // Base case: using only coins[0]
        for(int t = 0; t <= target; t++) {
            if(t % coins[0] == 0) dp[0][t] = t / coins[0];
        }

        // Fill DP table
        for(int idx = 1; idx < n; idx++) {
            for(int tar = 0; tar <= target; tar++) {
                int ntake = dp[idx-1][tar]; // not taking current coin
                int take = 1e9;
                if(coins[idx] <= tar) take = 1 + dp[idx][tar - coins[idx]];
                dp[idx][tar] = min(take, ntake);
            }
        }

        return (dp[n-1][target] >= 1e9) ? -1 : dp[n-1][target];
    }
};
