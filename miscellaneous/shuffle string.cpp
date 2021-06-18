class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int i=0;
        for (char c: s) {
            ans[indices[i++]] = c;
        }
        return ans;
    }
};
