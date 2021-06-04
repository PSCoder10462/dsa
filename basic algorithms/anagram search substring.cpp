vector<int> findAnagramsIndices(string str, string ptn, int n, int m)
{
    vector<int> pt(26, 0);
    vector<int> st(26, 0);
    vector <int> ans;
    
    if (m > n) return ans;
    
    for (int i=0; i<m; ++i) pt[ptn[i]-'A']++;
    
    int j=0;
    for (j; j<m; ++j) st[str[j]-'A']++;
    
    int i = 0;
    if (st == pt) ans.push_back(i);
    
    for (j; j<n; ++j) {
        st[str[i]-'A']--; ++i;
        st[str[j]-'A']++;
        if (st == pt) ans.push_back(i);
    }
    
    return ans;
}
