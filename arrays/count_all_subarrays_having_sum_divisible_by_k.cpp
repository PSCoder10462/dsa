#include <unordered_map>

int subArrayCount(vector<int> arr, int k)
{
  // Write your code here
  std::unordered_map<int, int> count;
  int n = arr.size();
  std::vector<long long> pre(n + 1, 0);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
  {
    pre[i] = ((pre[i - 1] + arr[i - 1]) % k + k) % k;
    if (pre[i] == 0)
      ans++;
  }
  count[pre[1]]++;
  for (int i = 2; i <= n; ++i)
  {
    ans += count[pre[i]];
    count[pre[i]]++;
  }
  return ans;
}
