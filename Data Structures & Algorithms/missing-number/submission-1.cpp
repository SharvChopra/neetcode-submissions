class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Method - 1 -> using sum trick    
        // int sum = 0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        // }
        // int n = nums.size();
        // int actual_sum = (n*(n+1))/2;

        // return actual_sum-sum;

        //Method-2: - using XOR
        
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while(i<=n){
            ans = ans^i;
            i++;
        }

        for(int i = 0;i<n;i++){
            ans = ans^nums[i];
        }
        return ans;

    }
};
