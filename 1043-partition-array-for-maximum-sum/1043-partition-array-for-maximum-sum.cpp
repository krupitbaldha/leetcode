class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);

        for(int idx = n-1;idx>=0;idx--){
            int len =0;
    int maxi= INT_MIN;
    int maxsum = INT_MIN;
int end = min(n, idx + k);
for (int i = idx; i < end; i++){
    len++;
    maxi = max(maxi,arr[i]);
 int sum = maxi * len + dp[i+1];
    maxsum = max(maxsum,sum); 
   }
       dp[idx] = maxsum;   
        }
        return dp[0];
    }
};