class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i=1; i<=numRows; ++i) {
            vector<int> temp;
            if (i == 1) temp = {1};
            else if (i == 2) temp = {1, 1};
            else {
                temp.resize(i, 1);
                for (int j=1; j<i-1; ++j) {
                    temp[j] = ans[i-2][j-1] + ans[i-2][j];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
