#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vl vector<long long>
#define vi vector<int>
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
        int n, k;
        cin >> n >> k;
        map<int, int> m[k];
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            m[i % k][num]++;
        }
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            int total = 0, maxx = -1;
            for (auto x : m[i])
            {
                total+=x.second;
                maxx = max(maxx, x.second);
            }

            ans += (total - maxx);
        }

        cout << ans << endl;
    }
    return 0;
}
