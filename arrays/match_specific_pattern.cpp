#include <unordered_map>
#include <set>

vector<string> matchSpecificPattern(vector<string> words, int n, string pattern)
{
    std::vector<std::string> ans;
    for(std::string test: words) {
        std::unordered_map<int, int> m;
    	std::set<int> s;
        int t = test.length(), p = pattern.length();
        if (t != p) continue;
        bool pat = true;
        for(int j=0; j<t; ++j) {
            if (m[pattern[j]] == 0){ 
                if (s.find(test[j]) != s.end()) {
                    pat = false;
                    break;
                }
                m[pattern[j]] = test[j];
                s.insert(test[j]);
           	}
            else if (m[pattern[j]] != test[j]) {
                pat = false;
                break;
            } 
        }
        if (pat) ans.push_back(test);
    }
    return ans;
}
