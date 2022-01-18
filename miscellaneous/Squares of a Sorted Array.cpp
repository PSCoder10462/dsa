class Solution {
public:
    int func(vector<int> &nums, int n) {
        int lo = -1, hi = n;
        while (lo != hi -1) {
            int mid = (lo+hi)/2;
            if (nums[mid] <= 0) lo = mid;
            else hi = mid;
        }
        return lo;
    }
    
    vector<int> sortedSquares(vector<int>& nums) {
        int a = 0, b; 
        int n = nums.size();
        // while (a < n and nums[a] < 0) ++a;
        a = func(nums, n);
        b = a+1;
        vector<int> ans;
        while (a >= 0 and b<n) {
            int i = nums[a], j = nums[b];
            if (i*i >= j*j) {
                ans.push_back(j*j); ++b;
            } else {
                ans.push_back(i*i); --a;
            }
        }
        while (a >= 0) {
            int i = nums[a];
            ans.push_back(i*i); --a;
        }
        while (b < n) {
            int j = nums[b];
            ans.push_back(j*j); ++b;
        }
        return ans;
    }
};
