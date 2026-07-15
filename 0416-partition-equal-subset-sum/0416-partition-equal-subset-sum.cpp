class Solution {
public:
    bool f(int n, int target, vector<int>& nums) {

        vector<bool> prev(target + 1, false), curr(target + 1, false);

        prev[0] = true;
        curr[0] = true;

        if (nums[0] <= target)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {

            curr[0] = true;

            for (int j = 1; j <= target; j++) {

                bool ntake = prev[j];

                bool take = false;

                if (nums[i] <= j)
                    take = prev[j - nums[i]];

                curr[j] = take || ntake;
            }

            prev = curr;
        }

        return prev[target];
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int tsum = 0;

        for (int x : nums)
            tsum += x;

        if (tsum % 2 != 0)
            return false;

        return f(n, tsum / 2, nums);
    }
};