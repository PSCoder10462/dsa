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
        int x, y;
        cin >> x >> y;
        if (y % x)
        {
            cout << -1 << '\n';
            continue;
        }
        y /= x;
        bool found = false;
        int ans = 1e9;
        for (int i = 1; i < 62; ++i)
        {
            int tt = y + i, cnt = 0, ta = 0;
            for (int j = 0; j < 62; ++j)
            {
                if ((1ll << j) & tt)
                {
                    cnt++;
                    ta += j;
                }
            }
            if (cnt == i)
            {
                ans = min(ans, ta + cnt - 1);
                found = true;
            }
        }
        if (!found)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}
