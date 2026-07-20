class Solution {
public:
int f(int idx,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
    if(idx==n || cap==0)return 0;
    if(dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];

    if(buy ==1){
    return dp[idx][buy][cap] = max(-prices[idx]+f(idx+1,0,cap,prices,n,dp),0+f(idx+1,1,cap,prices,n,dp));    
    }
    else{
        return dp[idx][buy][cap] = max(prices[idx]+f(idx+1,1,cap-1,prices,n,dp),0+f(idx+1,0,cap,prices,n,dp));
    }

}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i =n-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                    if(buy==1){
                       dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                    else {
                        dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};