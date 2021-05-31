class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for (int i=1; i<=nums.size(); ++i) {
            int x = mp[nums[i-1]];
            if (x && i-x <= k) return true;
            mp[nums[i-1]] = i;
        }
        return false;
    }
};
