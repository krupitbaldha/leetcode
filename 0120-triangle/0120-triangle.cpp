class Solution {
public:
    const int INF = 1e9;

    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == triangle.size() - 1)
            return triangle[i][j];

        if (dp[i][j] != INF)
            return dp[i][j];

        int down = triangle[i][j] + f(i + 1, j, triangle, dp);
        int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));

        return f(0, 0, triangle, dp);
    }
};