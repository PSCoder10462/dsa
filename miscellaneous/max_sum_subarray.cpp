class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int t, ans;
        
        ans = int(-1e6);
        
        t = 0;
        
        for (int x: nums) {
            
            t += x;
            
            ans = std::max(ans, t);
            
            t = std::max(t, 0);
            
        }
        
        return ans;
        
    }
};
