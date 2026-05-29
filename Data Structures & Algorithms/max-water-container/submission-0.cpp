class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = INT_MIN;
        int left = 0;
        int right = heights.size()-1;
        while(left<=right){
            int width = right-left;
            int height = min(heights[left],heights[right]);
            int curr_area = width*height;

            max_area = max(max_area,curr_area);
            if(heights[left]<=heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};
