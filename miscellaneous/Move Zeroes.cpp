class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j; i = j = 0;
        int n = nums.size();
        for (i; i<n; ++i) {
            if (nums[i] == 0) {
                if (i > j) j = i;
                while (j < n and !nums[j]) ++j;
                if (j < n)
                    swap(nums[i], nums[j]);
            }
        }
    }
};
