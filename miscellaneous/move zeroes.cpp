class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector <int> v;
        
        for (int i=0; i<nums.size(); ++i)
            if (!nums[i]) v.push_back(i);
        
        int z = 0;
        
        for (int x: v) {
            nums.erase(nums.begin() + x - z);
            z++;
        }
        
        for (int i = 0; i<v.size(); ++i) nums.push_back(0);
    }
};
