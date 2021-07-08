#include <algorithm>
#define mid(l, h) ((lo+hi)/2)

bool isPos(vector<int> v, int n, int c, int m) {
    
    int p = 1, pos = v[0];
    
    for (int i=1; i<n; i++) {
        if (v[i]-pos >= m) {
            pos = v[i];
            p++;
        } 
        if (p == c) return true;
    }
    
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    std::sort(positions.begin(), positions.end());
    
    int lo = 0, hi = positions[n-1];
    int ans = 0;
	while (lo <= hi) {
        int m = mid(lo, hi);
        
        if (isPos(positions, n, c, m)) {
            ans = m;
            lo = m+1;
        } else 
        	hi = m-1;
    }

    return ans;
    
}
