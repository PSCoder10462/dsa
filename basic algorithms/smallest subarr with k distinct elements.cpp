#include <unordered_map>

vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
	unordered_map<int, int> mp;
	int dist = 0;
	int start = 0, end = 0;
	int len = (int)1e9, s = -1, e = -1;

	for (end; end < arr.size(); end++)
	{

		if (!mp[arr[end]] || mp[arr[end]] == 0)
		{
			dist++;
		}

		mp[arr[end]]++;

		while (dist == k)
		{
			if (len > end - start + 1)
			{
				len = end - start + 1;
				s = start;
				e = end;
			}

			mp[arr[start]]--;
			if (mp[arr[start]] == 0)
				dist--;
			start++;
		}
	}

	return s == -1 ? vector<int>{-1} : vector<int>{s, e};
}
