class Solution {
public:
    int maxCoins(vector<int>& nums) {
       

        nums.insert(nums.begin(), 1);
        nums.push_back(1);
 int n = nums.size()-2;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i =n;i>=1;i--){
            for(int j = 1;j<=n;j++){
                if(i>j)continue;
            int maxi = INT_MIN;

        for (int idx = i; idx <= j; idx++) {
            int cost = nums[i - 1] * nums[idx] * nums[j + 1]
                     + dp[i][idx-1]
                     + dp[idx+1][j];

            maxi = max(maxi, cost);
        }
    dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};