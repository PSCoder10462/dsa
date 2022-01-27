#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll find_number(ll req_xor, ll cur_xor) {
    ll value = 0;
    for (int i=0; i<17; ++i) {
        ll t = (1ll << i);
        if (req_xor & t) {
            if (!(cur_xor & t)) 
                value += t;
        } else {
            if (cur_xor & t)
                value += t;
        }
    }
    return value;
}

int main() {
	// your code goes here
	int tt; cin >> tt;
	while (tt--) {
	    ll n; scanf("%lld", &n);
	    ll cur_xor = 0;
	    for (ll i=1; i<=n; ++i) {
	        ll t = find_number(i, cur_xor);
	        printf("%lld ", t);
	        cur_xor ^= t;
	    }
	    printf("\n");
	}
	return 0;
}
