class Solution {
public:
    int solve(int ind, int target, vector<int>& nums,
              vector<vector<int>>& dp) {

        if (ind == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = solve(ind - 1, target, nums, dp);

        int take = 0;
        if (nums[ind] <= target)
            take = solve(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;
        for (int x : nums)
            total += x;

        if ((total + target) % 2 != 0)
            return 0;

        if (abs(target) > total)
            return 0;

        int sum = (total + target) / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(sum + 1, -1));

        return solve(nums.size() - 1, sum, nums, dp);
    }
};