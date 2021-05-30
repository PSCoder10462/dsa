#include <unordered_set>
#include <unordered_map>
#include <algorithm>

string shortestSubstring(string s)
{
    int st, en, len = (int)1e4;
    unordered_set<char> ps;
    unordered_map<char, int> cm;

    for (char c : s)
        ps.insert(c);
    int dcp = ps.size();

    int start = 0, end = 1;
    int dcc = 1;

    cm[s[start]]++;

    if (dcp < 2)
    {
        string temp;
        temp.push_back(s[0]);
        return temp;
    }

    for (end; end < s.length(); ++end)
    {

        if (!cm[s[end]])
            dcc++;
        cm[s[end]]++;

        while (dcc == dcp)
        {
            if (len > end - start + 1)
            {
                len = end - start + 1;
                st = start;
                en = end;
            }

            cm[s[start]]--;

            if (!cm[s[start]])
            {
                dcc--;
            }

            start++;
        }
    }

    string ans;
    for (int i = st; i <= en; ++i)
        ans.push_back(s[i]);
    return ans;
}
