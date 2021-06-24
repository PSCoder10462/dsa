class Solution {
public:
    string sortSentence(string s) {
        string temp = "";
        map<int, string> helper;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                helper[s[i] - 48] = temp;
                temp = "";
                count++;
                i++;
            }
            if (s[i] != 32)
                temp += s[i];
        }
        temp = "";
        for (int i = 1; i <= count; i++) {
            temp += helper[i];
            if (i != count)
                temp += ' ';
        }
        return temp;
    }
};
