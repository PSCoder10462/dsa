class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<1) return 0;
        int t=nums[0];
        int it = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] != t) {
                nums[it++] = nums[i];
                t = nums[i];
            }
        }
        return it;
    }
};
