class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> partial;
        helper(candidates, result, partial, 0, target);
        return result;
    }
    
    void helper(vector<int>& n, vector<vector<int>>& res, vector<int> partial, int start, int target) {
        if (target < 0) return;
        else if (target == 0) {
            res.push_back(partial);
            return;
        }
        for (auto i = start; i < n.size(); ++i) {
            target -= n[i];
            partial.push_back(n[i]);
            helper(n,res,partial,i,target);
            partial.pop_back();
            target += n[i];
        }
    }
};
