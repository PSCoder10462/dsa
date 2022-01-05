#include <bits/stdc++.h>
using namespace std;

int Get(vector<int> &arr, int node) {
	if (arr[node] == node) return node;
	return Get(arr, arr[node]);
}

void Union(vector<int> &arr, vector<int> &size, int u, int v) {
	int ru = Get(arr, u), rv = Get(arr, v);
	if (size[ru] <= size[rv]) {
		arr[ru] = rv;
		size[rv] += size[ru];
	} else {
		arr[rv] = ru;
		size[ru] += size[rv];
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> arr(n);
	for (int i=0; i<n; ++i) arr[i] = i;
	vector<int> size(n, 1);
	for (int i=0; i<m; ++i) {
		int u, v; cin >> u >> v; u--; v--;
		Union(arr, size, u, v);
		vector<int> ans;
		unordered_set<int> vis;
		for (auto j: arr) {
			int i = Get(arr, j);
			if (vis.find(i) != vis.end()) continue;
			vis.insert(i);
			ans.push_back(size[i]);
		}
		sort(ans.begin(), ans.end());
		for (auto i: ans) cout << i << ' ';
		cout << '\n';
	}	
	return 0;
}
