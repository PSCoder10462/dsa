class Solution {
public:
    int maxDepth(string s) {
        int cnt, ans;
        cnt = ans = 0;
        for (char i: s) {
            if (i == '(') {
                cnt ++;
                ans = max(ans, cnt);
            } else if (i == ')') {
                cnt --;
            }
        }
        return ans;
    }
};
