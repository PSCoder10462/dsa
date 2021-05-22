#define M 1000000007

long long getSum(int n, std::vector<long long> &pre, long long lim) {
    return (pre[lim%n]+(((lim/n)%M)*pre[n])%M)%M;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    std::vector<int> ans;
    
    // pre-fix array
   	std::vector<long long> pre(n+1, 0);
    for(int i=1; i<=n; ++i) pre[i] = ((pre[i-1]%M)+(arr[i-1]%M))%M;
    
    for (int z=0; z<q; z++) {
        long long L, R;
        L = queries[z][0]; R = queries[z][1];
        long long ans1 = getSum(n, pre, L-1)%M, ans2 = getSum(n, pre, R);
        ans.push_back((ans2-ans1+M)%M);
    }
	return ans;
}
