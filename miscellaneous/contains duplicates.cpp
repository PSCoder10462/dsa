class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i: nums) {
            if (mp[i] == 1) return true;
            mp[i]++;
        }
        return false;
    }
};
