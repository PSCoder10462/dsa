string removeConsecutiveDuplicates(string str) 
{
    string ans;
    for (int i=0; i<str.length(); ++i) {
        char c = str[i];
        ans.push_back(c);
        while (i+1<str.length() && str[i+1] == c)
            i++;
    }
    return ans;
}
