class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() < 1) return 0;
        
        int it=0;
        
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != val) {   
                nums[it++] = nums[i];
            }
        }
        
        return it;
    }
};
