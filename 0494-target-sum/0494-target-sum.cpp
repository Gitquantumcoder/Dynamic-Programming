class Solution {
public:
    int dp(int i, int sum, vector<int>& nums, int total, int target,
           vector<vector<int>>& DP) {
        if (i == nums.size())
            return sum == target ? 1 : 0;

        if (DP[i][sum + total] != -1)
            return DP[i][sum + total];

        int add = dp(i + 1, sum + nums[i], nums, total, target, DP);
        int sub = dp(i + 1, sum - nums[i], nums, total, target, DP);

        return DP[i][sum + total] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        vector<vector<int>> DP(
            nums.size(), vector<int>(2 * total + 1, -1)
        );

        return dp(0, 0, nums, total, target, DP);
    }
};