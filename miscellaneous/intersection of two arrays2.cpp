class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i: nums1) mp[i]++;
        vector<int> ans;
        for (int i: nums2) {
            if (mp[i]) {ans.push_back(i); mp[i]--;}
        }
        return ans;
    }
};
