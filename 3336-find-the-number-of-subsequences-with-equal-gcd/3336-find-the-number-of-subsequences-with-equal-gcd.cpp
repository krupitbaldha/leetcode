class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp[201][201][201];

    int solve(int i, int g1, int g2, vector<int>& nums) {
        if (i == nums.size()) {
            return (g1 == g2 && g1 != 0);
        }

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;

        // Skip
        ans += solve(i + 1, g1, g2, nums);

        // Put in first subsequence
        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        ans += solve(i + 1, ng1, g2, nums);

        // Put in second subsequence
        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
        ans += solve(i + 1, g1, ng2, nums);

        return dp[i][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};