class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = 90000;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n; ++i) {
            
            if (i < n and i > 0 and nums[i] == nums[i-1]) ++i;
            
            int j = i+1;
            int k = n-1;
            
            while (j < k) {
                int sum = nums[i]+nums[j]+nums[k];
                if (target == sum)
                    return target;
                else if (target > sum) { 
                    if (abs(diff) > abs(target - sum))
                        diff = target - sum;
                    j++;
                    while (j < k and nums[j-1] == nums[j]) j++; 
                } else{ 
                    if (abs(diff) > abs(target - sum))
                        diff = target - sum;
                    k--;
                }
            }
            
        }
        
        return target - diff;
        
    }
};
