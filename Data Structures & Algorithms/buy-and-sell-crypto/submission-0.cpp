class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int max_profit = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > 0) {
                    max_profit = max(max_profit, prices[j] - prices[i]);
                }
            }
        }
        return max_profit == INT_MIN ? 0 : max_profit;
    }
};
