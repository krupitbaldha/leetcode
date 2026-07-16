class Solution {
public:
    int f(int idx, int target, vector<int>& coins,
          vector<vector<int>>& dp) {

        if(idx == 0){
            if(target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }

        if(dp[idx][target] != -1)
            return dp[idx][target];

        int ntake = f(idx-1, target, coins, dp);

        int take = 1e9;
        if(coins[idx] <= target)
            take = 1 + f(idx, target - coins[idx], coins, dp);

        return dp[idx][target] = min(take, ntake);
    }

    int coinChange(vector<int>& coins, int target) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        int ans = f(n-1, target, coins, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};