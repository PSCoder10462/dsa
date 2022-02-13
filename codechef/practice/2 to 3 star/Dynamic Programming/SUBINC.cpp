#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	int T; cin >> T;
	while (T--) {
	    ll n; cin >> n;
	    ll ans = 0;
	    ll len = 1, prev;
	    cin >> prev;
	    while (--n) {
	        ll cur; cin >> cur;
	        if (cur >= prev)
	            len++;
            else {
                ans += (len*(len+1))/2;
                len = 1;
            }
            prev = cur;
	    }
	    ans += (len*(len+1))/2;;
	    cout << ans << '\n';
	}
 	return 0;
}
