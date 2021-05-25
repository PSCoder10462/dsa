class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        
        if (nums[hi] == target) return hi; 
        
        if (nums[hi] < target) return hi+1;
        
        while (lo <= hi) {
            
            int m = (lo+hi)/2;
            
            if (nums[m] == target) return m;
            
            if (m > 0)
                if (nums[m] > target && nums[m-1] < target) 
                    return m;
        
            if (m==0 && nums[m] > target) return 0;
            
            if (nums[m] > target) hi = m - 1;
            
            else lo = m + 1;
            
        }
        
        return -1;
        
    }
};
