class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ans = strs[0];
        int alen = ans.length();
        
        for (std::string s: strs) {
            if (ans == s) continue;
            
            int slen = s.length();
            
            int len = std::min(slen, alen);
            
            std::string temp;
            
            for (int i=0; i<len; ++i) {
                if (ans[i]==s[i]) temp.push_back(ans[i]);
                else break;
            }
            
            
            ans = temp;
            
            if (ans == "") return ans;
        }
        
        return ans;
        
    }
};
