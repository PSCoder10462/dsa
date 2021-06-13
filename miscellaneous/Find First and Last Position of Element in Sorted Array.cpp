class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lo1, lo2, hi1, hi2;
        
        lo1 = lo2 = 0;
        hi1 = hi2 = nums.size()-1;
        
        bool s, e; s = e = false;
        
        if (nums.size() == 0) {
            s = e = true;
        }
        
        int start=-1, end=-1;
        
        while (!s or !e) {
            
            if (not s) {
                
                int m1 = ((long long)lo1+hi1)/2;

                cout << lo1 << m1 << hi1 << endl;
                
                if (nums[m1] == target and (m1 == 0 or nums[m1-1] != target)) {
                    s = true;
                    start = m1;
                } 
                
                else if (nums[m1] < target) lo1 = m1+1; 
                
                else hi1 = m1-1;
                
            }
            
            if (not e) {
                
                int m2 = ((long long)lo2+hi2)/2;

                if (nums[m2] == target and (m2 == nums.size()-1 or nums[m2+1] != target)) {
                    e = true;
                    end = m2;
                } 
                
                else if (nums[m2] > target) hi2 = m2-1; 
                
                else lo2 = m2+1;
                
            }
            
            if (lo1 > hi1) s = true;
            if (lo2 > hi2) e = true;
            
        }
        
        return vector<int> {start, end};
        
    }
};
