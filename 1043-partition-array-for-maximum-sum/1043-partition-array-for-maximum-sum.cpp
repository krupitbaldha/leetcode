class Solution {
public:
int f(int idx,int k,vector<int>& arr,vector<int>&dp){
    int n = arr.size();
    if(idx == n) return 0;
    if(dp[idx]!=-1)return dp[idx];
    int len =0;
    int maxi= INT_MIN;
    int maxsum = INT_MIN;
   for(int i =idx;i<min(n,k+idx);i++){
    len++;
    maxi = max(maxi,arr[i]);
 int sum = maxi * len + f(i+1,k,arr,dp);
    maxsum = max(maxsum,sum); 
   }
   return dp[idx] = maxsum;
}
 
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return f(0,k,arr,dp);
    }
};