#include <bits/stdc++.h>

vector<string> mp = {
    "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv",  "wxyz",
};

vector<string> ans;

void func(string s, string osf, int i, int n) {
  if (i == n) ans.push_back(osf);

  char p = s[i];

  string temp = mp[p-'2'];
  for (char c : temp) {
    osf.push_back(c);
    func(s, osf, i + 1, n);
    osf.pop_back();
  }
}

vector<string> combinations(string s){
	ans.clear();
    func(s, "", 0, s.length());
    return ans;
}
