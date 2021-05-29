class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber) {
            int c = columnNumber%26;
            if (c==0) {
                c = 25;
                columnNumber--;
            }
            else c--;
            ans.push_back(c+ (int)'A');
            columnNumber/=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
