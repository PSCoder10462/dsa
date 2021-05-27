class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, m=0;
        int n = prices.size();
        for (int i=n-1; i>0; --i) {
            m = std::max(prices[i], m);
            ans = std::max(ans, m-prices[i-1]);
        }
        return ans;
    }
};
