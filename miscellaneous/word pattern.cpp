class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        set <string> st;
        
        map<char, string> mp;
        
        int j = 0;
        
        for (int i=0; i<s.length(); ++i) {
            
            if (j == pattern.length()) return false; 
            
            string temp;
            
            while (i < s.length() && s[i] != ' ') temp.push_back(s[i++]);
            
            if (mp[pattern[j]] == "" && st.find(temp) != st.end()) return false;
            
            if (mp[pattern[j]] == "") {
                mp[pattern[j]] = temp;
                st.insert(temp);
            }
            else {
                if(mp[pattern[j]] != temp) return false;
            }
            
            j++;
        }
        
        if (j != pattern.length()) return false;
        
        return true;
        
    }
};
