class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
        if (n == 1) return false;
        
        for (int len = 1; len <= n/2; ++len) {
            
            if (n%len) continue;
        
            bool flag = true;
            
            int segs = n/len;
            
            for (int i=0; i<len; ++i) {
                for (int j=1; j<segs; ++j)
                    if (s[i] != s[j*len+i]) {
                        flag = false;
                        break;
                    }
                if (!flag) break;
            }
        
       
            if (flag) return true;    
        }
        
        return false;
    }
};
