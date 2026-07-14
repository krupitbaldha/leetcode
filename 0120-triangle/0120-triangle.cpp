class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[n-1][j] = tri[n-1][j];
        }

        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = tri[i][j] + dp[i+1][j];
                int diag = tri[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }

        return dp[0][0];
    }
};
