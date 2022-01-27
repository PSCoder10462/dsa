#include <iostream>
#define ll long long 
using namespace std;

int main() {
	// your code goes here
	int tt; cin >> tt;
	while (tt--) {
	    ll n, k, x; cin >> n >> k >> x;
	    if (x > k) 
	        cout << -1;
	    else {
	        for (ll i=0; i<n; ++i)
	            cout << i%x << ' ';
	    }
	    cout << '\n';
	}
	return 0;
}
