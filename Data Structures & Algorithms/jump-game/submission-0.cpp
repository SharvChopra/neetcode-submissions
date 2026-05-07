class Solution {
public:
    bool canJump(vector<int>& nums) {
       int mx = 0;
       int last = 0;
       bool is_valid = true;
       int n = nums.size();
       for(int i=0;i<nums.size()-1;i++){
        mx = max(mx,i+nums[i]);
        if(i==last){
            last = mx;
        }
       }
       if(last<n-1){
        return false;
       } 
       return true;
    }
};
