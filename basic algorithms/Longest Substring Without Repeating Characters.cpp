#include <vector>

int lengthOfLongestSubstring(string &s) {
    // Write your code here.
    int n = s.length();
    if (n<=1) return n;
    
    vector<int> v(256, 0);
    
    int start = 0;
    v[s[start]]++;
    
    int len = 1;
    
    for (int end=1; end<n; ++end) {
        
        v[s[end]]++;
        
        while (v[s[end]] == 2) {
            v[s[start]]--;
            start++;
        }
        
        len = std::max(len, end-start+1);
        
    }
    
    return len;
    
}
