class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int> values(nums.begin(), nums.end());

        unordered_set<int> dp1, dp2, dp3;

        for (int x : values) {

            vector<int> cur1(dp1.begin(), dp1.end());
            vector<int> cur2(dp2.begin(), dp2.end());

            dp1.insert(x);

            for (int v : cur1)
                dp2.insert(v ^ x);

            dp2.insert(x ^ x);

            for (int v : cur2)
                dp3.insert(v ^ x);

            for (int v : cur1)
                dp3.insert((v ^ x) ^ x);

            dp3.insert(x);
        }

        return dp3.size();
    }
};