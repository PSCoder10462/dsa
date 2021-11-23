#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T; cin >> T;
	while (T--) {
	    long long n; cin >> n;
	    cout << (n%6 ? "Chef" : "Misha") << endl; 
	}
	return 0;
}
