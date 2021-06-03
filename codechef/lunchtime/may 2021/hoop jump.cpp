#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<long long>
#define vi vector<int>
#define mid(l, h) ((l + h / 2))
#define endl '\n'

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << n / 2 + 1 << endl;
	}
	return 0;
}
