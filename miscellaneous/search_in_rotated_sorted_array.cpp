class Solution {
public:
    int fp (vector<int>&nums) {
        
        int n = nums.size();
        int hi = n-1, lo = 0;
        
        if (n == 1) return -1;
        
        if (nums[hi] > nums[lo]) return -1;
        
        while (hi >= lo) {
            int mid = ((long long)lo+hi)/2;
            
            if (mid < n-1 and nums[mid] > nums[mid+1]) return mid+1;
            
            if (mid > 0 and nums[mid] < nums[mid-1]) return mid;
            
            if (nums[mid] > nums[lo]) lo = mid+1;
            
            else if (nums[mid] < nums[hi]) hi = mid-1;
        }
        
        return -1;
    }
    
    int bs(vector<int>& nums, int lo, int hi, int target) {
      while (lo <= hi) {
        int mid = ((long long)lo + hi) / 2;

        if (nums[mid] == target) return mid;

        if (nums[mid] > target)
          hi = mid - 1;

        else
          lo = mid + 1;
      }
      return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = fp(nums);
        cout << pivot << endl;
        if (pivot == -1) return bs(nums, 0, nums.size()-1, target);
        
        if (target == nums[pivot]) return pivot;
        
        if (target > nums[pivot] and target <= nums[nums.size()-1]) 
            return bs(nums, pivot+1, nums.size()-1, target);
        
        else return bs(nums, 0, pivot-1, target);
        
    }
};
