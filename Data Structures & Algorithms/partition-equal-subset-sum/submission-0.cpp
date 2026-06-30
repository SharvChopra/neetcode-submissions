class Solution {
public:
    bool solve(int idx, int target, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (idx == nums.size() || target < 0)
            return false;
        if (target == 0) {
            return true;
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target] == 1;
        }

        bool include = solve(idx + 1, target - nums[idx], nums, dp);
        bool exclude = solve(idx + 1, target, nums, dp);

        bool result = include || exclude;

        return dp[idx][target] = result ? 1 : 0;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target_sum = accumulate(nums.begin(), nums.end(), 0);

        if(target_sum%2!=0){
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(target_sum + 1, -1));

        return solve(0, target_sum/2, nums, dp);
    }
};
