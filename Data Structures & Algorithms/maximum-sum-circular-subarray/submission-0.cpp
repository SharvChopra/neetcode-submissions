class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int current_Sum = nums[0];
        int max_Sum = nums[0];
        int total_Sum = nums[0];
        for(int i=1;i<nums.size();i++){
            current_Sum = max(nums[i],current_Sum+nums[i]);

            max_Sum = max(max_Sum,current_Sum);
            total_Sum+=nums[i];
        }
        int current_Sum1 = nums[0];
        int min_Sum = nums[0];
        for(int i=1;i<nums.size();i++){
            current_Sum1 = min(nums[i],current_Sum1+nums[i]);

            min_Sum = min(min_Sum,current_Sum1);
        }
        if(max_Sum<0){
            return max_Sum;
        }
        return max(max_Sum,total_Sum - min_Sum);
    }
};