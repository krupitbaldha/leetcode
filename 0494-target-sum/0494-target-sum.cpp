class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for (int x : nums) sum += x;

        // Impossible cases
        if (sum < abs(target)) return 0;
        if ((sum - target) % 2 != 0) return 0;

        int k = (sum - target) / 2;

        int n = nums.size();

        vector<int> prev(k + 1, 0), curr(k + 1, 0);

        // Base case
        if (nums[0] == 0)
            prev[0] = 2;      // pick or not pick
        else
            prev[0] = 1;

        if (nums[0] != 0 && nums[0] <= k)
            prev[nums[0]] = 1;

        for (int i = 1; i < n; i++) {

            curr[0] = (nums[i] == 0) ? prev[0] * 2 : prev[0];

            for (int j = 1; j <= k; j++) {

                int ntake = prev[j];

                int take = 0;
                if (nums[i] <= j)
                    take = prev[j - nums[i]];

                curr[j] = take + ntake;
            }

            prev = curr;
        }

        return prev[k];
    }
};