class Solution {
public:
int f(int i,int j,string&s1, string&s2,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j]= 1+f(i-1,j-1,s1,s2,dp);
    return dp[i][j]=max(f(i-1,j,s1,s2,dp) , f(i,j-1,s1,s2,dp));
 
    }
    int longestCommonSubsequence(string s1, string s2) {
        int i = s1.length();
        int  j = s2.length();
        vector<vector<int>>dp(i,vector<int>(j+1,-1));
        return f(i-1,j-1,s1,s2,dp);
    }
};