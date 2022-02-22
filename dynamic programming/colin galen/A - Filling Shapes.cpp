void solve1() {
    int n; cin >> n;
    if (n&1) {
        cout << 0; return;
    }
    cout << (1ll<<(n>>1ll));
}

void solve2 () {
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[2] = 2;
    loop(i, 4, n+1)
        dp[i] = dp[i-2]*2;
    cout << dp[n];
}
