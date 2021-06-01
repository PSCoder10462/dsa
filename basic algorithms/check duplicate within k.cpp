#include <unordered_map>

bool checkDuplicate(vector<int> &arr, int n, int k) {
    // Write your code here.
	unordered_map <int, int> m;
    
    for (int i=0; i<k+1 && i<n; ++i) {
        m[arr[i]]++;
        if (m[arr[i]] > 1) return true;
    }
    
    for (int i=k+1; i<n; ++i) {
        m[arr[i-k-1]]--;
        m[arr[i]]++;
        if (m[arr[i]] > 1) return true;
    }
    
    return false;
}
