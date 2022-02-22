void solve1() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> f(26);
    while (k--) {
        char c; cin >> c;
        f[c-'a']++;
    }
    ll ans = 0;
    ll len = 0;
    for (auto c: s) {
        ++len;
        if (f[c-'a'] == 0) {
            ans += len*(len-1)/2;
            len = 0;
        }
    }
    ans += len*(len+1)/2;    
    cout << ans;
}

void solve2() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> f(26);
    while (k--) {
        char c; cin >> c;
        f[c-'a']++;
    }
    vi dp(n+1);
    loop(i, 1, n+1) {
        if (f[s[i-1]-'a']) {
            dp[i] = dp[i-1]+1;
        }
    }
    cout << accumulate(all(dp), 0ll);
}
