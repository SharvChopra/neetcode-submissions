class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        vector<int>ans;
        while(left<right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                ans.push_back(left);
                ans.push_back(right);
                left++;
                right--;
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};
