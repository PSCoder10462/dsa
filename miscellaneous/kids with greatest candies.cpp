class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxx = -1;
        for (int i: candies) maxx = max(i, maxx);
        for (int i: candies) {
            maxx-i <= extraCandies ? ans.push_back(true) : ans.push_back(false);
        }
        return ans;
    }
};
