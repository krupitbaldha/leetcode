class Solution {
public:
    int f(int s, int e, string &k,vector<vector<int>>&dp) {
        if (s > e) return 0;
        if (s == e) return 1;
if(dp[s][e]!=-1) return dp[s][e];
        if (k[s] == k[e])
            return dp[s][e] = 2 + f(s + 1, e - 1, k,dp);

        return dp[s][e] = max(f(s + 1, e, k,dp), f(s, e - 1, k,dp));
    }
    int minInsertions(string s) {
         vector<vector<int>>dp(s.length(),vector<int>(s.length()+1,-1));
        return s.length() - f(0, s.length() - 1, s,dp);
    }
};