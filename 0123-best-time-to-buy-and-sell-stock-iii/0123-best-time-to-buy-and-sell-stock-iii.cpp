class Solution {
public:
int f(int idx,int tran,int n,vector<vector<int>>&dp,vector<int>& prices){
    if(idx==n || tran==4)return 0;
    if(dp[idx][tran]!=-1)return dp[idx][tran];
    if(tran%2==0){
        return dp[idx][tran] = max(-prices[idx]+f(idx+1,tran+1,n,dp,prices),f(idx+1,tran,n,dp,prices));
    }
    else{
        return dp[idx][tran] = max(prices[idx]+f(idx+1,tran+1,n,dp,prices),f(idx+1,tran,n,dp,prices));
    }
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));
        
        return f(0,0,n,dp,prices);
    }
};