class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        vector<int>ans;
        while(left<right){
            int sum = abs(nums[left]) + abs(nums[right]);
            if(sum == abs(target)){
                ans.push_back(left);
                ans.push_back(right);
                left++;
                right--;
            }
            else if(sum<abs(target)){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};
