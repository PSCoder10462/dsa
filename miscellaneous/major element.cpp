class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 1;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[ans] == nums[i]) cnt++;
            else cnt--;
            if (!cnt){ 
                ans = i;
                cnt=1;
            }
        }
        return nums[ans];
    }
};
