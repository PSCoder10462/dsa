#include <vector>

#define vi                vector<int>
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)

int maxSumTwoSubarray(int arr[], int n, int k) {
    vi dp(n, 0);
    int cur_sum = 0;
    int ans = (int)(-1e8);
    loop(i, 0, n-1) {
        if (i < k) {
            cur_sum += arr[i]; 
            if (i == k-1) dp[i] = cur_sum; 
        } else {
            cur_sum += arr[i];
            cur_sum -= arr[i-k];
            dp[i] = max(dp[i-1], cur_sum);
        }
        if (i >= 2*k-1) {
            ans = max(ans, cur_sum + dp[i-k]);
        }
    }
    return (ans == (int)(-1e8)) ? 0 : ans;
}
