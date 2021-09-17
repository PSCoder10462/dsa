#include <vector>
#include <unordered_set>
int minCharDeletion(string str) {
    // Write your code here.
	vector<int> freq(256);
    for (char c: str) {
		freq[c]++;        
    }
    unordered_set <int> s;
    int ans = 0;
    for (int i: freq) {
        while (i > 0 and s.find(i) != s.end()) {
            ans++; i--;
        }
        s.insert(i);
    }
    return ans;
}

