class Solution {
public:
int f(int idx,int target,vector<int>&coins,  vector<vector<int>>&dp){
    if(idx==0){
        return (target%coins[0]==0);
    }
    if(dp[idx][target]!=-1)return dp[idx][target];
    int ntake = f(idx-1,target,coins,dp);
    int take = 0;
    if(coins[idx]<=target) take = f(idx,target-coins[idx],coins,dp);

    return dp[idx][target] = take + ntake;
}
    int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    return f(n-1,amount,coins,dp);
    }
};