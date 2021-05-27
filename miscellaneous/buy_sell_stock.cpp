class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        std::vector<int> v(n+1);
        for (int i=n-1; i>=0; --i) 
            v[i] = std::max(v[i+1], prices[i]);
        for (int i=0; i<n; ++i) {
            ans = std::max(ans, v[i+1]-prices[i]);
        }
        return ans;
    }
};
