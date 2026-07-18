#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) {
            for(int jj = 0; jj <= j; jj++) {
                if(p[jj] != '*') return false;
            }
            return true;
        }
        if(i >= 0 && j < 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = f(i-1, j-1, s, p, dp);

        if(p[j] == '*')
            return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, p, dp);
    }
};
