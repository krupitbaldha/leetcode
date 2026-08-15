class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int zeros = 0;

        for (int x : nums) {
            xr ^= x;
            if (x == 0) zeros++;
        }

        int n = nums.size();

        if (xr != 0)
            return n;

        if (zeros == n)
            return 0;

        return n - 1;
    }
};