class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for (int i=0; i<numbers.size()-1; i++) {
            int ts = target-numbers[i];
            if (ts == numbers[i] && ts == numbers[i+1]) {
                return vector<int> {i+1, i+2};
            }
            int pos = lower_bound(numbers.begin()+i+1, numbers.end(), ts)-numbers.begin();
            if (pos < numbers.size() && ts == numbers[pos]) {
                return vector<int> {i+1, pos+1};
            }
        }
        return ans;
    }
};
