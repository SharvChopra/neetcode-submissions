class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_Sum = nums[0];
        int current_Sum = nums[0];

        for(int i=1;i<nums.size();i++){
            current_Sum = max(nums[i],current_Sum+nums[i]);

            max_Sum = max(max_Sum,current_Sum);
        }
        return max_Sum;
    }
};
