class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //using XOR
        int res = 0;
        for(int num:nums){
            res=res^num;
        }
        return res;
    }
};
