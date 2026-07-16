class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>gc;
int maxi = INT_MIN;
        for(int i =0;i<n;i++){
        maxi = max(nums[i],maxi);
        gc.push_back(maxi);
        }
        vector<int>prefix;
        for(int i =0;i<n;i++){
            int a = nums[i],b=gc[i];
         while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
prefix.push_back(a);
    }
    sort(prefix.begin(),prefix.end());
    long long ans = 0;

for (int i = 0; i < n / 2; i++) {
    ans += gcd(prefix[i], prefix[n - 1 - i]);
}

return ans;

    }
};