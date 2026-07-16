class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<int>prev(target+1,0),curr(target+1,0);

        // Base case: using only coins[0]
        for(int t = 0; t <= target; t++) {
            if(t % coins[0] == 0) prev[t] = t / coins[0];
            else prev[t] = 1e9;
        }

        // Fill DP table
        for(int idx = 1; idx < n; idx++) {
            for(int tar = 0; tar <= target; tar++) {
                int ntake =prev[tar]; // not taking current coin
                int take = 1e9;
                if(coins[idx] <= tar) take = 1 + curr[tar - coins[idx]];
                curr[tar] = min(take, ntake);
            }
           prev= curr; 
        }

        return (prev[target] >= 1e9) ? -1 : prev[target];
    }
};
