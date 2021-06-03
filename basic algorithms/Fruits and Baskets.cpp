#include <vector>
#include <set>

int findMaxFruits(string &str, int n) {
	if (n <= 2) return n;
    
    vector<int> v(26, 0);
    set<char> st;
    
    int j = 0;
    v[str[j]-'A']++;
    st.insert(str[j]);
    
    int ans = 1;
    
    for (int i=1; i<n; ++i) {
        v[str[i]-'A']++;
    	st.insert(str[i]);
        
        while (st.size()>2) {
            v[str[j]-'A']--;
            if (v[str[j]-'A'] == 0) 
                st.erase(str[j]);
            j++;
        }
    
        ans = std::max(ans, i-j+1);
    }
    
    return ans;
    
}
