class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        std::set <int> s;
        std::vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            int ts = target - nums[i];
            if (s.find(ts)!=s.end()) {
                ans.push_back(m[ts]);
                ans.push_back(i);
                break;
            }
            s.insert(nums[i]);
            m[nums[i]] = i;
        }
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};
