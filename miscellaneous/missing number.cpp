class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool zero = false;
        long long sum = 0;
        int n = nums.size();
        for (auto x: nums) {
            sum += x;
            if (!x) zero = true;
        }
        
        if (!zero) return 0;
        
        long long s2 = (n*(n+1))/2;
        
        return (s2 == sum) ? n : s2-sum;
    }
};
