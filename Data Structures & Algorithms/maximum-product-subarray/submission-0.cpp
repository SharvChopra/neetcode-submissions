class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size();

        int curr_max = nums[0];
        int curr_min = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(curr_max, curr_min);
            }

            curr_max = max(nums[i], nums[i] * curr_max);
            curr_min = min(nums[i], nums[i] * curr_min);

            ans = max(ans, curr_max);
        }
        return ans;
    }
};
