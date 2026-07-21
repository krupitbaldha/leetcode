class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n =arr.size();
        sort(arr.begin(), arr.end());
        int maxi =0;
        vector<int>dp(n,1),hash(n,0);
        int lastindex= 0;
        for(int i =0;i<n;i++){
            hash[i] = i;
            for(int j =0;j<i;j++){
                if(arr[i]%arr[j]==0 && dp[j]+1>dp[i]){
                    dp[i] = 1+dp[j];
hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }
vector<int>temp;
temp.push_back(arr[lastindex]);
while(hash[lastindex]!=lastindex){
    lastindex = hash[lastindex];
    temp.push_back(arr[lastindex]);
}
reverse(temp.begin(),temp.end());
return temp;
    }
};