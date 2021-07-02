#include <iostream>
#define int long long
using namespace std;

signed main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
	    int x;
	    cin >> x;
	    if (x % 5 != 0) { 
	        cout << "-1\n";
            continue;	   
	    }
	    for (int ctr = 0; ; ctr++, x*=2)
	    if (x % 10 == 0) {
	        cout << ctr << '\n';
	        break;
	    }
	}
	return 0;
}
